
## Motors and Propellers

### Drone Motor and ESC Selection Guide

1. Choose Frame Size
2. Determine prop diameter based on frame size
3. Determine motor stator based on prop size
4. Size ESC to handle amps draw at full throttle by motor/prop combo

#### Generic Guidlines for Quadcopter

|  Frame Size | Prop Size |	Motor Size |	KV |
| - | - | - | - |
| 150mm or smaller |	3″ or smaller | 1105 -1306 or smaller |	3000KV and higher |
| 180mm |	4″ |	1806, 2204 |	2600KV – 3000KV | 
| 210mm |	5″ |	2205-2208, 2305-2306 |	2300KV-2600KV |
| 250mm |	6″ |	2206-2208, 2306 |	2000KV-2300KV |
| 350mm |	7″ |	2506-2508 |	1200KV-1600KV |
| 450mm |	8″, 9″, 10″ or larger |	26XX and larger |	1200KV and lower |

##### Tarot frame data

| Frame | Prop Size |	Motor Size |	KV | Lipo | ESC |
| - | - | - | - | - | - |
| ZD550 | 1238/1245/1255 | 3508 | 700KV | 4S 5200-8000MAH | 30-40A |
| ZD680 | 1555/1655 | 3508,4110 | 380,340 | 6S 5200-100000MAH | 30-40A |

### Frame Size and Weight

- Total weight of vehicle - to determine minimum amount of thrust required for motor/propeller combination to produce
- Frame size - to determine maximum propeller size

### Propeller

From frame manufacturer recommendation 

Example: 12x4.5 or 1245

### Motors

- Brushless - racing and large models (3 wire, requires ESC)
- Brushed - micro and toy (2 wire)

Expressed: AABB/KV

Maximum thrust (in grams) produced by all motors must be at least double the total weight of the vehicle.
- Recommended 3:1 or 4:1 ratio for regular quads
- Higher for racing drones (5:1 up to 13:1)

Higher thrust/weight ratio: creater agility/acceleration but harder to control

#### Motor Stator (Size)

Size of motor: 4-digit number: AABB (both measured in millimeter)
- AA is stator width (stator diameter).   Wider stator = more torque at lower RPM 
- BB is stator height.  Taller stator = more power at higher RPM

More stator volume increase the overall torque of motor so it can spin bigger and heavier propeller

Common stator sizes for 5" propellers: 2207, 2306, 2307, 2407 (racing)

#### Motor KV

Guideline for how many RPM a motor give up per volt.  

- Larger props paired with low KV motors
- Smaller/lighter props paired with high KV motors.

### ESC

## How to decide motor size?

Generally speaking, heavier quad usually pair with medium to low KV motors, lighter quad usually use high KV motors.  
Bigger stator size and higher KV means more current draw.  

Frame Size => Prop Size => Motor Size

### Example Vehicle Performance

Vehicle weight: 1500g (3.3lbs)  

| Motor | Voltage | Prop | Load Current (A) | Pull (g) | Power (W) |  Efficency (g/W) | Weight (g) |
| - | - | - | - | - | - | - | - |
| DX3508-580KV | 14.8V | 12x3.8 | 13.5 | 1360 | 200 | 6.8 | 98 |

Thrust-to-weight ratio: (1360*4=5440)/1500 = 3.62 

### References

- [https://oscarliang.com/quadcopter-motor-propeller/](https://oscarliang.com/quadcopter-motor-propeller/)
- [https://quadquestions.com/blog/2017/02/22/choose-right-size-motors-drone/](https://quadquestions.com/blog/2017/02/22/choose-right-size-motors-drone/)
- [https://www.dronetrest.com/t/how-to-choose-the-right-motor-for-your-multicopter-drone/568](https://www.dronetrest.com/t/how-to-choose-the-right-motor-for-your-multicopter-drone/568)
