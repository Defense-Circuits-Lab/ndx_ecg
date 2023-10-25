.. _sec-ECG-src:

ECG
^^^

**Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`

**Description:** see :numref:`sec-ECG`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Explain how the time-series is processed or whether it is a raw acquisition.
      dtype: text
      name: processing_description
      required: false
    default_name: ECG
    doc: Specific data interface for ElectroCardioGram time-series (raw/processed).
    groups:
    - doc: CardiacSeries object representing the ElectroCardioGram (ECG). Whether raw
        or processed.
      neurodata_type_inc: CardiacSeries
      quantity: +
    neurodata_type_def: ECG
    neurodata_type_inc: NWBDataInterface


