.. _sec-AuxiliaryAnalysis-src:

AuxiliaryAnalysis
^^^^^^^^^^^^^^^^^

**Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`

**Description:** see :numref:`sec-AuxiliaryAnalysis`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Explain how the analysis is processed.
      dtype: text
      name: processing_description
      required: false
    default_name: AuxiliaryAnalysis
    doc: Specific data interface for whatever relevant auxiliary in-between analysis.
    groups:
    - doc: CardiacSeries object representing the auxiliary analysis.
      neurodata_type_inc: CardiacSeries
      quantity: +
    neurodata_type_def: AuxiliaryAnalysis
    neurodata_type_inc: NWBDataInterface


