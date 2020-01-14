#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>	// For sleep
#include <atomic>
#include <chrono>
#include <cstring>
#include "../../../paho.mqtt.cpp/src/mqtt/async_client.h"
#include "callback.h"

const std::string ADDRESS	    { "192.168.12.193" };
const std::string CLIENT_ID		{ "async_publish" };
const std::string TOPIC { "BME680" };
const char* LWT_PAYLOAD = "End of transmission";
const int  QOS = 1;
const auto TIMEOUT = std::chrono::seconds(10);


int main(){

	std::cout << "Initializing for server '" << ADDRESS << "'..." << std::endl;
	mqtt::async_client client(ADDRESS, CLIENT_ID);

	callback cb;
	client.set_callback(cb);

	mqtt::connect_options conopts;
	mqtt::message willmsg(TOPIC, LWT_PAYLOAD, 1, true);
	mqtt::will_options will(willmsg);
	conopts.set_will(will);


	try {
		std::cout << "\nConnecting..." << std::endl;
		mqtt::token_ptr conntok = client.connect(conopts);
		std::cout << "Waiting for the connection..." << std::endl;
		conntok->wait();
		std::cout << "  ...OK" << std::endl;


    while(1){
		  std::cout << "\nSending message..." << std::endl;
      std::string payload = "Temperatura";
		  mqtt::message_ptr pubmsg = mqtt::make_message(TOPIC, payload);
		  pubmsg->set_qos(QOS);
		  client.publish(pubmsg)->wait_for(TIMEOUT);
      std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }

		std::cout << "\nDisconnecting..." << std::endl;
		conntok = client.disconnect();
		conntok->wait();
		std::cout << "  ...OK" << std::endl;
	}
	catch (const mqtt::exception& exc) {
		std::cerr << exc.what() << std::endl;
		return 1;
	}

 	return 0;
}