import paho.mqtt.client as mqtt

broker_port = 1883

client = mqtt.Client()
client.connect('192.168.12.193', broker_port)

client.publish(topic="TestingTopic", payload="TestingPayload", qos=1, retain=False)