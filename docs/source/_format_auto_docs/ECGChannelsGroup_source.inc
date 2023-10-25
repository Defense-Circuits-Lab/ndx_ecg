.. _sec-ECGChannelsGroup-src:

ECGChannelsGroup
^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBContainer <sec-NWBContainer>`

**Description:** see :numref:`sec-ECGChannelsGroup`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Describe the recording channels for this specific experiment session.
      dtype: text
      name: group_description
      required: false
    doc: Information of all channels from which the corresponding CardiacSeries is generated.
      Note that these channels can represent single recording electrodes or differential
      recordings.
    groups:
    - doc: A dynamic table of the implemented electrodes.
      name: electrodes
      neurodata_type_inc: DynamicTable
    - doc: A dynamic table of the ECG recording channels.
      name: channels
      neurodata_type_inc: DynamicTable
    links:
    - doc: Link to the ECGRecDevice used to record cardiac signals.
      name: recording_device
      target_type: ECGRecDevice
    neurodata_type_def: ECGChannelsGroup
    neurodata_type_inc: NWBContainer


