
## Command/Control via MAVLink

### Mission Planner 

To fix pixelating frames or grey overlay in HUD add 'rtpjitterbuffer'
HUD=>Video=>Set Gstreamer source
```
 udpsrc port=5600 caps = "application/x-rtp, media=video, clock-rate=90000, encoding-name=H264, payload=96" ! rtpjitterbuffer ! rtph264depay ! avdec_h264 ! videoconvert ! video/x-raw,format=BGRA ! appsink name=outsink
 ```

### Resources

#### Open Source

- [Video streaming in QGroundControl](https://dev.px4.io/v1.9.0/en/qgc/video_streaming.html)
- [MAVLink Router - GitHub](https://github.com/intel/mavlink-router]

#### Forums

- [Unlimited range HD streaming with LTE - Ardupilot Blog](https://discuss.ardupilot.org/t/unlimited-range-hd-streaming-with-lte/48670)
- [4G telemetry for Pixhawk - PX4 Autopilot - Flight Controllers](https://discuss.px4.io/t/4g-telemetry-for-pixhawk/1548/7)

#### Commercial Software Products 

- [UAVcast-Pro](https://docs.uavmatrix.com/)

#### Commercial Hardware Products

- [Sky Drone FPV 3](https://www.skydrone.aero/collections/frontpage/products/sky-drone-fpv-3)
- [4Gmetry - Volta Robots](http://4gmetry.voltarobots.com/)
