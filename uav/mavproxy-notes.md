
# MAVProxy

## Connect to vehicle

## SITL Simulator

Tutorial: [Copter SITL/MAVProxy Tutorial](https://ardupilot.org/dev/docs/copter-sitl-mavproxy-tutorial.html)  

- Start SITL with console and map: `cd ~/git/ardupilot/ArduCopter; sim_vehicle.py --console --map`

## Cheat Sheet

### Link
- List all links: `link list`
- Set link n to primary: `set link N`
- Add new link: `link add X`
- Remove link: `link remove N`

### Map
- Show waypoints: `wp list`
- Show fence `fence list`
- Enable geofence `fence enable`
- Disable geofence `fence disable`

### Arming
- Arm Vehicle `arm throttle`
- Disarm Vehicle `disarm`
- Force disarm (heli) `disarm force`

### AUTO Flight
- Set current `wp wp set N`
- Engage auto `mode auto`
- Override auto speed (m/s) `setspeed N`

### Parameters
- Get param value `param show X`
- Set param `param set X N`
- Download param defns `param download`
- Get param help `param help X`

### Flight modes
- Loiter mode `mode loiter`
- Return to Launch `mode rtl`
- Manual mode `mode manual`
- Fly to specific location `mode guided LAT LON ALT`

### Relays
- Set relay `relay set N [0|1]`
- Set output servo `servo set N PWM`

### Terrain
- Get terrain height at location `terrain check LAT LON`

