#include "callback.h"

void  callback::connection_lost(const std::string& cause){
  std::cout << "\nConnection lost" << std::endl;
  if (!cause.empty())
		std::cout << "\tcause: " << cause << std::endl;
}

void callback::delivery_complete(mqtt::delivery_token_ptr tok){
  //std::cout << "\tDelivery complete for token: " << (tok ? tok->get_message_id() : -1) << std::endl;
}


