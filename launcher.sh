#!/bin/sh
# launcher.sh

sleep 60

cd /
cd home/pi
sudo python3 /home/pi/Downloads/bme680cpp_proj/MQTTInfluxDBBridge.py
cd /
