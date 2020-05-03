
## EnGenius ENH500 Testing

- Setup a point-to-point link between 2 sites

### Factory Reset

Press and hold the reset button for 30 seconds while it is powered On. After 30 seconds, release the reset button then disconnect the power for 10 seconds.

### Setup a point-to-point link between 2 sites

1. Login to device 1.  Default is admin / admin
2. Select system->Operation Mode.  
    - Set the device name
    - Uncheck Green
    - Set Country to United States
    - Set Operation Mode to **WDS** then **Bridge**
    - Click Save & Apply.   The device reboots
3. Login to the device.
4. Change the password under Management->Administration.  Test the password change.
5. Disable SNMP under Management->Administration
5. System->IP Settings, set the IP address
6. Wireless->WDS Link Settings:
    - Set Security to AES
    - Set the AES Passhprase
    - Under MAC Address select Mode Enable and enter the MAC address of device 2.
7. Wireless->Wireless Network:
    - Set Wireless Mode to 802.11 A/N Mixed
    - Set Channel HT Mode to **40MHz**
    - Set Channel/Frequency to **Ch157-5.785GHz**
    - Click Accept
8. Save the Changes.  Under Status click Save/Reload click Save & Apply.  The device reboots.
9. Repeat for device 2
    - Must use same AES Passphrase, Wireless Mode, Channel HT, Channel/Frequency
10. Check **Link Status** and **RSSI** under Statis->WDS Link List on both devices.

### Speed Tests

- Distance: 10 feet
- Channel/Frequency: Ch157-5.785GHz
```
devops@ws1:~$ iperf -c 192.168.1.10 -i 5 -t 20
------------------------------------------------------------
Client connecting to 192.168.1.10, TCP port 5001
TCP window size: 85.0 KByte (default)
------------------------------------------------------------
[  3] local 192.168.1.5 port 33910 connected with 192.168.1.10 port 5001
[ ID] Interval       Transfer     Bandwidth
[  3]  0.0- 5.0 sec  56.2 MBytes  94.4 Mbits/sec
[  3]  5.0-10.0 sec  56.1 MBytes  94.2 Mbits/sec
[  3] 10.0-15.0 sec  56.1 MBytes  94.2 Mbits/sec
[  3] 15.0-20.0 sec  56.1 MBytes  94.2 Mbits/sec
[  3]  0.0-20.0 sec   225 MBytes  94.2 Mbits/sec
```


### Notes

#### Set static IP and route on Ubuntu

/etc/network/interfaces
```
auto enp2s0
iface enp2s0 inet static
netmask 255.255.255.0
gateway 192.168.1.1
dns-nameservers 192.168.1.1 8.8.8.8
```

```
ip route
sudo ip route add default via 192.168.1.1 dev enp2s0
```

/etc/resolv.conf
```
nameserver 192.168.1.1
```


  
