
## DJI Drones

| Model | Protocol |
| ----- | ----- |
| Phantom 2			| 	Standard Wifi |
| Phantom 3 SE			|	Standard Wifi |
| Phantom 3 Advanced/Pro	|	Lightbridge |
| Inspire 1			|	Lightbridge |
| Phantom 4 Advanced/Pro	|	Lightbridge 2 |
| Inspire 2			|	Lightbridge 2 |
| Mavic Pro			|	OcuSync |
| Mavic Pro Platinum		|	Ocusync |
| Phantom 4 Pro v2.0		|	OcuSync	|
| Mavic 2 Pro & Zoom		|	OcuSync 2.0 |
| Mavic Air			|	Enhanced Wifi |
| Spark            		|	Enhanced Wifi |

- Lightbridge uses 2.4 and 5.8 for the controller
- OcuSync uses 2.4 for the controller and 5.8 for the video
- Enhanced Wifi drones broadcast a DroneID packet


### DroneID

Drone ID is a set of records created by DJI for identifying UAVs.

DJI intends to release drone ID as a public standard, but have preemptively enabled it across much of their hardware line. Through the efforts of several firmware reverse engineers (Freek van Tienen and Jan Dumon), we have the structure of the data being sent; more info is available in Freek’s repository at github

A device with Drone ID enabled broadcasts the serial number, current location, height, horizontal and vertical speeds, pitch, roll, yaw, and the home location of the drone (where it took off from, and where it will return after a go-home command or loss of control.

### OcuSync on non-DJI systems

- https://forum.dji.com/thread-133004-1-1.html
- https://www.kopterworx.com/dji-goggles-racing-edition-ocusync-air-unit-system-set.html

## References

- [DJI Super Patcher](https://github.com/brett8883/DJI_Super-Patcher)
- https://www.dji.com/products/consumer?site=brandsite&from=nav
- https://dronedj.com/2018/07/27/dji-ocusync-vs-lightbridge/
- http://djibestdrones.com/dji-ocusync-2-0/
- https://www.kismetwireless.net/development/droneid/

## DJI Flight Modification

### Force DJI Mavic to fixed channel - prevent frequency hopping

- Click HD.  
- Click Channel Mode: Custom
- Click Image Transmission Settings
- Move the slider to the desired frequencies
