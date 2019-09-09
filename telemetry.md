
# Telemetry

### Serial Comms with SikRadio V1

```
1) Type +++ on terminal and press enter
2) You should see "OK"

The AT commands available are:

ATI - show radio version
ATI2 - show board type
ATI3 - show board frequency
ATI4 - show board version
ATI5 - show all user settable EEPROM parameters
ATI6 - display TDM timing report
ATI7 - display RSSI signal report
ATO - exit AT command mode
ATSn? - display radio parameter number ‘n’
ATSn=X - set radio parameter number ‘n’ to ‘X’
ATZ - reboot the radio
AT&W - write current parameters to EEPROM
AT&F - reset all parameters to factory default
AT&T=RSSI - enable RSSI debug reporting
AT&T=TDM - enable TDM debug reporting
AT&T - disable debug reporting
All of these commands, except for ATO, may be used on a connected remote radio by replacing ‘AT’ with ‘RT’.
```


- [FrSky Telemetry](http://ardupilot.org/copter/docs/common-frsky-telemetry.html)
