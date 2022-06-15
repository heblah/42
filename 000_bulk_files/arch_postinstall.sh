# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    arch_postinstall.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 14:08:50 by halvarez          #+#    #+#              #
#    Updated: 2022/06/15 16:24:25 by halvarez         ###   ########.fr        #
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

#rebooting
 sleep 10 && systemctl reboot
