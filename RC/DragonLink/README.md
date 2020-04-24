
# DragonLink RC Setup

Configuration:
- Taranis transmitter with DragonLink module for RC
- MAVLink with Flow Control Enabled between receiver and flight controller
- Bluetooth MAVLink connection to Mission Planner
- Tested with:
  - DragonLink GUI version 3.0.2.6
  - Transmitter firmware version 3.315
  - Receiver firmware 3.302

DragonLink recommends using only the Large 1000W Advanced Receiver due to high bandwidth utilization and for best telemetry range.

**IMPORTANT:** Make sure the antennas are connected to the transmitter and receiver **BEFORE POWERING ON**

## V3 Transmitter Module

Need a Windows computer for this step.

1. Connect the USB from the computer to the transmitter module.  **IMPORTANT:** Make sure the antenna is connected to the transmitter module 
2. Run the DragonLink Config GUI Windows application.  The Home tab with "Welcome to DragonLink" will appear.  Select the TX tab to enter the Transmitter GUI.

### DragonLink Transmitter Setup

On the DragonLink Transmitter GUI, do the following.

From Settings->General Settings:
1. Press the Reset to factory settings button.  A popup will appear that reads "Default ID used".  Click OK
2. Set a new Transmit ID
3. Configure the input for SBUS
4. Configure power and alarms, if desired
5. Click Save Settings at the bottom

From Settings->RF: 
1. Set Speed and Data Range to 9X.
2. Click Save Settings at the bottom

From Settings->External Connections:
1. Set Baudrate to 57600
2. Set Expansion Connector to "Radio Modem"
3. Set Bluetoot and Wifi to "DragonLink Mavlink"
4. `If you want mavlink decoding to "Taranis Telemetry" and have the proper wire connected to the UEXP port, select "Enable Mavlink Decoding" and "Taranis Telemetry" on the expansion connector.` ???
5. Click Save Settings at the bottom

Reboot transmitter and verify saved settings.

## Large Advanced Receiver (V2)

### Antenna Orientation

1. The top element antenna wire MUST ALWAYS BE MOUNTED VERTICAL
2. The LOWER ( GROUND ) wire element of the antenna can be mounted horizontal on small planes and copters where there is no room to mount the bottom element vertical.

### Connectors

From top, going left to right:

- Servo:  RSSI, Channels 12 to 1.  Signal, VIN, GND
- CEXP2 - 5-pin GH1.25 connector
- UEXP3 - 6-pin GH1.25 connector 
- UEXP1 - 5-pin GH1.25 connector

### DragonLink Receiver Setup

Need a Windows computer for this step.

1. Connect the USB from the computer to the receiver.  **IMPORTANT:** Make sure the antenna is connected to the receiver 
2. Run the DragonLink Config GUI Windows application.  The Home tab with "Welcome to DragonLink" will appear.  Select the "AdvancedRX V2" tab to enter the Receiver GUI.

On the DragonLink Transmitter GUI, do the following.

From Settings->General Settings:
1. Press the Reset to factory settings button.  A popup will appear that reads "Default ID used".  Click OK
2. Click Save Settings at the bottom

From Settings->Receiver outputs:
2. Configure PPM/S.Bus for 8 or 12 channels
3. Configure the PWM/PPM/SBUS/RSSI outputs as desired. (???)
4. Click Save Settings at the bottom

From Settings->Radio Modem:
1. Select 57600 baud
2. Click Set Baud
3. `If you plan to use "Taranis Telemetry" mode on the transmitter, enable "Mavlink Decoding". Otherwise you can leave it disabled.`  (???)
4. Click Save Settings at the bottom

From Settings->Receiver outputs:
1. Scroll down and configure the UEXP3 pins as: Serial In, Serial Out, CTS, RTS
2. Click Save Settings at the bottom

Reboot receiver and verify saved settings.

### Model Creation

#### Wiring

1. Ensure the transmitter is powered off.
1. Connect Transmitter Module to external port on Taranis (3 or 4 pin)

#### Model Configuration

1. Create a new Model for desired vehicle
2. Set the following values in the Model Setup Menu:
  - Internal RF Mode: Off
  - External RF:
    - Mode: SBUS
    - Channel Range: CH1-8
    - External RF: SBUS
    - Refresh rate: 7.0ms  normal
  
### Binding

1. Ensure the transmitter and receiver is both powered off. 
2. Hold down the Menu button on the DragonLink transmitter and turn on the power. 
3. After the power-on sound is played, continue to hold the menu button until the LED(s) on the transmitter turn blue accompanied by 2 beeps. 
4. Release the Menu button. 
5. The transmitter will continue to play 2 beeps (if the bind mode alarm is enabled) and the LED(s) will flash blue to indicate it is in binding mode. 
6. Power on the receiver. 
7. The receiver’s blue and green LEDs should both begin flashing to indicate a successful bind. 
8. Power off both the receiver and the transmitter to save the binding. 

Power off both transmitter and receiver and verify both can reconnect.

### Vehicle Wiring

Complete the vehicle wiring.

**IMPORTANT**: Make sure both receiver and flight controller are **POWERED OFF**

On the vehicle:
1. Connect 6-pin straight thru cable between UEXP3 on receiver and Telem2 port on Pixhawk.
2. Power the receiver with 5.0-8.4 VDC to any GRD and VCC pins on the servo connectors.

### Mission Planner Setup

Connect the flight controller to the computer via USB and start Mission Planner.

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


## References

- [DragonLink - Radio Modem Telemetry](http://www.dragonlinkrc.com/instructions/v3equipment/radiomodem/)
- [DragonLink - Downloads](http://www.dragonlinkrc.com/instructions/v3equipment/v3downloads/)
- [DragonLink - Large 1000 mW Receiver](http://www.dragonlinkrc.com/instructions/v3equipment/large1000mwreceiver/)
