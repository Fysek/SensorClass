#include "sensor.h"

Sensor::Sensor(){
    _counter++;
    _id = _counter;
}

Sensor::~Sensor(){
    _counter--;
    _id = _counter;
}

int Sensor::getSensorID(){
    return _id;
}

int Sensor::_counter = 0;
