
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

### Resource for DJI Drones

For Mavic, Phantom 4 Pro, Inspire 2 using DJI Assistant 2 1.1.2

Download Links:
- [DUMLdore Firmware Flashing Tool v3](https://github.com/jezzab/DUMLdore)
- [DankDownloader Custom Firmware Download Tool](https://github.com/cs2000/DankDroneDownloader)
- [DJI Assistant 1.1.2](http://www.sekidorc.com/press/DJI_Assistant2_Installer_v1.1.2_20170527.zip)
- [http://dji.polybotes.feralhosting.com/DJI-Firmware/BIN/](http://dji.polybotes.feralhosting.com/DJI-Firmware/BIN/)

### Setup DJI Assistant in Debug Mode

1. Edit C:\Program Files (x86)\DJI Product\DJI Assistant 2\AppFiles\main.js
2. Save the File.
3. Uncomment mainWindow.webContents.openDevTools() around line 113 (delete the // in front of the line)
4. Start DJI Assistant, do NOT connect to aircraft
5. From DevTools window under Resources->Local Storage->file://, enable debug (set debug value to 1)
6. Connect to Aircraft

Open aircraft menu and select Parameters on the left 

### Removing NFZ limits

For Mavic Pro and Phantom 4

Parameters:
- `g_config_airport_limit_cfg_cfg_disable_airport_fly_limit=1`
- `g_config_airport_limit_cfg_cfg_limit_data=20250910`

### Removing height limit

Part 107 requires to fly under 400ft.

Parameters:
- `g_config_flying_limit_height_limit_enabled=2`
- `g_config_flying_limit_limit_height_abs_without_gps=3000`
- `g_config_flying_limit_limit_height_abs=3000`
- `g_config_flying_limit_limit_height_rel=3000`

### References

[DJI_Assistant2_Installer_v1.1.2_20170527.zip](/uploads/a216af418d7bcc81656f05f992c03326/DJI_Assistant2_Installer_v1.1.2_20170527.zip)

#### Phantom 4 Firmware

- Drone Firmware: [V01.03.0509_P4P_dji_system.bin](uploads/a14e62f4e1e294a5a14873e46b523303/V01.03.0509_P4P_dji_system.bin)

#### Mavic Pro Firmware

This is the firmware levels to use on the  drone and controller:

- Drone Firmware: [V01.03.0700_Mavic_dji_system.bin](/uploads/7f95db7ff1238f02aa58c7956ae9e70d/V01.03.0700_Mavic_dji_system.bin)
- RC Firmware: [V01.04.0000_Mavic_dji_system.bin](/uploads/91d9caefc0ce7f26f4c3cbc215372de3/V01.04.0000_Mavic_dji_system.bin)

Drone V01.03.0700 README:
```
COMMUNITY NOTE
This is the last FW version where the following parameters are able to be edited.
“g_config_airport_limit_cfg_cfg_disable_airport_fly_limit”
“g_config_airport_limit_cfg_cfg_limit_data” 
=====================================================================
 What’s New? 
• Added support for DJI Goggles
```

##### Earliest Firmware:

- Mavic Pro Firmware: [V01.03.0200_Mavic_dji_system.bin](/uploads/3b2950b2ed2232847175b385273ef735/V01.03.0200_Mavic_dji_system.bin)
- Mavic Pro Firmware README: [V01.03.0200_Mavic_dji_system.txt](/uploads/d6e4b3ba6e15f9b67b5b7ee1e253eaea/V01.03.0200_Mavic_dji_system.txt)
- Mavic Pro RC Firmware: [V01.03.0200_RC_Mavic_dji_system.bin](/uploads/2aba93b34dd724fb1dbd1d1a2a5f15f1/V01.03.0200_RC_Mavic_dji_system.bin)
- Mavic Pro RC Firmware README: [V01.03.0200_RC_Mavic_dji_system.txt](/uploads/c7d0fa68cce69ba7d3538936d2cbb24b/V01.03.0200_RC_Mavic_dji_system.txt)

Latest Video:
- [New Guide to modifying your DJI Mavic on PC (complete step-by-step latest version 1.04.0300)](https://www.youtube.com/watch?v=OOsTc0HKTCw)

Older Videos:
- [Simple Guide to Modifying Mavic, Phantom 4 Pro, Inspire 2 Flight Paramaters
](https://www.youtube.com/watch?v=H2d784lgtuA)
