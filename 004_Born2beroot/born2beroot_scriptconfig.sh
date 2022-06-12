# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    born2beroot_scriptconfig.sh                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 16:25:07 by halvarez          #+#    #+#              #
#    Updated: 2022/06/12 14:53:13 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#born2beroot_autoconfig
#!/bin/sh

#=================================== README ===================================#
#              ---> born2beroot autoconfiguring debian-script <---
# install, set partitions, create root and user with your login during install
# upload the script to your VM with scp command or any method
# log as root and execute
#=============================== mandatory part ===============================#

#variables definition
LOGIN="halvarez"

#exit if an error append
 set -e && trap 'echo "Script ending with error(s)..."' EXIT
#trap 'last_command=$current_command; current_command=$BASH_COMMAND' DEBUG
#trap 'echo "Script ending with error(s)..."' EXIT

#install packages
 echo "Installing packages..."
 apt update
 apt upgrade
 apt install vim
 apt install cron
 apt install openssh-server
 apt install openssh-client
 apt install apparmor
 apt install libpam-pwquality
 apt install sudo
 apt install ufw
 apt install bc

#add user42 as group and LOGIN in user42
 echo "Managing groups..."
 groupadd -f user42
 gpasswd -a ${LOGIN} user42

#hostname config
 echo "Managing hostname..."
 hostnamectl set-hostname ${LOGIN}"42"

#add /usr/sbin to variable environment for all user
 echo "Adding PATH /usr/sbin..."
 echo "export PATH=$PATH:/usr/sbin" > /etc/profile.d/add_sbin.sh

#ssh config
 echo "Configuring ssh..."
 sed -i 's/#Port 22/Port 4242/g' /etc/ssh/sshd_config
 sed -i 's/#PermitRootLogin .*$/PermitROotLogin no\n/g' /etc/ssh/sshd_config

#ufw config
 echo "Configuring ufw..."
 ufw default allow outgoing
 ufw default deny incoming
 ufw allow 4242

#sudo config
 echo "Configuring sudo..."
 usermod -aG sudo ${LOGIN}
 mkdir -p /var/log/sudo && touch /var/log/sudo/sudo.log
 cat << EOF > "/etc/sudoers.d/"${LOGIN}"42_sudoconfig"
  Defaults passwd_tries=3
  Defaults badpass_message="Nice try but wrong password !"
  Defaults logfile="/var/log/sudo/sudo.log"
  Defaults log_input
  Defaults log_output
  Defaults requiretty
EOF

#password policy config
 echo "Setting password policy..."
 sed -i 's/PASS_MAX_DAYS\t99999/PASS_MAX_DAYS\t30/g' /etc/login.defs
 sed -i 's/PASS_MIN_DAYS\t0/PASS_MIN_DAYS\t2/g' /etc/login.defs
 sed -i 's/PASS_WARN_AGE\t7/PASS_WARN_AGE\t7/g' /etc/login.defs
 sed -i 's/# difok = 1/difok = 7/g' /etc/security/pwquality.conf
 sed -i 's/# minlen = 8/minlen = 10/g' /etc/security/pwquality.conf
 sed -i 's/# dcredit = 0/dcredit = -1/g' /etc/security/pwquality.conf
 sed -i 's/# ucredit = 0/ucredit = -1/g' /etc/security/pwquality.conf
 sed -i 's/# maxrepeat = 0/maxrepeat = 3/g' /etc/security/pwquality.conf
 sed -i 's/# usercheck = 1/usercheck = 1/g' /etc/security/pwquality.conf
 sed -i 's/# retry = 3/retry = 3/g' /etc/security/pwquality.conf
 sed -i 's/# enforce_for_root/enforce_for_root/g' /etc/security/pwquality.conf

#apply password policy to root and LOGIN
 echo "Applying password policy to currrent user and root..."
 chage -M 30 root
 chage -M 30 ${LOGIN}
 chage -m 2 root
 chage -m 2 ${LOGIN}
 chage -W 7 root
 chage -W 7 ${LOGIN}

#set monitoring.sh
 echo "Setting monitoring.sh..."
 mkdir -p /monitoring
 cat << EOF > /monitoring/monitoring.sh
 #!/bin/sh
 ARCHITECTURE=\$(uname -srvmo)
 CPU=\$(grep 'physical id' /proc/cpuinfo | uniq | wc -l)
 vCPU=\$(grep processor /proc/cpuinfo | uniq | wc -l)
 VLBRAM=\$(free -h | grep 'Mem:' | awk '{print \$3}')
 TOTRAM=\$(free -h | grep 'Mem:' | awk '{print \$2}')
 PRTRAM=\$(free -h | grep 'Mem:' | awk '{printf("%.2f%%"), \$3 / \$2 * 100}')
 USDDISK=\$(df -h --total | grep total | awk '{print \$3}')
 TOTDISK=\$(df -h --total | grep total | awk '{print \$2}')
 PRTDISK=\$(df -h --total | grep total | awk '{printf("%.2f%%"), \$3 / \$2 * 100}')
 LOAD=\$(top -bn1 | grep '^%Cpu' | awk '{printf("%.1f%%"), \$2 + \$4}')
 LSTBOOT=\$(who -b | awk '{print \$3, \$4}')
 LVM=\$(lsblk | grep 'lvm' | awk 'NR==1{print \$6}' | awk '{if (\$1=="lvm"){print "yes"}else{print "no"}}')
 TCP=\$(grep 'TCP' /proc/net/sockstat | awk '{print \$3}')
 USERS=\$(who | wc -l)
 IP=\$(hostname -I | awk '{print \$1}')
 MAC=\$(ip link show | grep 'link/ether' | awk '{print \$2}')
 SUDO=\$(grep 'COMMAND' /var/log/sudo/sudo.log | wc -l)
 
wall	"
#Architecure		: \${ARCHITECTURE}
#CPU physical		: \${CPU}
#vCPU			: \${vCPU}
#Memory usage		: \${VLBRAM}/\${TOTRAM} (\${PRTRAM})
#CPU load		: \${USDDISK}/\${TOTDISK} (\${PRTDISK})
#Last boot		: \${LSTBOOT}
#LVM use		: \${LVM}
#Connections TCP	: \${TCP}
#Users log		: \${USERS}
#Network		: IP \${IP} (\${MAC})
#Sudo			: \${SUDO}"
EOF
 chmod 755 /monitoring/monitoring.sh

#set sleepdelay
 echo "Setting sleep delay..."
 cat << EOF > /monitoring/sleepdelay.sh
 #!/bin/sh
 BOOT_MIN=\$(uptime -s | cut -d ":" -f 2)
 BOOT_SEC=\$(uptime -s | cut -d ":" -f 3)
 DELAY=\$(bc <<< \${BOOT_MIN}%10*60+\${BOOT_SEC})
 sleep \${DELAY}
EOF
 chmod 755 /monitoring/sleepdelay.sh

#set crontab
 echo "Setting crontab..."
 systemctl enable cron
 cat << EOF > /monitoring/monitoring_crontab
 */10 * * * * bash /monitoring/sleepdelay.sh && bash /monitoring/monitoring.sh
EOF
 crontab -u root /monitoring/monitoring_crontab
 set +e && trap '' EXIT
 echo -e "\n\nMandatory part is set !\n\n"
