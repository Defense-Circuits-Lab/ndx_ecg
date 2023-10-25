.. _sec-ECGChannelsGroup:

ECGChannelsGroup
^^^^^^^^^^^^^^^^

**Overview:** Information of all channels from which the corresponding CardiacSeries is generated. Note that these channels can represent single recording electrodes or differential recordings.


``ECGChannelsGroup`` extends ``NWBContainer`` and includes all elements of :ref:`NWBContainer <sec-NWBContainer>` with the following additions or changes.



- **Extends:** :ref:`NWBContainer <sec-NWBContainer>`
- **Primitive Type:** Group
- **Inherits from:** :ref:`NWBContainer <sec-NWBContainer>`, :ref:`Container <sec-Container>`
- **Source filename:** ndx-ecg.extensions.yaml
- **Source Specification:** see :numref:`sec-ECGChannelsGroup-src`


.. figure:: ./_format_auto_docs/ECGChannelsGroup.*
    :alt: ECGChannelsGroup




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ECGChannelsGroup-data:

.. table:: Datasets, Links, and Attributes contained in <ECGChannelsGroup>
    :class: longtable

    +----------------------+-------------+-------------------------------------------------------------------------+
    | Id                   | Type        | Description                                                             |
    +======================+=============+=========================================================================+
    | <ECGChannelsGroup>   | Group       | Top level Group for <ECGChannelsGroup>                                  |
    |                      |             |                                                                         |
    |                      |             | - **Neurodata Type:** :ref:`ECGChannelsGroup <sec-ECGChannelsGroup>`    |
    |                      |             | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                   |
    |                      |             |                                                                         |
    +----------------------+-------------+-------------------------------------------------------------------------+
    | .group_description   | Attribute   | Describe the recording channels for this specific experiment session.   |
    |                      |             |                                                                         |
    |                      |             | - **Data Type:** text                                                   |
    |                      |             | - **Required:** False                                                   |
    |                      |             | - **Name:** group_description                                           |
    |                      |             |                                                                         |
    +----------------------+-------------+-------------------------------------------------------------------------+
    | .recording_device    | Link        | Link to the ECGRecDevice used to record cardiac signals.                |
    |                      |             |                                                                         |
    |                      |             | - **Target Type** :ref:`ECGRecDevice <sec-ECGRecDevice>`                |
    |                      |             | - **Name:** recording_device                                            |
    |                      |             |                                                                         |
    +----------------------+-------------+-------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ECGChannelsGroup-groups:

.. table:: Groups contained in <ECGChannelsGroup>
    :class: longtable

    +----------------------+---------+------------------------------------------------------------------------+
    | Id                   | Type    | Description                                                            |
    +======================+=========+========================================================================+
    | <ECGChannelsGroup>   | Group   | Top level Group for <ECGChannelsGroup>                                 |
    |                      |         |                                                                        |
    |                      |         | - **Neurodata Type:** :ref:`ECGChannelsGroup <sec-ECGChannelsGroup>`   |
    |                      |         | - **Extends:** :ref:`NWBContainer <sec-NWBContainer>`                  |
    |                      |         |                                                                        |
    +----------------------+---------+------------------------------------------------------------------------+
    | .recording_device    | Link    | Link to the ECGRecDevice used to record cardiac signals.               |
    |                      |         |                                                                        |
    |                      |         | - **Target Type** :ref:`ECGRecDevice <sec-ECGRecDevice>`               |
    |                      |         | - **Name:** recording_device                                           |
    |                      |         |                                                                        |
    +----------------------+---------+------------------------------------------------------------------------+
    | .electrodes          | Group   | A dynamic table of the implemented electrodes.                         |
    |                      |         |                                                                        |
    |                      |         | - **Extends:** :ref:`DynamicTable <sec-DynamicTable>`                  |
    |                      |         | - **Name:** electrodes                                                 |
    |                      |         |                                                                        |
    +----------------------+---------+------------------------------------------------------------------------+
    | .channels            | Group   | A dynamic table of the ECG recording channels.                         |
    |                      |         |                                                                        |
    |                      |         | - **Extends:** :ref:`DynamicTable <sec-DynamicTable>`                  |
    |                      |         | - **Name:** channels                                                   |
    |                      |         |                                                                        |
    +----------------------+---------+------------------------------------------------------------------------+


Groups: electrodes
""""""""""""""""""

A dynamic table of the implemented electrodes.



- **Extends:** :ref:`DynamicTable <sec-DynamicTable>`
- **Name:** electrodes

Groups: channels
""""""""""""""""

A dynamic table of the ECG recording channels.



- **Extends:** :ref:`DynamicTable <sec-DynamicTable>`
- **Name:** channels

