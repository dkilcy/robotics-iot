
### GPS

### GPS Models

| Model | Compass | Baudrate | Connector | Link | 
| - | - | - | - | - |
| Beitian BN-880 | HMC5883L | 9600 | PicoBlade 1.25mm | https://www.amazon.com/gp/product/B078Y6323W |
| Matek M8Q-5883 | QMC5883L | 9600 | SH 1.0mm | https://www.amazon.com/Matek-Systems-M8Q-5883-GPS-Module/dp/B07KC6QVW9 |

### Wiring

#### Adafruit FTDI Serial TTL-232 USB Cable [ADA70]

Data signals are at 3.3V and the power line provides 5V

| Color | Pin |
| - | - |
| BLACK  | GND |
| BROWN  | CTS |
| RED    | VCC |
| ORANGE | TXD |
| YELLOW | RXD |
| GREEN  | RTS |

Connect: VCC->VCC, GND->GND, RX->TX and TX->RX of GPS

### Software

```
$ lsusb
...
Bus 001 Device 009: ID 0403:6001 Future Technology Devices International, Ltd FT232 USB-Serial (UART) IC
...
```

Software:

- Install minicom: `sudo apt install minicom`
- Run minicom: `minicom -D /dev/ttyUSB0 -b 9600`



