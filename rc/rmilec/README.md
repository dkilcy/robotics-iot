
## RMILEC NB20 V2 20 Channel UHF LRS System / 4047NB20

Package:
- 1 x R4047NB20 20ch narrow band receiver
- 1 x SRH771 144/430Mhz Wide Band Receiveing Antenna
- 1 x T4047NB20 RF Module with cooling fan
- 1 x Wiring kit

Specs:
- Transmitter input power: 12VDC (11-16VDC)

### Installation

https://www.youtube.com/watch?v=QTbWvJ0o1sY

There should be two quick-release screws.  Remove the screws you can open the FR4 cover.  
You'll find terminal and some pins.  
The pin's instructions are on the back of them. On the right is GND, then 5V output, then SBUS, then PPM2, then PPM1.  
The three pins on the right can directly plug a receiver with SBUS port.  
This is the power supply terminal, and there is a positive and negative sign below.  
The input voltage supports 11-16VDC.  
You will get a power cord that looks like this.  And two servo wires.  
Due to machining problems, there will be a sharp edge, so we use PVC wire.  
If replacing other wires, pay attention to wear resistance.  
Loosen the screw counter clockwise, insert the wire, and then tighten it clockwise.  
This system can relay SBUS signals and PPM signals, so you need an SBUS receiver or a PPM receiver.  
Plug the receiver's output port into three pins on the right side.  
Then put the receiver in the box.  
The antenna can be placed inside or outside, as the cover is made of FR4 material.  
The cover needs to be installed in normal use.  
Don't forget to insall the antenna.  

### Setting Guide

https://www.youtube.com/watch?v=9kM5GU6OBSI

Click SET.  

The first button is **RF PWR SET**.  There are two power options, high power and low power.  The high power mode now shows 5W, which can be changed to another power output, for example, we can choose 2W.  Low power we can choose 0.5W.  The power you set will be displayed on the main page.  We can set any power to high or low mode.  The UI represents the power selection button on the home page. **PWR SEL** is the power control button in the UI.  In **RF PWR SET** RC stands for power control via remote controller.  We can control the power through a channel of FUT.  Now change the power control to RC.  **List** button selects the RC power control channel.  Now we areusing SBUS signals, so we choose the CH in SBUS.  If there is a PPM signal, you can also use a CH in PPM.  Now that SBUS is a valid signal, let's demonstrate through the CH3.  In fact, we can choose any channel for power control.  If CH3 is selected, a corresponding display appears at the top.  Now I can use the throttle to switch the power.  The **PWR SEL** button is now disabled and has a color indicating high or low power. Now control thru the throttle.  If flying in low power mode, the signal is abnormal, you can turn on high power to return back.   

**RF FRQ SET** is the frequency setting.  This system is a frequency hopping system.  The hopping starting and ending frequency will be shown above.  The first default band is the 433 ISM junk band.  The frequency span will be shown above. The other bands are amateur radio bands.  Select these bands as required by local law.  This transmitter can work at a custom frequency.  The starting and ending frequency of hopping can be set completely arbitrarily. There are three options, just like three files.  Now I choose the first file.  The frequency now displayed is the system default.  The system operates at such a wide frequency that we can modify it at will.  **Start, Stop, Center, Span** These 4 numbers are designed for ease of use, like the configuration interface of a spectrum analyzer.  We just need to enter two parameters.  For example the input frequency of 420-450.   Press the Start button.  The current edit number will turn light green.  **Start** Input number 420.  **Stop** Input number 450 .  After pressing the **ENTER** button, the data is calculated and written to the transmitter.  The main page shows the frequency range you just set.   The receiver needs to work after BIND.  Now if we select file 2.  Enter center frequency and SPAN, just for convenience, exactly as if you had entered the start and stop frequency.  Now let's type 425.5 span=1.  If you type SPAN=1, you have to type 0 and then type 1.  If you type 10, you'll type span=10M.  The start frequency and stop frequency are calculated automatically.  The frequency setting is now complete.   

The home page will display the chip temperature and the fan will turn on automatically. 

**Fail safe SET** These two opetions represent FS on or off.  When FS is on, if the RF signal is lost, the receiver will output the range of travel shown below.  If FS is turned off, the receiver will retain the last data received.  I now need to turn off the power control channel.  Now the data for each channel will be displayed.  For example I'm now going to set CH3 current position to the FS mode.  Pressing the **Send F/S Command** button will command the receiver to record the data of all channels.  The control command will now be sent.  After sending the command, the receiver saves the current position of all channels.  When the RF signal is lost, the receiver will output this position data.  

**TX CH Config** button is used to configure each output channel to correspond to the input channel.  The old NB20 required a jumper, but now it can be configured using a touch screen.  It can be configured for any of the output channels.  It is now a SBUS default configuration.  It can be seen from here that the output channel and SBUS channel are one-to-one.  The blue display represents the input signal.  Because SBUS has only 18 channels, channels 19 and 20 use the midpoint signal instead.  If there is a PPM signal now, we can also choose the channel in PPM.  Now lets reconfigure channel 1.  The correspondence will be dispayed at the top.  We chan choose any channel to correspond to CH1.  We can choose channels in PPM or SBUS.  Now we set output channel 1 correponding to input SBUS channel 3.  Now we can see that the output channel 1 is controlled by the throttle.   

