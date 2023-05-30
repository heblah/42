#!/bin/sh

#Install packages
sudo dnf install python3-pip vim
sudo dnf config-manager --add-repo https://brave-browser-rpm-release.s3.brave.com/x86_64/
sudo rpm --import https://brave-browser-rpm-release.s3.brave.com/brave-core.asc
sudo dnf install brave-browser

#Create git ssh key
ssh-keygen -t ed25519 -C "hansalvarezherencia@protonmail.com"

#Git config
git config --global user.email "hansalvarezherencia@protonmail.com"
git config --global user.name "Hans Alvarez Herencia"
git config --global color.ui auto

#Clone git repo
git clone git@github.com:heblah/42.git
git clone git@github.com:heblah/hgenerator.git
git clone git@github.com:heblah/mshell.git
git clone git@github.com:heblah/curriculum_vitae.git
git clone git@github.com:heblah/Algorithmie-ressources.git
