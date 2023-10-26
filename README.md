# ndx-ecg Extension for NWB

This extension is developed to extend NWB data standards to incorporate ECG recordings. ```CardiacSeries```, the basic neurotype in this extension, in fact extends the base type of NWB TimeSeries and can be stored into three specific data interfaces of ```ECG```, ```HeartRate``` and ```AuxiliaryAnalysis```. Also, the ```ECGChannelsGroup``` is another neurotype in this module which extends an NWB container and stores recording channels information along with the electrodes implementation (passed as DynamicTables) and a link to another extended neurotype -```ECGRecDevice```- which extends the type Device.

<div align="center">
<img src="https://github.com/Hamidreza-Alimohammadi/ndx_ecg/assets/63550467/be2435b2-e9ac-4c54-9c11-7a25c440f27b" width="700">
</div>

## Installation
Simply clone the repo and navigate to the root directory, then:
```
pip install .
```
## Test
A roundTrip test is runnable by ```pytest``` from the root. The test script can be found here:
```
\src\pynwb\tests
```
## An example use-case
The following is an example use case of ```ndx-ecg``` with explanatory comments. First, we build up an ```nwbfile``` and define an endpoint recording device:
```python
from datetime import datetime
from uuid import uuid4
import numpy as np
from dateutil.tz import tzlocal
from pynwb import NWBHDF5IO, NWBFile
from hdmf.common import DynamicTable

from ndx_ecg import (
    CardiacSeries, 
    ECG, 
    HeartRate, 
    AuxiliaryAnalysis, 
    ECGChannelsGroup, 
    ECGRecDevice
)


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
```
Then, we define two instances of ```DynamicTable```, to represent the meta-data on the recording electrodes and also the recording channels:
```python
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
nwbfile.add_analysis(ecg_electrodes_table)  # storage point for custom DT and NWB-C

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
nwbfile.add_analysis(recording_channels_table)  # storage point for custom DT and NWB-C
```
Now, we can define an instance of ```ECGRecDevice```:
```python
# define an ECGRecDevice-type device for ecg recording
ecg_device = ECGRecDevice(
    name='name_of_the_ECGRD',
    description='description_of_the_ECGRD',
    manufacturer='manufacturer_of_the_ECGRD',
    filtering='notch-60Hz-analog',
    gain='100',
    offset='0',
    synchronization='taken care of via ...',
    endpoint_recording_device=main_device
)
# adding the object of ECGRecDevice
nwbfile.add_device(ecg_device)
```
And also an instance of ```ECGChannelsGroup```:
```python
ecg_channels_group = ECGChannelsGroup(
    name='ecg_channels_group',
    group_description='a group to store electrodes and channels table, and linking to ECGRecDevice.',
    electrodes=ecg_electrodes_table,
    channels=recording_channels_table,
    recording_device=ecg_device
)
# adding the object of ECGChannelsGroup
nwbfile.add_analysis(ecg_channels_group)  # storage point for custom DT and NWB-C
#
```
Now, we have all the required standard arguments to genearate instances of ```CardiacSeries``` and stroing them in our three different NWBDataInterfaces:
```python
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
```
Here, we built an instance of our ```CradiacSeries``` to store a dummy raw ECG acquisition into a specified ```ECG``` interface, and we store it as an acquisition into the ```nwbfile```:
```python
# adding the raw acquisition of ECG to the nwb_file inside an 'ECG' container
nwbfile.add_acquisition(ecg_raw)
```
In the following, we have taken the similar approach but this time storing dummy data as processed data, into specific interfaces of ```HeartRate``` and ```AuxiliaryAnalysis```, then storing it into a -to be defined- ```ecg_module```:
```python
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
ecg_module = nwbfile.create_processing_module(
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

```
Now, the ```nwbfile``` is ready to be written on the disk and read back. 

