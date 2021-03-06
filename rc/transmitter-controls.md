
## Transmitter Controls

### Mode 2

- Throttle: Up/Down
- Yaw/Rudder: Which way front is pointing
- Pitch/Elevator: Forward/Backward Tilt
- Roll[Alerion]: Left/Right

```
                Up                                Forward
                 |                                   |
                 |                                   |
(Yaw)  RL <------+------> RR     (Roll)  Left <------+------> Right
[Rudder]         |               [Alerion]           |
                 |                                   |
                Down                              Backward   
                  
               (Throttle)                         (Pitch)
               [Throttle]                         [Elevator]       
```

Transmitter: Taranis X9D SE 2019.  Mode 2, Default Channel Order: AETR

| Inputs | | |
| - | - | - |
| Ail | 100 | Ail |
| Ele | -100 | Ele |
| Thr | 100 | Thr |
| Rud | 100 | Rud |

| Mixer | | |
| - | - | - |
| Ch1 | 100 | Rud --> Yaw |
| Ch2 | 100 | Ele --> Pitch |
| Ch3 | 100 | Thr |
| Ch4 | 100 | Ail --> Roll |

### Ardupilot Setup

For Ardupilot, match params with mixer

| Ardupilot Params | | 
| - | - |
| RCMAP_PITCH | 2 |
| RCMAP_ROLL | 4 |
| RCMAP_THROTTLE | 3 |
| RCMAP_YAW | 1 |

| Flight Modes | |
| - | - |
| 1 | Stabilize |
| 2 | | 
| 3 | |
| 4 | Loiter |
| 5 | |
| 6 | RTL |

### Throttle Curve Settings

Points: 9 

| Pt | X | y |
| - | - | - |
| 1 | -100 | -100 |
| 2 | -75 | -75 |
| 3 | -50 | -50 |
| 4 | -25 | -32 |
| 5 | 0 | -20 |
| 6 | 25 | -12 |
| 7 | 50 | 25 |
| 8 | 75 | 50 |
| 9 | 100 | 100 |

Assign Curve to Throttle Input
