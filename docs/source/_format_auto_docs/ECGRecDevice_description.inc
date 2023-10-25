.. _sec-ECGRecDevice:

ECGRecDevice
^^^^^^^^^^^^

**Overview:** ECG recording device.


``ECGRecDevice`` extends ``Device`` and includes all elements of :ref:`Device <sec-Device>` with the following additions or changes.



- **Extends:** :ref:`Device <sec-Device>`
- **Primitive Type:** Group
- **Inherits from:** :ref:`Device <sec-Device>`, :ref:`NWBContainer <sec-NWBContainer>`, :ref:`Container <sec-Container>`
- **Source filename:** ndx-ecg.extensions.yaml
- **Source Specification:** see :numref:`sec-ECGRecDevice-src`


.. figure:: ./_format_auto_docs/ECGRecDevice.*
    :alt: ECGRecDevice




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ECGRecDevice-data:

.. table:: Datasets, Links, and Attributes contained in <ECGRecDevice>
    :class: longtable

    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------+
    | Id                           | Type        | Description                                                                                                             |
    +==============================+=============+=========================================================================================================================+
    | <ECGRecDevice>               | Group       | Top level Group for <ECGRecDevice>                                                                                      |
    |                              |             |                                                                                                                         |
    |                              |             | - **Neurodata Type:** :ref:`ECGRecDevice <sec-ECGRecDevice>`                                                            |
    |                              |             | - **Extends:** :ref:`Device <sec-Device>`                                                                               |
    |                              |             |                                                                                                                         |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------+
    | .filtering                   | Attribute   | Explain analogue frequency filtering of the ECG acquisition device, if any is implemented.                              |
    |                              |             |                                                                                                                         |
    |                              |             | - **Data Type:** text                                                                                                   |
    |                              |             | - **Required:** False                                                                                                   |
    |                              |             | - **Name:** filtering                                                                                                   |
    |                              |             |                                                                                                                         |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------+
    | .gain                        | Attribute   | Explain the gain settings of the ECG acquisition device.                                                                |
    |                              |             |                                                                                                                         |
    |                              |             | - **Data Type:** text                                                                                                   |
    |                              |             | - **Required:** False                                                                                                   |
    |                              |             | - **Name:** gain                                                                                                        |
    |                              |             |                                                                                                                         |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------+
    | .offset                      | Attribute   | Explain what the baseline of the ECG signal is set to.                                                                  |
    |                              |             |                                                                                                                         |
    |                              |             | - **Data Type:** text                                                                                                   |
    |                              |             | - **Required:** False                                                                                                   |
    |                              |             | - **Name:** offset                                                                                                      |
    |                              |             |                                                                                                                         |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------+
    | .synchronization             | Attribute   | Explain the synchronization settings if the ECG recording device is separately connected to another recording system.   |
    |                              |             |                                                                                                                         |
    |                              |             | - **Data Type:** text                                                                                                   |
    |                              |             | - **Required:** False                                                                                                   |
    |                              |             | - **Name:** synchronization                                                                                             |
    |                              |             |                                                                                                                         |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------+
    | .endpoint_recording_device   | Link        | endpoint recording device to which the ECG recording device is connected.                                               |
    |                              |             |                                                                                                                         |
    |                              |             | - **Target Type** :ref:`Device <sec-Device>`                                                                            |
    |                              |             | - **Name:** endpoint_recording_device                                                                                   |
    |                              |             |                                                                                                                         |
    +------------------------------+-------------+-------------------------------------------------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ECGRecDevice-groups:

.. table:: Groups contained in <ECGRecDevice>
    :class: longtable

    +------------------------------+---------+-----------------------------------------------------------------------------+
    | Id                           | Type    | Description                                                                 |
    +==============================+=========+=============================================================================+
    | <ECGRecDevice>               | Group   | Top level Group for <ECGRecDevice>                                          |
    |                              |         |                                                                             |
    |                              |         | - **Neurodata Type:** :ref:`ECGRecDevice <sec-ECGRecDevice>`                |
    |                              |         | - **Extends:** :ref:`Device <sec-Device>`                                   |
    |                              |         |                                                                             |
    +------------------------------+---------+-----------------------------------------------------------------------------+
    | .endpoint_recording_device   | Link    | endpoint recording device to which the ECG recording device is connected.   |
    |                              |         |                                                                             |
    |                              |         | - **Target Type** :ref:`Device <sec-Device>`                                |
    |                              |         | - **Name:** endpoint_recording_device                                       |
    |                              |         |                                                                             |
    +------------------------------+---------+-----------------------------------------------------------------------------+


