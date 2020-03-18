
## UAVCAN with mRO Control Zero F7

### mRo Location One GPS

```
[Quickstart]

On the latest version of mission planner set the following params:

CAN_P1_DRIVER - > 1
CAN_P2 _DRIVER - > 1 (Optional)
GPS_TYPE -> 9 UAVCAN
GPS_TYPE2 -> 9 UAVCAN (Optional)

Then let's make sure the UAVCAN compass driver is not disabled (UAVCAN should be unchecked). If your controller has more than 3 internal compasses, you should disable the least important one:

COMPASS_TYPEMASK->UAVCAN (Unchecked)

Connect your mRo Location One to your controller via CAN and Restart.

NTF_LED_TYPE -> UAVCAN (Only if you want the RGB enabled)

If you want to enable the I2C airspeed, on the autopilot/controller parameters via mission planner set:

ARSP_TYPE -> 8 UAVCAN

Then you must access your mRo Location One CAN parameters, follow those steps:

Mission Planner->Initial Setup->Optional Hardware->UAVCAN-> SLCan Mode CAN1 (or 2) -> Parameters

1 min later inside the CAN Parameters change the following:

ARSP_TYPE -> 4
ARSP_USE -> 1
ARSP_BUS -> 0

Write and restart everything! Enjoy.

*Remember that mRo X2.1 has the CAN signal H and L crossover.

MCU:
STM32F303 ARM Microcontroller
```

### ACSP7 


### References

- [mRo Control Zero F7](https://store.mrobotics.io/mRo-Control-Zero-F7-p/mro-ctrl-zero-f7.htm)
- [mRo Location One GPS](https://store.mrobotics.io/product-p/mro10070.htm)
- [mRo Hall Sens Power module ACSP7 (Next Gen)](https://store.mrobotics.io/product-p/mro-acsp7v10-mr.htm)
- [ACSP7 for Ardupilot](https://drive.google.com/file/d/0B7PUmbXnLA99SGZ0YXYtVWpCZm8/view)
- [Zubax UAVCAN Micro Extender](https://shop.zubax.com/products/uavcan-micro-extender?variant=30177092403299)
- [UAVCAN GUI Tool](https://github.com/UAVCAN/gui_tool)
- [UAVCAN GUI Tool Windows Download](https://files.zubax.com/products/org.uavcan.gui_tool/)
