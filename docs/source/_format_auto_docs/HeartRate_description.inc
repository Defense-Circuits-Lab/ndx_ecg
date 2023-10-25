.. _sec-HeartRate:

HeartRate
^^^^^^^^^

**Overview:** Specific data interface for HeartRate.


``HeartRate`` extends ``NWBDataInterface`` and includes all elements of :ref:`NWBDataInterface <sec-NWBDataInterface>` with the following additions or changes.



- **Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`
- **Primitive Type:** Group
- **Default Name:** HeartRate
- **Inherits from:** :ref:`NWBDataInterface <sec-NWBDataInterface>`, :ref:`NWBContainer <sec-NWBContainer>`, :ref:`Container <sec-Container>`
- **Source filename:** ndx-ecg.extensions.yaml
- **Source Specification:** see :numref:`sec-HeartRate-src`


.. figure:: ./_format_auto_docs/HeartRate.*
    :alt: HeartRate




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-HeartRate-data:

.. table:: Datasets, Links, and Attributes contained in <HeartRate>
    :class: longtable

    +---------------------------+-------------+--------------------------------------------------------------------------------+
    | Id                        | Type        | Description                                                                    |
    +===========================+=============+================================================================================+
    | <HeartRate>               | Group       | Top level Group for <HeartRate>                                                |
    |                           |             |                                                                                |
    |                           |             | - **Neurodata Type:** :ref:`HeartRate <sec-HeartRate>`                         |
    |                           |             | - **Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`                  |
    |                           |             | - **Default Name:** HeartRate                                                  |
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
.. _table-HeartRate-groups:

.. table:: Groups contained in <HeartRate>
    :class: longtable

    +-----------------------------------------------+---------+----------------------------------------------------------------------------------+
    | Id                                            | Type    | Description                                                                      |
    +===============================================+=========+==================================================================================+
    | <HeartRate>                                   | Group   | Top level Group for <HeartRate>                                                  |
    |                                               |         |                                                                                  |
    |                                               |         | - **Neurodata Type:** :ref:`HeartRate <sec-HeartRate>`                           |
    |                                               |         | - **Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`                    |
    |                                               |         | - **Default Name:** HeartRate                                                    |
    |                                               |         |                                                                                  |
    +-----------------------------------------------+---------+----------------------------------------------------------------------------------+
    | .<:ref:`CardiacSeries <sec-CardiacSeries>`>   | Group   | CardiacSeries object representing the HearRate (HR). Whether raw or processed.   |
    |                                               |         |                                                                                  |
    |                                               |         | - **Extends:** :ref:`CardiacSeries <sec-CardiacSeries>`                          |
    |                                               |         | - **Quantity:** 1 or more                                                        |
    |                                               |         |                                                                                  |
    +-----------------------------------------------+---------+----------------------------------------------------------------------------------+


Groups: <CardiacSeries>
"""""""""""""""""""""""

CardiacSeries object representing the HearRate (HR). Whether raw or processed.



- **Extends:** :ref:`CardiacSeries <sec-CardiacSeries>`
- **Quantity:** 1 or more

