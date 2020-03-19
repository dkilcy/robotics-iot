
## LiPo Battery Notes

| Cells | Std Voltage | Max Charge Voltage | Storage Voltage | Max Charge Current |
| - | - | - | - | - |
| 1S | 3.7V | 4.2V | 3.8V | 1C |
| 2S | 7.4V | 8.4V | 7.6V | |
| 3S | 11.1 | 12.6V | 11.4V | |
| 4S | 14.8 | 16.8V | 15.2V | |
| 5S | 18.5 | | | |
| 6S | 22.2 | | | |

- LiPo batteries need to be discharged and stored with cell voltages near nominal, at 3.8v.
- At no time during use, should the voltage drop below 3.0v

### Capacity - How Much Energy the Battery Holds (i.e Fuel Tank)

A battery with a rating of 1000 mAh should be able to provide:

- 1/2 amp for 2 hours
- 1 amp of current, for 1 hour
- 2 amps for 1/2 hour

### C Rating – How Fast the Battery Can Deliver Its Energy (i.e Size of Fuel Line)

C Rating is the Constant Discharge Rate. It tells you how much sustained current the battery can safely provide to the motors or any other device that is being powered.

### Battery Size Calculation

How to determine size battery needed for vehicle.  

1. Find current draw of each motor.  Ex: 15A
2. Calculate total current draw of vehicle.  Ex: 4 motors x 15A = 60A
3. Find LiPo Capacity.  Ex: 2200mAh
4. Find Constant Discharge Rate.  Ex: 25C
5. Multiply Lipo Capacity * Constant Discharge.  Ex: 
  - 2.2A*25C=55A.  For 60A vehicle, not enough.
  - 5.0A*50C=250A.  For 60A vehicle, OK
  
### References

- [https://thercdronehub.com/how-to-charge-discharge-and-store-a-lipo-battery/](https://thercdronehub.com/how-to-charge-discharge-and-store-a-lipo-battery/)

