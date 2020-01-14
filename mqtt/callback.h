#ifndef CALLBACK_H
#define CALLBACK_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <atomic>
#include <chrono>
#include <cstring>
#include "../../../paho.mqtt.cpp/src/mqtt/async_client.h"

class callback : public virtual mqtt::callback {
  public:
	  void connection_lost(const std::string& cause) override;
	  void delivery_complete(mqtt::delivery_token_ptr tok) override;

};


#endif