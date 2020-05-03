# dragino-lora

### Setup Arduino IDE Environment

1. Install Arduino IDE [Arduino IDE](https://www.arduino.cc/en/Main/Software)
2. Set permissions

  ```
sudo usermod -a -G tty devops
sudo usermod -a -G dialout devops
```

3. Reboot

### Setup Arduino LMIC Library

1. Install Ardiuno LMIC library [Dragino Arduino LMIC Library](https://github.com/dragino/arduino-lmic)
1. Define the radio type.  Edit `~/Arduino/libraries/arduino-lmic-master/src/lmic/config.h`
  - comment:   `#define CFG_eu868`
  - uncomment: `#define CFG_us915`
  
### Notes

```
route add -net 10.130.1.0/24 gw 10.130.1.1 dev enp2s0

#persistent static routes in /etc/network/interfaces
#up route add -net 10.130.1.0/24 gw 10.130.1.1 dev enp2s0
```

- [adding persistent static routes on ubuntu](http://www.networkinghowtos.com/howto/adding-persistent-static-routes-on-ubuntu/)


### References

