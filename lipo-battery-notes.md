
## LiPo Battery Notes

All LiPo batteries come with 2 sets of wires/connectors: a balance lead and a main lead or discharge lead (Except for 1S batteries which only have a main lead).

| Cells | Std Voltage | Max Charge Voltage | Storage Voltage | Max Charge Current |
| - | - | - | - | - |
| 1S | 3.7V | 4.2V | 3.8V | 1C |
| 2S | 7.4V | 8.4V | 7.6V | |
| 3S | 11.1 | 12.6V | 11.4V | |
| 4S | 14.8 | 16.8V | 15.2V | |
| 5S | 18.5 | 21.0V | 19.0V | |
| 6S | 22.2 | 25.2V | 22.8V | |  

- LiPo batteries need to be discharged and stored with cell voltages near nominal, at 3.8V.
- Stop discharging battery when cell voltage nears 3.5V
- At no time during use, should the voltage drop below 3.0V
- Never charge battery above cell voltage of 4.2V

### Capacity - How Much Energy the Battery Holds (i.e Fuel Tank)

A battery with a rating of 1000 mAh should be able to provide:

- 1/2 amp for 2 hours
- 1 amp of current, for 1 hour
- 2 amps for 1/2 hour

### C Rating – How Fast the Battery Can Deliver Its Energy (i.e Size of Fuel Line)

C Rating is the Constant Discharge Rate. It tells you how much sustained current the battery can safely provide to the motors or any other device that is being powered.

Some batteries come with two C-ratings: “continuous” and “burst” ratings. The Burst rating is only applicable in short period of time (e.g. 10 seconds).

### Battery Size Calculation

How to determine size battery needed for vehicle.  

1. Find current draw of each motor.  Ex: 15A
2. Calculate total current draw of vehicle.  Ex: 4 motors x 15A = 60A
3. Find LiPo Capacity.  Ex: 2200mAh
4. Find Constant Discharge Rate.  Ex: 25C
5. Multiply Lipo Capacity * Constant Discharge.  Ex: 
  - 2.2A*25C=55A.  For 60A vehicle, not enough.
  - 5.0A*50C=250A.  For 60A vehicle, OK

### Internal Resistance

Internal resistance (IR) can be used to measure how good a LiPo battery is. The lower the value, the better. Higher internal resistance reduces the max current the LiPo can produce, and voltage sag becomes worse. More energy is wasted as heat, and therefore the battery is also more likely to overheat.  

Note the IR as soon as you bought them

### BattGo

All BattGo compatible batteries, chargers and other accessories are using the newer XT60i connectors. In the middle of the XT60i connector you will find an additional data pin, which connects to a third wire in addition to the positive and negative battery wires.

### References

- [https://thercdronehub.com/how-to-charge-discharge-and-store-a-lipo-battery/](https://thercdronehub.com/how-to-charge-discharge-and-store-a-lipo-battery/)
- [WHEN TO RETIRE LIPO BATTERY? CHECK INTERNAL RESISTANCE](https://oscarliang.com/when-retire-lipo-battery/)
- [EVERYTHING ABOUT LIPO BATTERY FOR RACING DRONES](https://oscarliang.com/lipo-battery-guide)
- [BATTGO BATTERY MANAGEMENT TECHNOLOGY](https://oscarliang.com/battgo-battery-management-technology/)
