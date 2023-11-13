.. _sec-ECGChannels:

ECGChannels
^^^^^^^^^^^

**Overview:** Meta information of the channels from which the CardiacSeries is obtained.


``ECGChannels`` extends ``DynamicTable`` and includes all elements of :ref:`DynamicTable <sec-DynamicTable>` with the following additions or changes.



- **Extends:** :ref:`DynamicTable <sec-DynamicTable>`
- **Primitive Type:** Group
- **Name:** channels
- **Inherits from:** :ref:`DynamicTable <sec-DynamicTable>`, :ref:`Container <sec-Container>`
- **Source filename:** ndx-ecg.extensions.yaml
- **Source Specification:** see :numref:`sec-ECGChannels-src`


.. figure:: ./_format_auto_docs/ECGChannels.*
    :alt: ECGChannels




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ECGChannels-data:

.. table:: Datasets, Links, and Attributes contained in <ECGChannels>
    :class: longtable

    +------------------------+-----------+--------------------------------------------------------------------------------+
    | Id                     | Type      | Description                                                                    |
    +========================+===========+================================================================================+
    | channels               | Group     | Top level Group for channels                                                   |
    |                        |           |                                                                                |
    |                        |           | - **Neurodata Type:** :ref:`ECGChannels <sec-ECGChannels>`                     |
    |                        |           | - **Extends:** :ref:`DynamicTable <sec-DynamicTable>`                          |
    |                        |           | - **Name:** channels                                                           |
    |                        |           |                                                                                |
    +------------------------+-----------+--------------------------------------------------------------------------------+
    | .channel_name          | Dataset   | Reference name of the corresponding recording channel.                         |
    |                        |           |                                                                                |
    |                        |           | - **Extends:** :ref:`VectorData <sec-VectorData>`                              |
    |                        |           | - **Data Type:** text                                                          |
    |                        |           | - **Name:** channel_name                                                       |
    |                        |           |                                                                                |
    +------------------------+-----------+--------------------------------------------------------------------------------+
    | .channel_type          | Dataset   | Type of the recording channel, e.g., single or differential.                   |
    |                        |           |                                                                                |
    |                        |           | - **Extends:** :ref:`VectorData <sec-VectorData>`                              |
    |                        |           | - **Data Type:** text                                                          |
    |                        |           | - **Name:** channel_type                                                       |
    |                        |           |                                                                                |
    +------------------------+-----------+--------------------------------------------------------------------------------+
    | .involved_electrodes   | Dataset   | Reference of the electrodes involved in the corresponding recording channel.   |
    |                        |           |                                                                                |
    |                        |           | - **Extends:** :ref:`VectorData <sec-VectorData>`                              |
    |                        |           | - **Data Type:** text                                                          |
    |                        |           | - **Name:** involved_electrodes                                                |
    |                        |           |                                                                                |
    +------------------------+-----------+--------------------------------------------------------------------------------+
    | .channel_info          | Dataset   | Descriptive information on the corresponding recording channel.                |
    |                        |           |                                                                                |
    |                        |           | - **Extends:** :ref:`VectorData <sec-VectorData>`                              |
    |                        |           | - **Data Type:** text                                                          |
    |                        |           | - **Name:** channel_info                                                       |
    |                        |           |                                                                                |
    +------------------------+-----------+--------------------------------------------------------------------------------+



