.. _sec-CardiacSeries-src:

CardiacSeries
^^^^^^^^^^^^^

**Extends:** :ref:`TimeSeries <sec-TimeSeries>`

**Description:** see :numref:`sec-CardiacSeries`

**YAML Specification:**

.. code-block:: yaml
    :linenos:

    datasets:
    - attributes:
      - doc: Default measurement unit of the corresponding cardiac-series.
        dtype: text
        name: unit
      - doc: 'Determine that the columns of data here corresponds to which recording channels.
          By default it is meant to be a one to one map to the recording channels table,
          passed to the ECGRecDevice container. A use case can be like <0: ch_0, 1:ch_2>,
          implying that the data is of two columns and the 0-th and 1-th columns correspond
          to ch_0 and ch_2 of all the recording channels, respectively.'
        dtype: text
        name: which_channels
        value: One to one map with all the channels in ECGRecDevice.
      - doc: 'Global conversion factor for corresponding cardiac-series. See also channel_conversion.
          finally, the stored data-set for each channel will be returned in default unit
          using the scaling as: data-in-default-unit = data * conversion * channel_conversion.'
        dtype: float32
        name: conversion
        value: 1.0
      doc: Associated cardiac-series data. Note that in general, this data could be a
        numerical array,the columns of which corresponding to the recording channels,
        indexed similarly as the rows of the dynamic table passed for the channels argument.
        Notice the difference between electrodes table and the recording channels.
      dtype: numeric
      name: data
    - attributes:
      - doc: Zero-indexed axis of the data that the channel-specific conversion factor
          corresponds to.
        dtype: int32
        name: axis
        value: 1
      doc: 'Conventional NWB channel-specific conversion factor. Default value would be
        1. See also conversion. Finally, the stored data-set for each channel will be
        returned in default unit using the scaling as: data-in-default-unit = data * conversion
        * channel_conversion.'
      dtype: float32
      name: channel_conversion
      quantity: '?'
    doc: A group to store standardized cardiac time-series, e.g., ECG and HeartRate, including
      acquisitions, processed cardiac series or auxiliary analysis.
    links:
    - doc: Link to the ECGRecordingGroup as a reference for recording channels, recording
        electrodes and the recording device.
      name: recording_group
      target_type: ECGRecordingGroup
    neurodata_type_def: CardiacSeries
    neurodata_type_inc: TimeSeries


