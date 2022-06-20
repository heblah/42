# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    arch_postinstall.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 14:08:50 by halvarez          #+#    #+#              #
#    Updated: 2022/06/20 17:13:48 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

#network activation
 systemctl enable NetworkManager
 systemctl restart NetworkManager

#system update
 pacman -Syu --noconfirm

#app install
 pacman -S --noconfirm vim git gdb gcc bluez bluez-utils tlp ntfs-3g
 pacman -S --noconfirm vlc vivaldi vivaldi-ffmpeg-codecs powertop

#bluetooth activation
 systemctl enable bluetooth.service
 systemctl restart bluetooth.service

#power management
 systemctl mask systemd-rfkill.service
 systemctl mask systemd-rfkill.socket
 systemctl enable tlp.service
 systemctl restart tlp.service
 
#if sound not recognized
 pacman -S sof-firmware alsa-ucm-conf

#42 stuff
 git clone git@github.com:heblah/42.git /home/hans/42
 cp home/hans/42/.vimrc home/hans/.
 git clone https://github.com/43Paris/42header.git /home/hans/header
 mkdir -p /home/hans/.vim
 cp -r /home/hans/header/plugin /home/hans/.vim/.
 sudo pacman -S pyhton python-pip
 git clone https://github.com/42School/norminette.git /home/hans/norminette
 python3 -m pip install --upgrade pip setuptools
 python3 -m pip install norminette

#rebooting
 sleep 10 && systemctl reboot
