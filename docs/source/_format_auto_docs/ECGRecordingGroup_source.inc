.. _sec-ECGRecordingGroup-src:

ECGRecordingGroup
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`LabMetaData <sec-LabMetaData>`

**Description:** see :numref:`sec-ECGRecordingGroup`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Describe the recording channels for this specific experiment session.
      dtype: text
      name: group_description
      required: false
    doc: Information of all electrodes, channels and the recording device from which the
      corresponding CardiacSeries is obtained.
    groups:
    - doc: An extended dynamic table of the implemented electrodes.
      name: electrodes
      neurodata_type_inc: ECGElectrodes
    - doc: An extended dynamic table of the ECG recording channels.
      name: channels
      neurodata_type_inc: ECGChannels
    links:
    - doc: Link to the ECGRecDevice used to record cardiac signals.
      name: recording_device
      target_type: ECGRecDevice
    neurodata_type_def: ECGRecordingGroup
    neurodata_type_inc: LabMetaData


