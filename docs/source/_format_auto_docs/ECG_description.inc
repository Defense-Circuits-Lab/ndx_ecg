.. _sec-ECG:

ECG
^^^

**Overview:** Specific data interface for ElectroCardioGram time-series (raw/processed).


``ECG`` extends ``NWBDataInterface`` and includes all elements of :ref:`NWBDataInterface <sec-NWBDataInterface>` with the following additions or changes.



- **Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`
- **Primitive Type:** Group
- **Default Name:** ECG
- **Inherits from:** :ref:`NWBDataInterface <sec-NWBDataInterface>`, :ref:`NWBContainer <sec-NWBContainer>`, :ref:`Container <sec-Container>`
- **Source filename:** ndx-ecg.extensions.yaml
- **Source Specification:** see :numref:`sec-ECG-src`


.. figure:: ./_format_auto_docs/ECG.*
    :alt: ECG




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ECG-data:

.. table:: Datasets, Links, and Attributes contained in <ECG>
    :class: longtable

    +---------------------------+-------------+--------------------------------------------------------------------------------+
    | Id                        | Type        | Description                                                                    |
    +===========================+=============+================================================================================+
    | <ECG>                     | Group       | Top level Group for <ECG>                                                      |
    |                           |             |                                                                                |
    |                           |             | - **Neurodata Type:** :ref:`ECG <sec-ECG>`                                     |
    |                           |             | - **Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`                  |
    |                           |             | - **Default Name:** ECG                                                        |
    |                           |             |                                                                                |
    +---------------------------+-------------+--------------------------------------------------------------------------------+
    | .processing_description   | Attribute   | Explain how the time-series is processed or whether it is a raw acquisition.   |
    |                           |             |                                                                                |
    |                           |             | - **Data Type:** text                                                          |
    |                           |             | - **Required:** False                                                          |
    |                           |             | - **Name:** processing_description                                             |
    |                           |             |                                                                                |
    +---------------------------+-------------+--------------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-ECG-groups:

.. table:: Groups contained in <ECG>
    :class: longtable

    +-----------------------------------------------+---------+--------------------------------------------------------------------------------------------+
    | Id                                            | Type    | Description                                                                                |
    +===============================================+=========+============================================================================================+
    | <ECG>                                         | Group   | Top level Group for <ECG>                                                                  |
    |                                               |         |                                                                                            |
    |                                               |         | - **Neurodata Type:** :ref:`ECG <sec-ECG>`                                                 |
    |                                               |         | - **Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`                              |
    |                                               |         | - **Default Name:** ECG                                                                    |
    |                                               |         |                                                                                            |
    +-----------------------------------------------+---------+--------------------------------------------------------------------------------------------+
    | .<:ref:`CardiacSeries <sec-CardiacSeries>`>   | Group   | CardiacSeries object representing the ElectroCardioGram (ECG). Whether raw or processed.   |
    |                                               |         |                                                                                            |
    |                                               |         | - **Extends:** :ref:`CardiacSeries <sec-CardiacSeries>`                                    |
    |                                               |         | - **Quantity:** 1 or more                                                                  |
    |                                               |         |                                                                                            |
    +-----------------------------------------------+---------+--------------------------------------------------------------------------------------------+


Groups: <CardiacSeries>
"""""""""""""""""""""""

CardiacSeries object representing the ElectroCardioGram (ECG). Whether raw or processed.



- **Extends:** :ref:`CardiacSeries <sec-CardiacSeries>`
- **Quantity:** 1 or more

