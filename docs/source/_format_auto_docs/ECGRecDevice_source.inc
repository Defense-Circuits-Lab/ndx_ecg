.. _sec-ECGRecDevice-src:

ECGRecDevice
^^^^^^^^^^^^

**Extends:** :ref:`Device <sec-Device>`

**Description:** see :numref:`sec-ECGRecDevice`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    attributes:
    - doc: Explain analogue frequency filtering of the ECG acquisition device, if any
        is implemented.
      dtype: text
      name: filtering
      required: false
    - doc: Explain the gain settings of the ECG acquisition device.
      dtype: text
      name: gain
      required: false
    - doc: Explain what the baseline of the ECG signal is set to.
      dtype: text
      name: offset
      required: false
    - doc: Explain the synchronization settings if the ECG recording device is separately
        connected to another recording system.
      dtype: text
      name: synchronization
      required: false
    doc: ECG recording device.
    links:
    - doc: endpoint recording device to which the ECG recording device is connected.
      name: endpoint_recording_device
      target_type: Device
    neurodata_type_def: ECGRecDevice
    neurodata_type_inc: Device


