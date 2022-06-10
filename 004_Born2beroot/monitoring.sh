 \#!/bin/sh
 ARCHITECTURE= uname -srvmo
 CPU= grep 'physical id' /proc/cpuinfo | uniq | wc -l
 vCPU= grep processor /proc/cpuinfo | uniq | wc -l
 VLBRAM= free -h | grep 'Mem:' |awk '{print $7}'
 TOTRAM= free -h | grep 'Mem:' |awk '{print $2}'
 PRTRAM= free -h | grep 'Mem:' |awk '{printf("%.2f%%"), $7 / $2 * 100}'
 RAM= $VLBRAM"/"$TOTRAM "("$PRTRAM")"
 USDDISK= df -h --total | grep total | awk '{print $3}'
 TOTDISK= df -h --total | grep total | awk '{print $2}'
 PRTFISK= df -h --total | grep total | awk '{printf("%.2f%%"), $3 / $2 * 100}'
 DISK= $USDDISK"/"$TOTDISK "("$PRTDISK")"
 CPU= top -bn1 | grep '^%Cpu' | awk '{printf("%.1f%%"), $2 + $4}'
 LSTBOOT= who -b | awk '{print $3, $4}'
 LVM= lsblk | grep 'lvm' | awk 'NR==1{print $6}' | awk '{if ($1=="lvm"){print "yes"}else{print "no"}}'
 TCP= grep 'TPC' /proc/net/sockstat | awk '{print $3}'
 USERS= who | wc -l
 IP= hostname -I | awk '{print $1}'
 MAC= ip link show | grep 'link/ether' | awk '{print $2}'
 SUDO= grep 'COMMAND' /var/log/sudo/sudo.log | wc -l

wall    "
\#Architecure       : $ARCHITECTURE
\#CPU physical      : $CPU
\#vCPU              : $vCPU
\#Memory usage      : $RAM
\#CPU load          : $CPU
\#Last boot         : $LSTBOOT
\#LVM use           : $LVM
\#Connections TCP   : $TCP
\#Users log         : $USERS
\#Network           : IP $IP "("$MAC")"
\#Sudo              : $SUDO
        "
