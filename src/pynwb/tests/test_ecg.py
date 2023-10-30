
from pynwb.testing import TestCase, remove_test_file, NWBH5IOMixin

from pynwb import NWBHDF5IO, NWBFile
from datetime import datetime
from uuid import uuid4
import numpy as np
from dateutil.tz import tzlocal
from hdmf.common import DynamicTable

from ndx_ecg import (
    CardiacSeries,
    ECG,
    HeartRate,
    AuxiliaryAnalysis,
    ECGChannelsGroup,
    ECGRecDevice
)


def set_up_nwbfile(nwbfile: NWBFile = None):

    nwbfile = NWBFile(
        session_description='ECG test-rec session',
        identifier=str(uuid4()),
        session_start_time=datetime.now(tzlocal()),
        experimenter='experimenter',
        lab='DCL',
        institution='UKW',
        experiment_description='',
        session_id='',
    )
    # define an endpoint main recording device
    main_device = nwbfile.create_device(
        name='name_of_the_MRD',  # MRD: main recording device
        description='description_of_the_MRD',
        manufacturer='manufacturer_of_the_MRD'
    )

    '''
    creating an ECG electrodes table
    as a DynamicTable
    '''
    ecg_electrodes_table = DynamicTable(
        name='ecg_electrodes',
        description='info on ECG electrodes'
    )

    # add relevant columns
    ecg_electrodes_table.add_column(
        name='electrode_name',
        description='reference name of the corresponding electrode'
    )
    ecg_electrodes_table.add_column(
        name='electrode_location',
        description='the location of the corresponding electrode on the body'
    )
    ecg_electrodes_table.add_column(
        name='electrode_info',
        description='descriptive information on the corresponding electrode'
    )

    # add electrodes
    ecg_electrodes_table.add_row(
        electrode_name='el_0',
        electrode_location='right upper-chest',
        electrode_info='descriptive info'
    )
    ecg_electrodes_table.add_row(
        electrode_name='el_1',
        electrode_location='left lower-chest',
        electrode_info='descriptive info'
    )
    ecg_electrodes_table.add_row(
        electrode_name='reference',
        electrode_location='top of the head',
        electrode_info='descriptive info'
    )
    # adding the object of DynamicTable
    nwbfile.add_acquisition(ecg_electrodes_table)  # storage point for custom DT and NWB-C

    '''
    creating an ECG recording channels table
    as a DynamicTable
    '''
    recording_channels_table = DynamicTable(
        name='recording_channels',
        description='info on ecg recording channels'
    )

    # add relevant columns
    recording_channels_table.add_column(
        name='channel_name',
        description='reference name of the corresponding recording channel'
    )
    recording_channels_table.add_column(
        name='channel_type',
        description='type of the recording, e.g., single electrode or differential'
    )
    recording_channels_table.add_column(
        name='electrodes',
        description='descriptive information the corresponding electrode(s)',
    )

    # add channels
    recording_channels_table.add_row(
        channel_name='ch_0',
        channel_type='single',
        electrodes='el_0'
    )
    recording_channels_table.add_row(
        channel_name='ch_1',
        channel_type='differential',
        electrodes='el_0 and el_1'
    )
    # adding the object of DynamicTable
    nwbfile.add_acquisition(recording_channels_table)  # storage point for custom DT and NWB-C

    return nwbfile, ecg_electrodes_table, recording_channels_table


