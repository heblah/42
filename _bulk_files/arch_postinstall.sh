# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    arch_postinstall.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 14:08:50 by halvarez          #+#    #+#              #
#    Updated: 2022/08/10 20:04:32 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
#Execute with root privileges

#system update
 pacman -Syu --noconfirm

#app install
 sudo pacman -S --noconfirm sof-firmware alsa-ucm-conf xf86-video-intel ntfs-3g
 sudo pacman -S --noconfirm vim git gdb gcc valgrind bluez bluez-utils tlp 
 sudo pacman -S --noconfirm pyhton python-pip discord
# pacman -S --noconfirm sway swaylock swayidle swaybg dmenu alacritty

#bluetooth activation
 systemctl enable bluetooth.service
 systemctl restart bluetooth.service

#power management
 systemctl mask systemd-rfkill.service
 systemctl mask systemd-rfkill.socket
 systemctl enable tlp.service
 systemctl restart tlp.service
 
#42 stuff
 git clone git@github.com:heblah/42.git /home/hans/42
 cp home/hans/42/.vimrc home/hans/.
 git clone https://github.com/43Paris/42header.git /home/hans/header
 mkdir -p /home/hans/.vim
 cp -r /home/hans/header/plugin /home/hans/.vim/.
 git clone https://github.com/42School/norminette.git /home/hans/norminette
 python3 -m pip install --upgrade pip setuptools
 python3 -m pip install norminette

#rebooting
 sleep 10 && systemctl reboot
