
# MAVProxy

## Connect to vehicle

## SITL Simulator

Tutorial: [Copter SITL/MAVProxy Tutorial](https://ardupilot.org/dev/docs/copter-sitl-mavproxy-tutorial.html)  

- Start SITL with console and map: `cd ~/git/ardupilot/ArduCopter; sim_vehicle.py --console --map`

## Commands

Copter should take off to an altitude of 40 metres and then hover (while it waits for the next command):
```
mode guided
arm throttle
takeoff 40
```

The command below shows how to put Copter into CIRCLE mode with a CIRCLE_RADIUS of 2000cm. This will fly the Copter in a circle at a constant altitude, with the front pointed towards the centre of the circle.
```
mode circle
param set circle_radius 2000
```


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

