#!/bin/bash

# This script fixes USB permissions for lejos on LEGO NXT robots

# Get bus and device number(s) from lsusb
BUS=$(lsusb | grep NXT$ | sed 's/.*Bus \([0-9]*\).*/\1/g')
DEVICE=$(lsusb | grep NXT$ | sed 's/.*Device \([0-9]*\).*/\1/g')

echo Bus and Device aquired

# Get the number of NXT entries
NUMLINES=$(echo $BUS | wc -l)

echo $NUMLINES NXT Devices found

# Change permissions on all NXT ports
for i in $(seq 1 $NUMLINES); do
    echo Configuring NXT Device: $i
    sudo chmod a+w /dev/bus/usb/"$(echo $BUS | sed -n "${i}p")"/"$(echo $DEVICE | sed -n "${i}p")"
done;



#EXAMPLE LSUSB
#Bus 001 Device 015: ID 0694:0002 Lego Group Mindstorms NXT
#Bus 001 Device 005: ID 05e3:0608 Genesys Logic, Inc. USB-2.0 4-Port HUB
#Bus 001 Device 006: ID 0bda:5605 Realtek Semiconductor Corp.
#Bus 001 Device 003: ID 0457:1029 Silicon Integrated Systems Corp.
#Bus 001 Device 002: ID 8087:07e6 Intel Corp.
#Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
