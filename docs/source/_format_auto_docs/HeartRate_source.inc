.. _sec-HeartRate-src:

HeartRate
^^^^^^^^^

**Extends:** :ref:`NWBDataInterface <sec-NWBDataInterface>`

**Description:** see :numref:`sec-HeartRate`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Explain how the time-series is processed or whether it is a raw acquisition.
      dtype: text
      name: processing_description
      required: false
    default_name: HeartRate
    doc: Specific data interface for HeartRate.
    groups:
    - doc: CardiacSeries object representing the HearRate (HR). Whether raw or processed.
      neurodata_type_inc: CardiacSeries
      quantity: +
    neurodata_type_def: HeartRate
    neurodata_type_inc: NWBDataInterface


