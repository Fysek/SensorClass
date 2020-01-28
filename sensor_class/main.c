#include "sensor.h"
#include "bme680_sensor.h"
#include "apds9960_sensor.h"
#include "dht11_sensor.h"
#include "ds18b20_sensor.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "MQTTClient.h"

#define ADDRESS     "192.168.12.193"
#define CLIENTID    "lolz"
#define BME680_I2C_ADDR UINT8_C(0x76)

void publish(MQTTClient client, char* topic, char* payload) {
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    pubmsg.payload = payload;
    pubmsg.payloadlen = strlen(pubmsg.payload);
    pubmsg.qos = 2;
    pubmsg.retained = 0;
    MQTTClient_deliveryToken token;
    MQTTClient_publishMessage(client, topic, &pubmsg, &token);
    MQTTClient_waitForCompletion(client, token, 1000L);
    printf("Message '%s' with delivery token %d delivered\n", payload, token);
}

int on_message(void *context, char *topicName, int topicLen, MQTTClient_message *message) {
    char* payload = message->payload;
    printf("Received operation %s\n", payload);
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}


int main(){
    BME680 iBME680(BME680_I2C_ADDR);
    APDS9960 iAPDS9960;
    DHT11 iDHT11;
    DS18B20 iDS18B20;
    Data dataBME680;
    char *outputFile = "log.txt";
    int i=0;
    std::string output;
    
   	iBME680.startConnection();
    iBME680.configure();
    
    /****************/
    MQTTClient client;
    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_setCallbacks(client, NULL, NULL, on_message, NULL);
    
    int rc;
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }
    
    //create device
    publish(client, "BME680", "100,C MQTT,c8y_MQTTDevice");
    //set hardware information
    publish(client, "BME680", "110,S123456789,MQTT test model,Rev0.1");
    //listen for operation
    MQTTClient_subscribe(client, "s/ds", 0);
    
    
    while(1){
      iBME680.measure(5, 1, dataBME680, outputFile);
      output = dataBME680.toString();
      char *cstr = &output[0];
      publish(client, "BME680", "212,24");
      //std::cout<< output << std::endl;
      i++;
    } 
    
    MQTTClient_disconnect(client, 1000);
    MQTTClient_destroy(&client);
    
    
    iBME680.stopConnection();

    return 0;
}
