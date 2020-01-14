import paho.mqtt.client as mqtt
import time

broker = "192.168.12.193"

def on_log(client, userdata, level, buf):
   print("log: "+buf)

def on_connect(client, userdata, flags, rc):
   if rc==0:
       print("Connected OK")
   else:
       print("Bad connection, RC: ", rc)


def on_message_from_bme680(client, userdata, message):
   print("Message Received from BME680: "+message.payload.decode())

def on_message(client, userdata, message):
   print("Message Received from Others: "+message.payload.decode())


client = mqtt.Client("python1")

client.on_connect = on_connect
# client.on_log = on_log

print("Connecting to broker: ", broker)

client.connect(broker)

client.loop_start()

client.subscribe("BME680", qos=1)

client.message_callback_add("BME680", on_message_from_bme680)
while 1:
    time.sleep(3)

client.loop_stop()

client.disconnect()