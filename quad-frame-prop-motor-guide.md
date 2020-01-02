
## Quadcopter Frame/Propeller/Motor Guide

1. Choose Frame Size
2. Determine prop diameter based on frame size
3. Determine motor stator based on prop size
4. Size ESC to handle amps draw at full throttle by motor/prop combo

#### Generic Baseline for Quadcopter

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

Take total weight of vehicle and divide by # of rotors.  This is minimum amount of thrust each motor/prop must make for aircraft to hover @ 50% throttle.

### Propeller

Propellers create lift and propulsion.  

Lift is generated as prop push against the wind.  Lift increases as prop rotates faster.  (Fixed wings rely on airflow above and below wings to generate lift).  

Propulsion is created by varying the rate of rotation of each propeller, the pitch changes.

Properties:
1. Size
2. Pitch.  Example: 4.5 pitch means the prop will move forward 3.8 inches in 1 revolution.  
  - higher pitches produce less torque
  - higher pitches create more vibration

Example: 12x4.5 or 1245  

Blade Count: 2, 3 or 4 blades.  With 3 and 4, do not need to use longer blades.

**How to determine propeller to use:** from frame manufacturer recommendation 

#### Propeller Orientation

For S500 with Pixhawk, motor orientation:
```
                Front
  (3/D) CW/Pusher   (1/A) CCW/Normal
  (2/C) CCW/Normal  (4/B) CW/Pusher
 ```

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

Constant Velocity - K=RPM, V=Per Volt. How many RPM a motor give up per volt.  Ex: 580KV*14.8V=8352RPM

- Larger props paired with low KV motors
- Smaller/lighter props paired with high KV motors.

**For racing:**  high RPM for high speed - High KV motor and small diameter prop  
**For heavy-lift/multirotor:**  low RPM for high torque - Low KV motor and large diameter prop

### ESC

Pair ESC greater than max amp draw of motor

## How to decide propeller and motor size?

Frame Size => Prop Size => Motor Size

"Generally speaking, heavier quad usually pair with medium to low KV motors, lighter quad usually use high KV motors.  
Bigger stator size and higher KV means more current draw.  "

"**Propellers:** Manueverability of a quad is dependent on how quickly you can change the thrust (how fast you can change the RPM 
of the props).  

A smaller prop is easier to speed up and slow down whereas a large prop takes a very long time to change speeds. Beyond a certain size you essentially are unable to fly. This is why you see hexacoptors and octocopters that use more, smaller props instead of giant quadrotors.

On the flipside, propeller efficiency is related to the area of a prop (or radius squared) so a small increase in prop diameter will make the quad vastly more efficient.

The faster you want to go, the more aggressive a pitch you want. Since quadrotors are generally hovering this means you want the lowest pitch available. If you want to go somewhere fast a higher pitch might be apropriate.

**Motors:** Generally you just choose a motor that matches the given prop. Having a motor that is too large will be heavy, and a motor that is too small will perform poorly or burn up.

A smaller prop requires a higher RPM motor because they must spin faster to generate equivalent lift.

If you put everything together, an efficient quad will have properly sized, low RPM motors with very large props.
An acrobatic quad will want smaller, more aggressive props, faster motors, and you might even overvolt the motors for faster response."

### Example Vehicle Performance

Vehicle weight: 1500g (3.3lbs)  

[Racerstart DX3508](https://www.amazon.com/dp/B07B8FLJ14/?coliid=I3JAJLD3BIXDHN&colid=34H1UX4F57WK0&psc=1&ref_=lv_ov_lig_dp_it)  

| Motor | Voltage | Prop | Load Current (A) | Pull (g) | Power (W) |  Efficency (g/W) | Weight (g) |
| - | - | - | - | - | - | - | - |
| DX3508-380KV | 22.2V | 12x3.8 | 10.6 | 1560 | 235 | 6.6 | 98 |
| DX3508-380KV | 22.2V | 15x5 | 13.8 | 1880 | 306 | 6.1 | 98 |
| DX3508-580KV | 14.8V | 12x3.8 | 13.5 | 1360 | 200 | 6.8 | 98 |
| DX3508-580KV | 14.8V | 15x5 | 16.3 | 1600 | 241 | 6.6 | 98 |
| DX3508-700KV | 14.8V | 12x3.8 | 22.6 | 1700 | 334 | 5.1 | 98 |
| DX3508-700KV | 14.8V | 15x5 | 21.8 | 17800 | 323 | 5.5 | 98 |

Thrust-to-weight ratio for 1360g of thrust and 1500g of weight: (1360*4=5440)/1500 = 3.62 

### eCalc

[Test 1](https://ecalc.ch/xcoptercalc_mobile.php?ecalc&lang=en&rotornumber=4&config=flat&frame=400&tiltlimit=90&weight=850&calc=auw&elevation=500&airtemp=25&qnh=1013&chargestate=0&s=3&p=1&battdisc=0.85&esc=0&esccont=&escmax=&escri=&escweight=&motor=0&type=-1&cooling=good&gear=1&propeller=0&pconst=1.2&tconst=1.0&diameter=10&pitch=4.7&blades=2)

### Weight References

| Battery | Voltage | Cells | Discharge Rate | Max Dist Rate | Weight |
| - | - | - | - | - | - |
| Gens ace 5000mAh | 11.1V | 3S | 50C | 100C | 380g |
| Powerhobby 5200mAh | 14.8V | 4S | 50C | 100C | 443g |

### References

- [https://oscarliang.com/quadcopter-motor-propeller/](https://oscarliang.com/quadcopter-motor-propeller/)
- [https://quadquestions.com/blog/2017/02/22/choose-right-size-motors-drone/](https://quadquestions.com/blog/2017/02/22/choose-right-size-motors-drone/)
- [https://www.dronetrest.com/t/how-to-choose-the-right-motor-for-your-multicopter-drone/568](https://www.dronetrest.com/t/how-to-choose-the-right-motor-for-your-multicopter-drone/568)
- [https://robotics.stackexchange.com/questions/25/how-to-choose-the-right-propeller-motor-combination-for-a-quadcopter?rq=1](https://robotics.stackexchange.com/questions/25/how-to-choose-the-right-propeller-motor-combination-for-a-quadcopter?rq=1)
- [https://skilledflyer.com/drone-propellers/](https://skilledflyer.com/drone-propellers/)
- [https://3dinsider.com/drone-propellers/](https://3dinsider.com/drone-propellers/)


