#include "sensor.h"

Sensor::Sensor(){
        counter++;
        _id = counter;
}

Sensor::~Sensor(){
        counter--;
        _id = counter;
}

int Sensor::getSensorID(){
    return _id;
}

int Sensor::counter = 0;
