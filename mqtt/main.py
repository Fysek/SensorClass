import paho.mqtt.client as mqtt
import time
import queue
import _thread
import datetime
from data import Data
from matplotlib import pyplot as plt
from plot_data import DataPlot, RealtimePlot
from matplotlib.ticker import FormatStrFormatter
import matplotlib.ticker as mtick

data = Data()
broker = "192.168.12.193"
q_time = queue.Queue()
q_temperature = queue.Queue()
q_humidity = queue.Queue()
q_pressure = queue.Queue()
q_gasResistance = queue.Queue()

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected OK")
    else:
        print("Bad connection, RC: ", rc)


def get_broker_data(broker):
    client = mqtt.Client("python1")
    client.on_connect = on_connect
    print("Connecting to broker: ", broker)
    client.connect(broker)
    client.loop_start()
    client.subscribe("DATETIME", qos=1)
    client.subscribe("BME680 TEMPERATURE", qos=1)
    client.subscribe("BME680 HUMIDITY", qos=1)    
    client.subscribe("BME680 PRESSURE", qos=1)
    client.subscribe("BME680 GAS_RESISTANCE", qos=1)
    client.message_callback_add("DATETIME", on_message_datetime)
    client.message_callback_add("BME680 TEMPERATURE", on_message_from_bme680_temperature)
    client.message_callback_add("BME680 HUMIDITY", on_message_from_bme680_humidity)
    client.message_callback_add("BME680 PRESSURE", on_message_from_bme680_presssure)
    client.message_callback_add("BME680 GAS_RESISTANCE", on_message_from_bme680_gas_resistance)
    while 1:
        time.sleep(3)

    client.loop_stop()
    client.disconnect()


def on_message_datetime(client, userdata, message):
    # print("Message received from BME680: " + message.payload.decode())
    q_time.put(message.payload.decode("utf-8"))


def on_message_from_bme680_temperature(client, userdata, message):
    # print("Message received from BME680: " + message.payload.decode())
    q_temperature.put(message.payload.decode("utf-8"))


def on_message_from_bme680_humidity(client, userdata, message):
    # print("Message received from BME680: " + message.payload.decode())
    q_humidity.put(message.payload.decode("utf-8"))    


def on_message_from_bme680_presssure(client, userdata, message):
    # print("Message received from BME680: " + message.payload.decode())
    q_pressure.put(message.payload.decode("utf-8"))


def on_message_from_bme680_gas_resistance(client, userdata, message):
    # print("Message received from BME680: " + message.payload.decode())
    q_gasResistance.put(message.payload.decode("utf-8"))      


def threadfunction():
    fig1, axes1 = plt.subplots()
    plt.title('Temperature')
    plt.gca().yaxis.set_major_formatter(FormatStrFormatter('%.2f °C'))
    plt.xticks(rotation=90)

    fig2, axes2 = plt.subplots()
    plt.title('Humidity')
    plt.gca().yaxis.set_major_formatter(FormatStrFormatter('%.2f'))
    plt.gca().yaxis.set_major_formatter(mtick.PercentFormatter())
    plt.xticks(rotation=90)

    fig3, axes3 = plt.subplots()
    plt.title('Pressure')
    plt.gca().yaxis.set_major_formatter(FormatStrFormatter('%.2f hPa'))
    plt.xticks(rotation=90)

    fig4, axes4 = plt.subplots()
    plt.title('Gas resistance')
    plt.gca().yaxis.set_major_formatter(FormatStrFormatter('%.2f kOhms'))
    plt.xticks(rotation=90)

    dataToPlot1 = DataPlot()
    dataPlotting1 = RealtimePlot(axes1, "ro-")

    dataToPlot2 = DataPlot()
    dataPlotting2 = RealtimePlot(axes2, "bo-")

    dataToPlot3 = DataPlot()
    dataPlotting3 = RealtimePlot(axes3, "g*-")

    dataToPlot4 = DataPlot()
    dataPlotting4 = RealtimePlot(axes4, "k+-")

    while 1:
        date_time = q_time.get()
        try:
            date_time = datetime.datetime.strptime(date_time, '%Y/%m/%d %H:%M:%S')
        except:
            print("Strange date")
            now = datetime.now()
            date_time = now.strftime('%Y/%m/%d %H:%M:%S')

        temperature = q_temperature.get()
        humidity = q_humidity.get()
        pressure = q_pressure.get()
        gasResistance = q_gasResistance.get()

        dataToPlot1.add(date_time, float(temperature))
        dataPlotting1.plot(dataToPlot1)

        dataToPlot2.add(date_time, float(humidity))
        dataPlotting2.plot(dataToPlot2)

        dataToPlot3.add(date_time, float(pressure))
        dataPlotting3.plot(dataToPlot3)

        dataToPlot4.add(date_time, float(gasResistance))
        dataPlotting4.plot(dataToPlot4)
        plt.pause(1)
        time.sleep(1)


def main():
    _thread.start_new_thread(threadfunction, ())
    get_broker_data(broker)


if __name__ == "__main__": main()
