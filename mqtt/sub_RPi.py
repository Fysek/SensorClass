import paho.mqtt.client as mqtt
import time

broker = "192.168.12.193"
broker_port = 1883

def on_log(client, userdata, level, buf):
   print("log: "+buf)

def on_connect(client, userdata, flags, rc):
   if rc==0:
      print("Connected OK")
   else:
      print("Bad connection, RC: ", rc)

def on_message_from_kitchen(client, userdata, message):
   print("Message Recieved from Kitchen: "+message.payload.decode())

def on_message_from_bedroom(client, userdata, message):
   print("Message Recieved from Bedroom: "+message.payload.decode())

def on_message(client, userdata, message):
   print("Message Recieved from Others: "+message.payload.decode())

client = mqtt.Client("python_rpi")
client.on_connect = on_connect
client.on_log = on_log

print("Connecting to broker: ", broker )

client.connect(broker)
client.loop_start()

client.subscribe("BME680", qos=1)
client.publish("BME680", "my message")


#client.loop_forever()
time.sleep(4)
client.loop_stop()
client.disconnect()