
## TBS Crossfire and Pixhawk

### RC Control via MAVlink

1. Configure 2 outputs of TBS Crossfire Receiver as Mavlink TX/RX

Output 7: MAVL.RX
Output 8: MAVL. TX

2. Connected to Telemetry port on Pixhawk

Set Channel Order in Mixer:
CH1 100 I Ail
CH2 100 I Ele
CH3 100 I Thr
CH4 100 I Rud
CH5 100 I Mod  Mode
CH6 100 I Aux  Aux

### References

- [Crossfire and Pixhawk: RC Control (S-Bus, MAVLink) and telemetry options - Painless 360](https://www.youtube.com/watch?v=b55rdaDCKaM)
