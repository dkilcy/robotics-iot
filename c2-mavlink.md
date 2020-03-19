
## Command/Control via MAVLink

### UAVcast-Pro Setup

- Start Gstreamer launcher and Mission Planner.  
- Mission Planner: Select UDP then connect, port 14550.  Starts UDP listening endpoint
- Power up RPI and Pixhawk
- Video and MAVLink telemetry when finished booting

From shell:
```
gst-launch-1.0 -v udpsrc port=5600 caps="application/x-rtp, media=(string)video, clock-rate=(int)90000, encoding-name=(string)H264" ! rtpjitterbuffer ! rtph264depay ! avdec_h264 ! videoconvert ! autovideosink sync=false 
```

### Stream Rates Setup

Arducopter supports so called "telemetry streaming". You can choose from different subsets of telemetry information and how often you want the Flight Controller (FC) to stream that particular set of data per second (defined in Hz). These parameters are the so called SRx_Parameters where x represents the serial port number. In this walk-through we are using Telem1 (aka Serial1) - hence X=1.   

In order not to transmit telemetry data too often over our radio link, we have to select just the necessary data (the right subsets of information) and at the same time find a good compromise on how often this data should be send and thus be updated. The following parameters have to be found working very reliably:   

- SR1_ADSB=5
- SR1_EXT_STAT=2
- SR1_EXTRA1=4
- SR1_EXTRA2=4
- SR1_EXTRA3=2
- SR1_PARAMS=10
- SR1_POSITION=2
- SR1_RAW_CTRL=0
- SR1_RAW_SENS=2
- SR1_RC_CHAN=2

### Resources

#### Open Source

- [Video streaming in QGroundControl](https://dev.px4.io/v1.9.0/en/qgc/video_streaming.html)
- [MAVLink Router - GitHub](https://github.com/intel/mavlink-router)

#### Forums

- [Unlimited range HD streaming with LTE - Ardupilot Blog](https://discuss.ardupilot.org/t/unlimited-range-hd-streaming-with-lte/48670)
- [4G telemetry for Pixhawk - PX4 Autopilot - Flight Controllers](https://discuss.px4.io/t/4g-telemetry-for-pixhawk/1548)
- [Will RC control override Mavlink control?](https://discuss.ardupilot.org/t/will-rc-control-override-mavlink-control/17194)
- [https://github.com/OpenHD/Open.HD/wiki/RC-~-RC-with-Ardupilot](https://github.com/OpenHD/Open.HD/wiki/RC-~-RC-with-Ardupilot)

#### Commercial Software Products 

- [UAVcast-Pro](https://docs.uavmatrix.com/)

#### Commercial Hardware Products

- [Sky Drone FPV 3](https://www.skydrone.aero/collections/frontpage/products/sky-drone-fpv-3)
- [4Gmetry - Volta Robots](http://4gmetry.voltarobots.com/)
