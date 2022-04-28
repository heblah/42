#!/bin/sh
ls -l | awk '{if (NR%2==1) print $0}'
