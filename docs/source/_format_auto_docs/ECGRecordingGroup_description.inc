.. _sec-ECGRecordingGroup:

ECGRecordingGroup
^^^^^^^^^^^^^^^^^

**Overview:** Information of all electrodes, channels and the recording device from which the corresponding CardiacSeries is obtained.


``ECGRecordingGroup`` extends ``LabMetaData`` and includes all elements of :ref:`LabMetaData <sec-LabMetaData>` with the following additions or changes.



- **Extends:** :ref:`LabMetaData <sec-LabMetaData>`
- **Primitive Type:** Group
- **Inherits from:** :ref:`LabMetaData <sec-LabMetaData>`, :ref:`NWBContainer <sec-NWBContainer>`, :ref:`Container <sec-Container>`
- **Source filename:** ndx-ecg.extensions.yaml
- **Source Specification:** see :numref:`sec-ECGRecordingGroup-src`


.. figure:: ./_format_auto_docs/ECGRecordingGroup.*
    :alt: ECGRecordingGroup




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ECGRecordingGroup-data:

.. table:: Datasets, Links, and Attributes contained in <ECGRecordingGroup>
    :class: longtable

    +-----------------------+-------------+--------------------------------------------------------------------------+
    | Id                    | Type        | Description                                                              |
    +=======================+=============+==========================================================================+
    | <ECGRecordingGroup>   | Group       | Top level Group for <ECGRecordingGroup>                                  |
    |                       |             |                                                                          |
    |                       |             | - **Neurodata Type:** :ref:`ECGRecordingGroup <sec-ECGRecordingGroup>`   |
    |                       |             | - **Extends:** :ref:`LabMetaData <sec-LabMetaData>`                      |
    |                       |             |                                                                          |
    +-----------------------+-------------+--------------------------------------------------------------------------+
    | .group_description    | Attribute   | Describe the recording channels for this specific experiment session.    |
    |                       |             |                                                                          |
    |                       |             | - **Data Type:** text                                                    |
    |                       |             | - **Required:** False                                                    |
    |                       |             | - **Name:** group_description                                            |
    |                       |             |                                                                          |
    +-----------------------+-------------+--------------------------------------------------------------------------+
    | .recording_device     | Link        | Link to the ECGRecDevice used to record cardiac signals.                 |
    |                       |             |                                                                          |
    |                       |             | - **Target Type** :ref:`ECGRecDevice <sec-ECGRecDevice>`                 |
    |                       |             | - **Name:** recording_device                                             |
    |                       |             |                                                                          |
    +-----------------------+-------------+--------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ECGRecordingGroup-groups:

.. table:: Groups contained in <ECGRecordingGroup>
    :class: longtable

    +-----------------------+---------+--------------------------------------------------------------------------+
    | Id                    | Type    | Description                                                              |
    +=======================+=========+==========================================================================+
    | <ECGRecordingGroup>   | Group   | Top level Group for <ECGRecordingGroup>                                  |
    |                       |         |                                                                          |
    |                       |         | - **Neurodata Type:** :ref:`ECGRecordingGroup <sec-ECGRecordingGroup>`   |
    |                       |         | - **Extends:** :ref:`LabMetaData <sec-LabMetaData>`                      |
    |                       |         |                                                                          |
    +-----------------------+---------+--------------------------------------------------------------------------+
    | .recording_device     | Link    | Link to the ECGRecDevice used to record cardiac signals.                 |
    |                       |         |                                                                          |
    |                       |         | - **Target Type** :ref:`ECGRecDevice <sec-ECGRecDevice>`                 |
    |                       |         | - **Name:** recording_device                                             |
    |                       |         |                                                                          |
    +-----------------------+---------+--------------------------------------------------------------------------+
    | .electrodes           | Group   | An extended dynamic table of the implemented electrodes.                 |
    |                       |         |                                                                          |
    |                       |         | - **Extends:** :ref:`ECGElectrodes <sec-ECGElectrodes>`                  |
    |                       |         | - **Name:** electrodes                                                   |
    |                       |         |                                                                          |
    +-----------------------+---------+--------------------------------------------------------------------------+
    | .channels             | Group   | An extended dynamic table of the ECG recording channels.                 |
    |                       |         |                                                                          |
    |                       |         | - **Extends:** :ref:`ECGChannels <sec-ECGChannels>`                      |
    |                       |         | - **Name:** channels                                                     |
    |                       |         |                                                                          |
    +-----------------------+---------+--------------------------------------------------------------------------+


Groups: electrodes
""""""""""""""""""

An extended dynamic table of the implemented electrodes.



- **Extends:** :ref:`ECGElectrodes <sec-ECGElectrodes>`
- **Name:** electrodes

Groups: channels
""""""""""""""""

An extended dynamic table of the ECG recording channels.



- **Extends:** :ref:`ECGChannels <sec-ECGChannels>`
- **Name:** channels

