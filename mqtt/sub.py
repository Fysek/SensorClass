import paho.mqtt.client as mqtt
import time

broker = "192.168.12.193"
broker_port = 1883

#broker = "tailor.cloudmqtt.com"
#broker_port = 11553

#broker = "broker.hivemq.com"
#broker_port = 1883

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

client = mqtt.Client("python1")
client.on_connect = on_connect
client.on_log = on_log

print("Connecting to broker: ", broker )

client.username_pw_set("zhepmsyj", "2eqqHKVRbPkO")
client.connect(broker, broker_port)
client.loop_start()

client.subscribe("TestingTopic", qos=1)
client.subscribe("KitchenTopic", qos=1)
client.publish("TestingTopic", "my message")

client.publish("KitchenTopic", "kitchen message")

#client.subscribe("BedroomTopic", qos=1)
#client.message_callback_add("KitchenTopic", on_message_from_kitchen)
#client.message_callback_add("BedroomTopic", on_message_from_bedroom)

#client.loop_forever()
time.sleep(4)
client.loop_stop()
client.disconnect()