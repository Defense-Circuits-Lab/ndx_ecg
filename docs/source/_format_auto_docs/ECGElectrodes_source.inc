.. _sec-ECGElectrodes-src:

ECGElectrodes
^^^^^^^^^^^^^

**Extends:** :ref:`DynamicTable <sec-DynamicTable>`

**Description:** see :numref:`sec-ECGElectrodes`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - doc: Reference name of the corresponding electrode.
      dtype: text
      name: electrode_name
      neurodata_type_inc: VectorData
    - doc: Implementation location of the corresponding electrode.
      dtype: text
      name: electrode_location
      neurodata_type_inc: VectorData
    - doc: Descriptive information on the corresponding electrode
      dtype: text
      name: electrode_info
      neurodata_type_inc: VectorData
    doc: Meta information of the electrodes from which the ECG signals are being recorded.
    name: electrodes
    neurodata_type_def: ECGElectrodes
    neurodata_type_inc: DynamicTable


