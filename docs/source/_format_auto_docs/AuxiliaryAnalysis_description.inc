.. _sec-AuxiliaryAnalysis:

AuxiliaryAnalysis
^^^^^^^^^^^^^^^^^

**Overview:** Specific data interface for whatever relevant auxiliary in-between analysis.


``AuxiliaryAnalysis`` extends ``NWBDataInterface`` and includes all elements of :ref:`NWBDataInterface <sec-NWBDataInterface>` with the following additions or changes.



- **Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`
- **Primitive Type:** Group
- **Default Name:** AuxiliaryAnalysis
- **Inherits from:** :ref:`NWBDataInterface <sec-NWBDataInterface>`, :ref:`NWBContainer <sec-NWBContainer>`, :ref:`Container <sec-Container>`
- **Source filename:** ndx-ecg.extensions.yaml
- **Source Specification:** see :numref:`sec-AuxiliaryAnalysis-src`


.. figure:: ./_format_auto_docs/AuxiliaryAnalysis.*
    :alt: AuxiliaryAnalysis




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-AuxiliaryAnalysis-data:

.. table:: Datasets, Links, and Attributes contained in <AuxiliaryAnalysis>
    :class: longtable

    +---------------------------+-------------+--------------------------------------------------------------------------+
    | Id                        | Type        | Description                                                              |
    +===========================+=============+==========================================================================+
    | <AuxiliaryAnalysis>       | Group       | Top level Group for <AuxiliaryAnalysis>                                  |
    |                           |             |                                                                          |
    |                           |             | - **Neurodata Type:** :ref:`AuxiliaryAnalysis <sec-AuxiliaryAnalysis>`   |
    |                           |             | - **Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`            |
    |                           |             | - **Default Name:** AuxiliaryAnalysis                                    |
    |                           |             |                                                                          |
    +---------------------------+-------------+--------------------------------------------------------------------------+
    | .processing_description   | Attribute   | Explain how the analysis is processed.                                   |
    |                           |             |                                                                          |
    |                           |             | - **Data Type:** text                                                    |
    |                           |             | - **Required:** False                                                    |
    |                           |             | - **Name:** processing_description                                       |
    |                           |             |                                                                          |
    +---------------------------+-------------+--------------------------------------------------------------------------+




.. tabularcolumns:: |p{4cm}|p{1cm}|p{10cm}|
.. _table-AuxiliaryAnalysis-groups:

.. table:: Groups contained in <AuxiliaryAnalysis>
    :class: longtable

    +-----------------------------------------------+---------+--------------------------------------------------------------------------+
    | Id                                            | Type    | Description                                                              |
    +===============================================+=========+==========================================================================+
    | <AuxiliaryAnalysis>                           | Group   | Top level Group for <AuxiliaryAnalysis>                                  |
    |                                               |         |                                                                          |
    |                                               |         | - **Neurodata Type:** :ref:`AuxiliaryAnalysis <sec-AuxiliaryAnalysis>`   |
    |                                               |         | - **Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`            |
    |                                               |         | - **Default Name:** AuxiliaryAnalysis                                    |
    |                                               |         |                                                                          |
    +-----------------------------------------------+---------+--------------------------------------------------------------------------+
    | .<:ref:`CardiacSeries <sec-CardiacSeries>`>   | Group   | CardiacSeries object representing the auxiliary analysis.                |
    |                                               |         |                                                                          |
    |                                               |         | - **Extends:** :ref:`CardiacSeries <sec-CardiacSeries>`                  |
    |                                               |         | - **Quantity:** 1 or more                                                |
    |                                               |         |                                                                          |
    +-----------------------------------------------+---------+--------------------------------------------------------------------------+


Groups: <CardiacSeries>
"""""""""""""""""""""""

CardiacSeries object representing the auxiliary analysis.



- **Extends:** :ref:`CardiacSeries <sec-CardiacSeries>`
- **Quantity:** 1 or more

