CXX = g++

GestureTest: GestureTest.cpp apds9960_rpi.cpp
	$(CXX) -Wall -o GestureTest GestureTest.cpp apds9960_rpi.cpp -lwiringPi

ProximitySensor: ProximitySensor.cpp apds9960_rpi.cpp
	$(CXX) -Wall -o ProximitySensor ProximitySensor.cpp apds9960_rpi.cpp -lwiringPi
	
ColorSensor: ColorSensor.cpp apds9960_rpi.cpp
	$(CXX) -Wall -o ColorSensor ColorSensor.cpp apds9960_rpi.cpp -lwiringPi	

clean:
	rm GestureTest ProximitySensor ColorSensor






