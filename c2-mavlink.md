
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

### Resources

#### Open Source

- [Video streaming in QGroundControl](https://dev.px4.io/v1.9.0/en/qgc/video_streaming.html)
- [MAVLink Router - GitHub](https://github.com/intel/mavlink-router)

#### Forums

- [Unlimited range HD streaming with LTE - Ardupilot Blog](https://discuss.ardupilot.org/t/unlimited-range-hd-streaming-with-lte/48670)
- [4G telemetry for Pixhawk - PX4 Autopilot - Flight Controllers](https://discuss.px4.io/t/4g-telemetry-for-pixhawk/1548/7)

#### Commercial Software Products 

- [UAVcast-Pro](https://docs.uavmatrix.com/)

#### Commercial Hardware Products

- [Sky Drone FPV 3](https://www.skydrone.aero/collections/frontpage/products/sky-drone-fpv-3)
- [4Gmetry - Volta Robots](http://4gmetry.voltarobots.com/)
