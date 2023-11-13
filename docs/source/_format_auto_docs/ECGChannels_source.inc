.. _sec-ECGChannels-src:

ECGChannels
^^^^^^^^^^^

**Extends:** :ref:`DynamicTable <sec-DynamicTable>`

**Description:** see :numref:`sec-ECGChannels`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - doc: Reference name of the corresponding recording channel.
      dtype: text
      name: channel_name
      neurodata_type_inc: VectorData
    - doc: Type of the recording channel, e.g., single or differential.
      dtype: text
      name: channel_type
      neurodata_type_inc: VectorData
    - doc: Reference of the electrodes involved in the corresponding recording channel.
      dtype: text
      name: involved_electrodes
      neurodata_type_inc: VectorData
    - doc: Descriptive information on the corresponding recording channel.
      dtype: text
      name: channel_info
      neurodata_type_inc: VectorData
    doc: Meta information of the channels from which the CardiacSeries is obtained.
    name: channels
    neurodata_type_def: ECGChannels
    neurodata_type_inc: DynamicTable


