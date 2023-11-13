.. _sec-ECGElectrodes:

ECGElectrodes
^^^^^^^^^^^^^

**Overview:** Meta information of the electrodes from which the ECG signals are being recorded.


``ECGElectrodes`` extends ``DynamicTable`` and includes all elements of :ref:`DynamicTable <sec-DynamicTable>` with the following additions or changes.



- **Extends:** :ref:`DynamicTable <sec-DynamicTable>`
- **Primitive Type:** Group
- **Name:** electrodes
- **Inherits from:** :ref:`DynamicTable <sec-DynamicTable>`, :ref:`Container <sec-Container>`
- **Source filename:** ndx-ecg.extensions.yaml
- **Source Specification:** see :numref:`sec-ECGElectrodes-src`


.. figure:: ./_format_auto_docs/ECGElectrodes.*
    :alt: ECGElectrodes




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ECGElectrodes-data:

.. table:: Datasets, Links, and Attributes contained in <ECGElectrodes>
    :class: longtable

    +-----------------------+-----------+------------------------------------------------------------------+
    | Id                    | Type      | Description                                                      |
    +=======================+===========+==================================================================+
    | electrodes            | Group     | Top level Group for electrodes                                   |
    |                       |           |                                                                  |
    |                       |           | - **Neurodata Type:** :ref:`ECGElectrodes <sec-ECGElectrodes>`   |
    |                       |           | - **Extends:** :ref:`DynamicTable <sec-DynamicTable>`            |
    |                       |           | - **Name:** electrodes                                           |
    |                       |           |                                                                  |
    +-----------------------+-----------+------------------------------------------------------------------+
    | .electrode_name       | Dataset   | Reference name of the corresponding electrode.                   |
    |                       |           |                                                                  |
    |                       |           | - **Extends:** :ref:`VectorData <sec-VectorData>`                |
    |                       |           | - **Data Type:** text                                            |
    |                       |           | - **Name:** electrode_name                                       |
    |                       |           |                                                                  |
    +-----------------------+-----------+------------------------------------------------------------------+
    | .electrode_location   | Dataset   | Implementation location of the corresponding electrode.          |
    |                       |           |                                                                  |
    |                       |           | - **Extends:** :ref:`VectorData <sec-VectorData>`                |
    |                       |           | - **Data Type:** text                                            |
    |                       |           | - **Name:** electrode_location                                   |
    |                       |           |                                                                  |
    +-----------------------+-----------+------------------------------------------------------------------+
    | .electrode_info       | Dataset   | Descriptive information on the corresponding electrode           |
    |                       |           |                                                                  |
    |                       |           | - **Extends:** :ref:`VectorData <sec-VectorData>`                |
    |                       |           | - **Data Type:** text                                            |
    |                       |           | - **Name:** electrode_info                                       |
    |                       |           |                                                                  |
    +-----------------------+-----------+------------------------------------------------------------------+



