
# Linux Netwoking

## General


```
route add -net 10.130.1.0/24 gw 10.130.1.1 dev enp2s0

#persistent static routes in /etc/network/interfaces
#up route add -net 10.130.1.0/24 gw 10.130.1.1 dev enp2s0
```

- [adding persistent static routes on ubuntu](http://www.networkinghowtos.com/howto/adding-persistent-static-routes-on-ubuntu/)



## DHCP Server setup on multihomed computers

Install DHCP Server on Ubuntu and configure it to serve addresses for a private subnet on the ethernet interface.  The wireless device continues to be the default route.  

In this setup:
- Private Subnet is 10.0.0.0
- Ethernet device is enp2s0
- Wireless device is wlp4s0, configured to use DHCP from the public router.  Wireless gateway is 10.128.128.128

[https://dedrone.sharepoint.com/sites/TechPortal/knowledgebase/Shared%20Documents/20191009_141610.jpg](https://dedrone.sharepoint.com/sites/TechPortal/knowledgebase/Shared%20Documents/20191009_141610.jpg)


### Install DHCP Server

1. Install DHCP Server: `sudo apt-get install isc-dhcp-server`

### Configure interface

1. Edit /etc/default/isc-dhcp-server and specify the ethernet interface to use:
```
INTERFACES="enp2s0"
```

2. Edit /etc/network/interfaces and set the following configuration for the ethernet device (in this example enp2s0).  The ethernet interface is assigned 10.0.0.1 which becomes the gateway for the private network.  

```
auto enp2s0
iface enp2s0 inet static
address 10.0.0.1
netmask 255.255.255.0
broadcast 10.0.0.255
gateway 10.0.0.1
dns-nameservers 8.8.8.8
```
Reboot the computer for the change to take effect

### Configuring DHCP

1. Edit the /etc/dhcp/dhcpd.conf 

/etc/dhcp/dhcpd.conf
```
ddns-update-style none;
option domain-name "dedrone.local";
default-lease-time 600;
max-lease-time 7200;
authoritative;
log-facility local7;
subnet 10.0.0.0 netmask 255.255.255.0 {
  option subnet-mask 255.255.255.0;
  option broadcast-address 10.0.0.255;
  range 10.0.0.100 10.0.0.200;
  option routers 10.0.0.1;
  option domain-name-servers 8.8.8.8;
  option domain-name "dedrone.local"; 
  option domain-search "dedrone.local";
}
```

2. Restart the service: `sudo systemctl restart isc-dhcp-server`
3. Enable service to start on boot: `sudo systemctl enable isc-dhcp-server`


At this point the sensors on the private network should be able to get an IP address from the DHCP on the server.  However the sensors on the private network will not be able to reach the Internet.  

To allow the sensors to talk to the Internet for VPN, updates, etc., setup NAT as explained below

### Setup NAT

**Run the following as root**

1. Enable packet forwarding in the kernel  
/etc/sysctl.conf
```
net.ipv4.ip_forward=1
net.ipv4.conf.all.forwarding=1
```

1. Install iptables: `apt-get install iptables`
2. Create /etc/iptables.rules
```
# nat Table rules
*nat
:POSTROUTING ACCEPT [0:0]
# Forward traffic from enp2s0 through wlp4s0
-A POSTROUTING -s 10.0.0.0/24 -o wlp4s0 -j MASQUERADE
# don't delete the 'COMMIT' line or these nat table rules won't be processed
COMMIT
```
3. Start iptables: `iptables-restore < /etc/iptables.rules`  
**Note: this needs to be run at every boot** or you can add it to /etc/rc.local.  If added to /etc/rc.local make sure it is executable : `chmod +x /etc/rc.local`

From sensor, test that you can ping 8.8.8.8

4. Check contents of /etc/resolv.conf  
```
domain dedrone.local
search dedrone.local
nameserver 8.8.8.8
```

5. Verify routing

Wireless gateway is 10.128.128.128
Private gateway is 10.0.0.1

```
$ ip route
default via 10.128.128.128 dev wlp4s0  proto static  metric 600 
10.0.0.0/24 dev enp2s0  proto kernel  scope link  src 10.0.0.1 
10.0.0.0/8 dev wlp4s0  proto kernel  scope link  src 10.227.235.157  metric 600

$ ip a
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
    inet6 ::1/128 scope host 
       valid_lft forever preferred_lft forever
2: enp2s0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast state UP group default qlen 1000
    link/ether b0:6e:bf:50:b9:c1 brd ff:ff:ff:ff:ff:ff
    inet 10.0.0.1/24 brd 10.0.0.255 scope global enp2s0
       valid_lft forever preferred_lft forever
    inet6 fe80::b26e:bfff:fe50:b9c1/64 scope link 
       valid_lft forever preferred_lft forever
3: wlp4s0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state UP group default qlen 1000
    link/ether 9c:da:3e:b5:b0:b7 brd ff:ff:ff:ff:ff:ff
    inet 10.227.235.157/8 brd 10.255.255.255 scope global dynamic wlp4s0
       valid_lft 85864sec preferred_lft 85864sec
    inet6 fe80::576e:4308:3c15:91d2/64 scope link 
       valid_lft forever preferred_lft forever

```