class TestCardiacSeriesRoundtrip(TestCase):

    def setUp(self):
        self.nwbfile = set_up_nwbfile()[0]
        self.electrodes_table = set_up_nwbfile()[1]
        self.channels_table = set_up_nwbfile()[2]
        self.path = "test.nwb"

    def tearDown(self):
        remove_test_file(self.path)

    def test_roundtrip(self):
        # define an ECGRecDevice-type device for ecg recording
        ecg_device = ECGRecDevice(
            name='name_of_the_ECGRD',
            description='description_of_the_ECGRD',
            manufacturer='manufacturer_of_the_ECGRD',
            filtering='notch-60Hz-analog',
            gain='100',
            offset='0',
            synchronization='taken care of via ...',
            endpoint_recording_device=self.nwbfile.get_device('name_of_the_MRD')
        )
        # adding the object of ECGRecDevice
        self.nwbfile.add_device(ecg_device)

        ecg_channels_group = ECGChannelsGroup(
            name='ecg_channels_group',
            group_description='a group to store electrodes and channels table, and linking to ECGRecDevice.',
            electrodes=self.nwbfile.get_acquisition('ecg_electrodes'),
            channels=self.nwbfile.get_acquisition('recording_channels'),
            recording_device=ecg_device
        )
        # adding the object of ECGChannelsGroup
        self.nwbfile.add_lab_meta_data(ecg_channels_group)  # storage point for custom DT and NWB-C
        #
        #
        # storing the ECG data
        dum_data_ecg = np.random.randn(20, 2)
        dum_time_ecg = np.linspace(0, 10, len(dum_data_ecg))
        ecg_cardiac_series = CardiacSeries(
            name='ecg_raw_CS',
            data=dum_data_ecg,
            timestamps=dum_time_ecg,
            unit='mV',
            channels_group=ecg_channels_group
        )

        ecg_raw = ECG(
            cardiac_series=ecg_cardiac_series,
            processing_description='raw acquisition'
        )
        # adding the raw acquisition of ECG to the nwb_file inside an 'ECG' container
        self.nwbfile.add_acquisition(ecg_raw)

        # storing the HeartRate data
        dum_data_hr = np.random.randn(10, 2)
        dum_time_hr = np.linspace(0, 10, len(dum_data_hr))
        hr_cardiac_series = CardiacSeries(
            name='heart_rate_CS',
            data=dum_data_hr,
            timestamps=dum_time_hr,
            unit='bpm',
            channels_group=ecg_channels_group
        )

        # defining an ecg_module to store the processed cardiac data and analysis
        ecg_module = self.nwbfile.create_processing_module(
            name='cardio_module',
            description='a module to store processed cardiac data'
        )

        hr = HeartRate(
            cardiac_series=hr_cardiac_series,
            processing_description='processed heartRate of the animal'
        )
        # adding the heart rate data to the nwb_file inside an 'HeartRate' container
        ecg_module.add(hr)

        # storing the Auxiliary data
        # An example could be the concept of ceiling that is being used in the literature published by DCL@UKW
        dum_data_ceil = np.random.randn(10, 2)
        dum_time_ceil = np.linspace(0, 10, len(dum_data_ceil))
        ceil_cardiac_series = CardiacSeries(
            name='heart_rate_ceil_CS',
            data=dum_data_ceil,
            timestamps=dum_time_ceil,
            unit='bpm',
            channels_group=ecg_channels_group
        )

        ceil = AuxiliaryAnalysis(
            cardiac_series=ceil_cardiac_series,
            processing_description='processed auxiliary analysis'
        )
        # adding the 'ceiling' auxiliary analysis to the nwb_file inside an 'AuxiliaryAnalysis' container
        ecg_module.add(ceil)

        # storing the processed heart rate: as an NWBDataInterface with the new assigned name instead of default
        # An example could be the concept of HR2ceiling that is being used in the literature published by DCL@UKW
        dum_data_hr2ceil = np.random.randn(10, 2)
        dum_time_hr2ceil = np.linspace(0, 10, len(dum_data_hr2ceil))
        hr2ceil_cardiac_series = CardiacSeries(
            name='heart_rate_to_ceil_CS',
            data=dum_data_hr2ceil,
            timestamps=dum_time_hr2ceil,
            unit='bpm',
            channels_group=ecg_channels_group
        )

        hr2ceil = HeartRate(
            name='HR2Ceil',
            cardiac_series=hr2ceil_cardiac_series,
            processing_description='processed heartRate to ceiling'
        )
        # adding the 'HR2ceiling' processed HR to the nwb_file inside an 'HeartRate' container
        ecg_module.add(hr2ceil)

        # writing the nwbfile on disk
        with NWBHDF5IO(self.path, mode='w') as io:
            io.write(self.nwbfile)

        # reading and asserting
        with NWBHDF5IO(self.path, mode="r", load_namespaces=True) as io:
            read_nwbfile = io.read()
            # assertion of ECG raw acquisition
            self.assertContainerEqual(ecg_raw, read_nwbfile.acquisition['ECG'])
            self.assertEqual('raw acquisition', read_nwbfile.acquisition['ECG'].processing_description)

            # CardiacSeries assertion
            self.assertContainerEqual(ecg_cardiac_series, read_nwbfile.acquisition['ECG']['ecg_raw_CS'])

            # assertion of the arguments of a typical CardiacSeries
            np.testing.assert_array_equal(dum_data_ecg, read_nwbfile.acquisition['ECG']['ecg_raw_CS'].data[:])
            np.testing.assert_array_equal(dum_time_ecg, read_nwbfile.acquisition['ECG']['ecg_raw_CS'].timestamps[:])
            self.assertEqual('mV', read_nwbfile.acquisition['ECG']['ecg_raw_CS'].unit)
            self.assertContainerEqual(ecg_channels_group, read_nwbfile.acquisition['ECG']['ecg_raw_CS'].channels_group)
            self.assertContainerEqual(ecg_channels_group, read_nwbfile.lab_meta_data['ecg_channels_group'])

            # assertion of default(first three)/given(last) names of interfaces
            self.assertEqual('ECG', read_nwbfile.acquisition['ECG'].name)
            self.assertEqual('HeartRate', read_nwbfile.processing['cardio_module']['HeartRate'].name)
            self.assertEqual('AuxiliaryAnalysis', read_nwbfile.processing['cardio_module']['AuxiliaryAnalysis'].name)
            self.assertEqual('HR2Ceil', read_nwbfile.processing['cardio_module']['HR2Ceil'].name)

            # assertion of ECGChannelsGroup elements (instances of DynamicTable)
            self.assertEqual(self.electrodes_table, read_nwbfile.lab_meta_data['ecg_channels_group'].electrodes)
            self.assertEqual(self.channels_table, read_nwbfile.lab_meta_data['ecg_channels_group'].channels)

