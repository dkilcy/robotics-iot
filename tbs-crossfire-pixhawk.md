
## TBS Crossfire and Pixhawk

### RC Control via MAVLink using TBS Crossfire 8ch Diversity Receiver

1. Configure Receiver for MAVLink TX/RX

CRSF Module Main Menu:

- RX Diversity
  - Output Map
    - Output 7: MAVL. RX
    - Output 8: MAVL. TX
  - RC by MAVLink: On

2. Connect Receiver MAVLink TX/RX to Telemetry port on Pixhawk

Wiring to Receiver:
- TX(out) -> Signal pin of Channel 7 
- RX(in) --> Signal pin of Channel 8
- +5VDC on Channel 8

3. Verify Setup

CRSF Module Status:
- Max Power: 100mw
- Dyn. Power: On
- Op. Mode: Normal
- Bluetooth: MAVLink

### Notes

TBS uses Semtech SX1272

### References0

- [Crossfire and Pixhawk: RC Control (S-Bus, MAVLink) and telemetry options - Painless 360](https://www.youtube.com/watch?v=b55rdaDCKaM)
- [Semtech SX1272 - DigiKey](https://www.digikey.com/en/product-highlight/s/semtech/sx1272-rf-transceiver)
