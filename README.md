# Sensor Class
The goal of this project is to create a sensor library in OOP. The process started with UML diagram and list of features to implement. System is based on Raspberry Pi which communicates with sensor, processes data and acts as a MQTT broker. This approach makes it simpler to connect any sensor and use it in IoT application with minimal changes in the code. Measurements are available through MQTT protocol on Grafana, MQTT Dash or any other MQTT client.

## UML Diagram

<img src="https://github.com/Fysek/SensorClass/blob/master/SensorClassUML.PNG" width="800"/>

## Prerequisites

### Application

```sh
sudo apt-get install libmosquitto-dev libmosquittopp-dev libssl-dev
sudo apt-get install wiringpi
```

### Testing
```sh
sudo apt-get install libcppunit-dev
```

## Usage
To run the application, simply execute the command below:
```cmd
cd application/
make
./main
```

To run the unit tests, go to the module with tests/ directory and run make, e.g.:
```cmd
cd sensor_class/tests/
make
./Testmain
```

<!-- CONTACT -->
## Contact

Mateusz Dyrdol - [@Mateusz Dyrdol](https://www.linkedin.com/in/mateusz-dyrdol/) - mateusz.dyrdol@gmail.com

Project Link: [https://github.com/Fysek/SensorClass/](https://github.com/Fysek/SensorClass/)
