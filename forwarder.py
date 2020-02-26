import paho.mqtt.client as mqtt
from influxdb import InfluxDBClient
import datetime

def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("home/bme680/temperature");
    client.subscribe("home/bme680/humidity");
    client.subscribe("home/bme680/pressure");
    client.subscribe("home/bme680/gas_resistance");
    client.subscribe("home/bme680/proximity");
    print("Forwarder is running, do not close the application!")
    

def on_message_from_bme680_temperature(client, userdata, msg):
    current_time = datetime.datetime.utcnow().isoformat()
    json_body = [
    {
        "measurement": "temperature",
        "tags": {
            "host": "bme680",
        },
        "time": current_time,
        "fields": {
            "value": float(msg.payload)
        }
    }
    ]
    influx_client.write_points(json_body)


def on_message_from_bme680_humidity(client, userdata, msg):
    current_time = datetime.datetime.utcnow().isoformat()
    json_body = [
    {
        "measurement": "humidity",
        "tags": {
            "host": "bme680",
        },
        "time": current_time,
        "fields": {
            "value": float(msg.payload)
        }
    }
    ]
    influx_client.write_points(json_body) 


def on_message_from_bme680_pressure(client, userdata, msg):
    current_time = datetime.datetime.utcnow().isoformat()
    json_body = [
    {
        "measurement": "pressure",
        "tags": {
            "host": "bme680",
        },
        "time": current_time,
        "fields": {
            "value": float(msg.payload)
        }
    }
    ]
    influx_client.write_points(json_body)


def on_message_from_bme680_gas_resistance(client, userdata, msg):
    current_time = datetime.datetime.utcnow().isoformat()
    json_body = [
    {
        "measurement": "gas_resistance",
        "tags": {
            "host": "bme680",
        },
        "time": current_time,
        "fields": {
            "value": float(msg.payload)
        }
    }
    ]
    influx_client.write_points(json_body)
    
def on_message_from_bme680_proximity(client, userdata, msg):
    current_time = datetime.datetime.utcnow().isoformat()
    json_body = [
    {
        "measurement": "proximity",
        "tags": {
            "host": "bme680",
        },
        "time": current_time,
        "fields": {
            "value": float(msg.payload)
        }
    }
    ]
    influx_client.write_points(json_body)    
    


influx_client = InfluxDBClient('localhost', 8086, database='weather_stations')
client = mqtt.Client("forwarder")
client.on_connect = on_connect
client.message_callback_add("home/bme680/temperature", on_message_from_bme680_temperature)
client.message_callback_add("home/bme680/humidity", on_message_from_bme680_humidity)
client.message_callback_add("home/bme680/pressure", on_message_from_bme680_pressure)
client.message_callback_add("home/bme680/gas_resistance", on_message_from_bme680_gas_resistance)
client.message_callback_add("home/bme680/proximity", on_message_from_bme680_proximity)

client.connect("192.168.12.16", 1883, 60)

client.loop_forever()