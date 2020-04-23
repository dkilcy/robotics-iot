
## DragonLink RC Setup

DragonLink recommends using only the Large 1000W Receiver due to high bandwidth utilization and for best telemetry range.

Configuration:
- Taranis transmitter with DragonLink module for RC
- MAVLink with Flow Control Enabled between receiver and flight controller
- Bluetooth MAVLink connection to Mission Planner

### V3 Transmitter


### Receiver


#### Antenna Orientation

1. The top element antenna wire MUST ALWAYS BE MOUNTED VERTICAL
2. The LOWER ( GROUND ) wire element of the antenna can be mounted horizontal on small planes and copters where there is no room to mount the bottom element vertical.

##### Connectors

From top, going left to right:

- Servo:  RSSI, Channels 12 to 1.  Signal, VIN, GND
- CEXP2 - 5-pin GH1.25 connector
- UEXP3 - 6-pin GH1.25 connector
- UEXP1 - 5-pin GH1.25 connector

### Wiring

1. Connect 6-pin straight thru cable between UEXP3 on receiver and Telem2 port on Pixhawk.
2. Power the receiver with 5.0-8.4 VDC to any GRD and VCC pins on the servo connectors.

### DragonLink Transmitter Setup

On the DragonLink Transmitter GUI:
1. Reset to factory settings
2. Set a new Transmit ID
3. Configure the input for SBUS
4. Configure power and alarms
5. Save Settings

Under RF settings: 
1. Select 9X mode.

Under External Connections:
1. Set Baudrate to 57600
2. Set UEXP (Expansion Connector) to "Radio Modem"
3. Set Bluetooth to "Radio Modem" to use Bluetooth, otherwise set to "Dragonlink Mavlink" (????)
4. Save Settings

Reboot transmitter and verify saved settings.

### DragonLink Receiver Setup

On the Dragonlink Receiver GUI:
1. Reset to factory settings
2. configure PPM/S.Bus for 12 channels (as needed). 
3. Configure the PWM/PPM/SBUS/RSSI outputs as desired.
4. Save Settings

Under Radio Modem:
1. Select 57600 baud
2. Click Set Baud
3. Save Settings

Under Receiver Outputs:
1. Configure the UEXP3 pins as: Serial In, Serial Out, CTS, RTS
2. Save Settings

Reboot receiver and verify saved settings.

### Binding

Bind transmitter and receiver.  

Link light will go blue on receiver when connected to the transmitter.  

### Mission Planner Setup

Set parameters for Serial Telem2 port:

```
BRD_SER2_RTSCTS	1
SERIAL2_BAUD	57
SERIAL2_PROTOCOL	1
SR2_EXT_STAT	1			
SR2_EXTRA1	5			
SR2_EXTRA2	5			
SR2_EXTRA3	1			
SR2_PARAMS	10			
SR2_POSITION	3			
SR2_RAW_CTRL	1			
SR2_RAW_SENS	1			
SR2_RC_CHAN	1
```

Under "Config/Tuning"->Planner, set the following:
1. Attitude to 5
2. Position to 3
3. Mode/Status and Sensor to 1
4. RC to 1

```
Power cycle everything. Make sure your PC's bluetooth is paired to your the DL transmitter (you can only do that with the DL receiver powered off).

Launch mission planner.
In the upper-right corner, select the first bluetooth serial port which shows up. Select 57600 baud.
Power on your DLA transmitter.
Power on your plane.
After you see the blue telemetry light show up on the TX, hit "Connect" in mission planner.
It should come right up and work. If it fails right away, select the other bluetooth serial port, power cycle the DL TX and hit connect as soon as you see the blue light.
```

### Bench Test


### References

- [DragonLink - Radio Modem Telemetry](http://www.dragonlinkrc.com/instructions/v3equipment/radiomodem/)
