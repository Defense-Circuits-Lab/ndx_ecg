# -*- coding: utf-8 -*-
import os.path

from pynwb.spec import (NWBNamespaceBuilder, export_spec,
                        NWBGroupSpec, NWBAttributeSpec, NWBDatasetSpec, NWBLinkSpec)


def main():
    # these arguments were auto-generated from your cookiecutter inputs
    ns_builder = NWBNamespaceBuilder(
        doc="""This extension is developed to extend NWB data standards to incorporate ECG recordings.""",
        name="""ndx-ecg""",
        version="""0.1.0""",
        author=list(map(str.strip, """Hamidreza Alimohammadi ([AT]DefenseCircuitsLab)""".split(','))),
        contact=list(map(str.strip, """alimohammadi.hamidreza@gmail.com""".split(',')))
    )

    ns_builder.include_type('TimeSeries', namespace='core')
    ns_builder.include_type('DynamicTable', namespace='hdmf-common')
    ns_builder.include_type('VectorData', namespace='hdmf-common')
    ns_builder.include_type('Device', namespace='core')
    ns_builder.include_type('NWBDataInterface', namespace='core')
    ns_builder.include_type('LabMetaData', namespace='core')

    ecg_recording_device = NWBGroupSpec(
        neurodata_type_def='ECGRecDevice',
        neurodata_type_inc='Device',
        doc='ECG recording device.',
        attributes=[
            NWBAttributeSpec(
                name='filtering',
                doc='Explain analogue frequency filtering of the ECG acquisition device, '
                    'if any is implemented.',
                dtype='text',
                required=False
            ),
            NWBAttributeSpec(
                name='gain',
                doc='Explain the gain settings of the ECG acquisition device.',
                dtype='text',
                required=False
            ),
            NWBAttributeSpec(
                name='offset',
                doc='Explain what the baseline of the ECG signal is set to.',
                dtype='text',
                required=False
            ),
            NWBAttributeSpec(
                name='synchronization',
                doc='Explain the synchronization settings if the ECG recording device is separately connected to '
                    'another recording system.',
                dtype='text',
                required=False
            )
        ],
        links=[
            NWBLinkSpec(
                name='endpoint_recording_device',
                target_type='Device',
                doc='endpoint recording device to which the ECG recording device is connected.'
            )
        ]
    )

    ecg_electrodes = NWBGroupSpec(
        neurodata_type_def='ECGElectrodes',
        neurodata_type_inc='DynamicTable',
        name='electrodes',
        doc='Meta information of the electrodes from which the ECG signals are being recorded.',
        datasets=[
            NWBDatasetSpec(
                name='electrode_name',
                neurodata_type_inc='VectorData',
                dtype='text',
                doc='Reference name of the corresponding electrode.'
            ),
            NWBDatasetSpec(
                name='electrode_location',
                neurodata_type_inc='VectorData',
                dtype='text',
                doc='Implementation location of the corresponding electrode.'
            ),
            NWBDatasetSpec(
                name='electrode_info',
                neurodata_type_inc='VectorData',
                dtype='text',
                doc='Descriptive information on the corresponding electrode'
            ),
        ]
    )

    ecg_channels = NWBGroupSpec(
        neurodata_type_def='ECGChannels',
        neurodata_type_inc='DynamicTable',
        name='channels',
        doc='Meta information of the channels from which the CardiacSeries is obtained.',
        datasets=[
            NWBDatasetSpec(
                name='channel_name',
                neurodata_type_inc='VectorData',
                dtype='text',
                doc='Reference name of the corresponding recording channel.'
            ),
            NWBDatasetSpec(
                name='channel_type',
                neurodata_type_inc='VectorData',
                dtype='text',
                doc='Type of the recording channel, e.g., single or differential.'
            ),
            NWBDatasetSpec(
                name='involved_electrodes',
                neurodata_type_inc='VectorData',
                dtype='text',
                doc='Reference of the electrodes involved in the corresponding recording channel.'
            ),
            NWBDatasetSpec(
                name='channel_info',
                neurodata_type_inc='VectorData',
                dtype='text',
                doc='Descriptive information on the corresponding recording channel.'
            )
        ]
    )

    ecg_recording_group = NWBGroupSpec(
        neurodata_type_def='ECGRecordingGroup',
        neurodata_type_inc='LabMetaData',
        doc='Information of all electrodes, channels and the recording device from which the corresponding '
            'CardiacSeries is obtained.',
        attributes=[
            NWBAttributeSpec(
                name='group_description',
                doc='Describe the recording channels for this specific experiment session.',
                dtype='text',
                required=False
            )
        ],
        groups=[
            NWBGroupSpec(
                name='electrodes',
                neurodata_type_inc='ECGElectrodes',
                doc='An extended dynamic table of the implemented electrodes.',
            ),
            NWBGroupSpec(
                name='channels',
                neurodata_type_inc='ECGChannels',
                doc='An extended dynamic table of the ECG recording channels.',
            )
        ],
        links=[
            NWBLinkSpec(
                name='recording_device',
                target_type='ECGRecDevice',
                doc='Link to the ECGRecDevice used to record cardiac signals.'
            )
        ]
    )

    cardiac_series = NWBGroupSpec(
        neurodata_type_def='CardiacSeries',
        neurodata_type_inc='TimeSeries',
        doc='A group to store standardized cardiac time-series, e.g., ECG and HeartRate, including '
            'acquisitions, processed cardiac series or auxiliary analysis.',
        datasets=[
            NWBDatasetSpec(
                name='data',
                dtype='numeric',
                doc='Associated cardiac-series data. Note that in general, this data could be a numerical array,'
                    'the columns of which corresponding to the recording channels, indexed similarly as the rows '
                    'of the dynamic table passed for the channels argument. Notice the difference between electrodes '
                    'table and the recording channels.',
                attributes=[
                    NWBAttributeSpec(
                        name='unit',
                        dtype='text',
                        doc='Default measurement unit of the corresponding cardiac-series.'
                    ),
                    NWBAttributeSpec(
                        name='which_channels',
                        dtype='text',
                        value='One to one map with all the channels in ECGRecDevice.',
                        doc='Determine that the columns of data here corresponds to which recording channels. '
                            'By default it is meant to be a one to one map to the recording channels table, passed '
                            'to the ECGRecDevice container. A use case can be like <0: ch_0, 1:ch_2>, implying '
                            'that the data is of two columns and the 0-th and 1-th columns correspond to ch_0 and '
                            'ch_2 of all the recording channels, respectively.'
                    ),
                    NWBAttributeSpec(
                        name='conversion',
                        dtype='float32',
                        value=1.0,
                        doc='Global conversion factor for corresponding cardiac-series. See also channel_conversion. '
                            'finally, the stored data-set for each channel will be returned in default unit using '
                            'the scaling as: data-in-default-unit = data * conversion * channel_conversion.'
                    )
                ]
            ),
            NWBDatasetSpec(
                name='channel_conversion',
                dtype='float32',
                quantity='?',
                doc='Conventional NWB channel-specific conversion factor. Default value would be 1. '
                    'See also conversion. Finally, the stored data-set for each channel will be returned in '
                    'default unit using the scaling as: '
                    'data-in-default-unit = data * conversion * channel_conversion.',
                attributes=[
                    NWBAttributeSpec(
                        name='axis',
                        dtype='int32',
                        value=1,
                        doc='Zero-indexed axis of the data that the channel-specific conversion factor corresponds to.'
                    )
                ]
            )
        ],
        links=[
            NWBLinkSpec(
                name='recording_group',
                target_type='ECGRecordingGroup',
                doc='Link to the ECGRecordingGroup as a reference for recording channels, recording electrodes '
                    'and the recording device.'
            )
        ]
    )

    ecg_series = NWBGroupSpec(
        neurodata_type_def='ECG',
        neurodata_type_inc='NWBDataInterface',
        default_name='ECG',
        doc='Specific data interface for ElectroCardioGram time-series (raw/processed).',
        attributes=[
            NWBAttributeSpec(
                name='processing_description',
                doc='Explain how the time-series is processed or whether it is a raw acquisition.',
                dtype='text',
                required=False
            )
        ],
        groups=[
            NWBGroupSpec(
                neurodata_type_inc='CardiacSeries',
                doc='CardiacSeries object representing the ElectroCardioGram (ECG). Whether raw or processed.',
                quantity='+'
            )
        ]
    )

    hr_series = NWBGroupSpec(
        neurodata_type_def='HeartRate',
        neurodata_type_inc='NWBDataInterface',
        default_name='HeartRate',
        doc='Specific data interface for HeartRate.',
        attributes=[
            NWBAttributeSpec(
                name='processing_description',
                doc='Explain how the time-series is processed or whether it is a raw acquisition.',
                dtype='text',
                required=False
            )
        ],
        groups=[
            NWBGroupSpec(
                neurodata_type_inc='CardiacSeries',
                doc='CardiacSeries object representing the HearRate (HR). Whether raw or processed.',
                quantity='+'
            )
        ]
    )

    aux_analysis = NWBGroupSpec(
        neurodata_type_def='AuxiliaryAnalysis',
        neurodata_type_inc='NWBDataInterface',
        default_name='AuxiliaryAnalysis',
        doc='Specific data interface for whatever relevant auxiliary in-between analysis.',
        attributes=[
            NWBAttributeSpec(
                name='processing_description',
                doc='Explain how the analysis is processed.',
                dtype='text',
                required=False
            )
        ],
        groups=[
            NWBGroupSpec(
                neurodata_type_inc='CardiacSeries',
                doc='CardiacSeries object representing the auxiliary analysis.',
                quantity='+'
            )
        ]
    )

    new_data_types = [cardiac_series, ecg_series, hr_series, aux_analysis,
                      ecg_recording_group, ecg_recording_device, ecg_electrodes, ecg_channels]

    # export the spec to yaml files in the spec folder
    output_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), '..', '..', 'spec'))
    export_spec(ns_builder, new_data_types, output_dir)
    print('Spec files generated. Please make sure to rerun `pip install .` to load the changes.')


if __name__ == '__main__':
    # usage: python create_extension_spec.py
    main()
