#include "sensor.h"

int counter = 0;

Sensor::Sensor(){
    counter++;
    m_id = counter;
}

Sensor::~Sensor(){
    counter--;
    m_id = counter;
}

int Sensor::getSensorID(){
    return m_id;
}


