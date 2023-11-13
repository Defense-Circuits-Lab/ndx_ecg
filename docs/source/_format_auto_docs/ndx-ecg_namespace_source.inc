**Source Specification:** see :numref:`hdmf-type-namespace-src` 
 
.. _hdmf-type-namespace-src:

ndx-ecg
-------

**Description:** see :numref:`hdmf-type-namespace-doc`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    author:
    - Hamidreza Alimohammadi ([AT]DefenseCircuitsLab)
    contact:
    - alimohammadi.hamidreza@gmail.com
    doc: This extension is developed to extend NWB data standards to incorporate ECG recordings.
    name: ndx-ecg
    schema:
    - namespace: core
      neurodata_types:
      - TimeSeries
      - Device
      - NWBDataInterface
      - LabMetaData
    - namespace: hdmf-common
      neurodata_types:
      - DynamicTable
      - VectorData
    - source: ndx-ecg.extensions.yaml
    version: 0.1.0