**Recver SET** is the receiver setting.  Top button sends the BIND command.  With this command, you need to ensure that all onboard equipment is powered on.  Once the receiver receives the BIND command the receiver will perform a detailed EMI scan.  The receiver transmits EMI analysis data back to the transmitter.  Based on EMI data, the NB20 will choose the best hopping frequency.  If you need to copy an identical receiver, you can select **Send ID & HOP list to receiver**.  You should note that two identical receivers can only operate in the same EMI environment.  If they work in a different environment, the signal will be interfered.  Now the transmitter is transmitting ID number and frequency hopping data.  Now the transmitter does not know the operating environment of the receiver, and there is no data return.   

**DAT Analysis** is the data analysis function.  This functyion is designed to facilitate the installation and debugging of the whole system. This function can display all the input data and output data.  The data sampling of this system is very sophisticated.  We can directly observe what the pulse width of channel 3.  The above data indicate that this pulse width data is a standard FUTABA specification.  **Transmitted data** output data will be shown here.   

**System SET** 

- **VIN Alarm-ON** is the input voltage alarm, the voltage exceeding the working range will trigger thea alarm. 
- **TEMP Alarm-ON** 
- **SYS Sound=ON** 
- **Fan control=AUTO**

**IDLE control=NEVER .. Control CH=SBUS CH19** control the system standby, stop the RF signal transmission.  "When the conditions is met, the system will stop transmitting RF signals!".  

- **PPM1 signal loss** Trigger standby when PPM1 signal is lost. 
- **SBUS signal lost** remote control os turned off and the receiver appears in FS state.  If you turn on the remote now, the NB20 system will continue to work. 
- Bottom two options are to trigger the IDLE function through an arbitrary channel.  The idle function is triggered red when the data meets the condition.  We  can select the control channel here.  

**Screen calibration** is the touch screen calibration, don't use this feature if your screen work normally.

### RF Function and Frequency

https://www.youtube.com/watch?v=RzgM4oTe1go  

Now we will demonstrate the use of the NB20 system.  **RF noise** Background noise is automatically detected when the system is turned on. This noise indicates the noise of the current transmitter environment. Now the noise shows -107dBm. The sensitivity of this system is very high.  -107dBm actually causes some interference to the system.  This actually has a netative effect on remote range. But the effect is small.  If the background noise becomes higher, I suggest changing position or changing other bands.  

This is a test receiver. The transmitter is now working properly. But now the receiver cant receive the signal.   Now the receiver requires a BIND operation.  You need to hold down the BIND button of the receiver.  Then power the receiver.  Before BIND you need to turn on all of your onboard electronics.  Thus the EMI data scanned by the receiver is meaningful. Receiver scanning accuracy is very high, sensitivity is very high, but the speed will be relatively slow.  The receiver has received the scan command and is scanning. When the scan is complete, there will be an indication on the screen.  Now that BIND is complete, the receiver needs to be restarted.     Now the servo is plugged into CH1.  We can see that the servo's motion corresponds to the main page.  

### Input Signal Conversion and PPM Setting

https://www.youtube.com/watch?v=QkY1R1zaVKo

Now lets do something more complicated. If you have multiple receivers, or your signal access is very complex. You need to buy a signal converter. Now I will use this converter to convert the SBUS signal into a PPM.  I will connect the PPM interface to the NB20.  Now I'm going to show you how these wires are connected.  First I connected the servo wire directly to the NB20 and receiver.  Now the SBUS signal for the NB20 system comes from this receiver. Now this SBUS wire is plugged into the signal converter through another wire.  Tih is another servo wire, just to power the signal converter. This white wire is PPM output.  The main page will then show that the status of PPM1 is normal.  Since the FUT is off, the SBUS displays a FS status.  We can see SBUS data and PPM data in the data analysis. PPM is an analog signal, but we can see that their sampling error is very small.  If the signal is inserted into the PPM2, the PPM2 will display the same data. I short-circuted PPM1 and PPM2 with a screwdriver, and you can see their sample data at the same time, and they can work at the same time.  If you have a lot of receivers, you can distribute them.  For example, one receiver corresponds to 1234 channels and the second receiver corresponds to 5678 channels.  

### USB Upgrade

https://www.youtube.com/watch?v=QkY1R1zaVKo

This USB port is for upgrading.  If you want to upgrade the UI, you need to remove the top cover and upgrade through TF card.  The upgrade files need to be downloaded into the TF root directory, inserted into the card slot, and then re-power the system.  When plugged into the computer, the USB port is recognized as a USB flash drive.  But you can only use it on Windows 7 and below.  Win8 and Win10, will produce garbage file after formatting, make system upgrade failure or damaged.  Upgrade operation, only need to copy the upgrade file to the flash drive.   However, writing any other files before writing to the system firmware will cause firmare corruption or upgrade failure.  **If you format the drive under Windows 8 or 10, your system firmware will be damaged directly, even if you don't do any writing** 


### References

- [https://fpvmodel.com/products/rmilec-nb20-v2-20-channel-uhf-lrs-long-range-rc-system](https://fpvmodel.com/products/rmilec-nb20-v2-20-channel-uhf-lrs-long-range-rc-system)
