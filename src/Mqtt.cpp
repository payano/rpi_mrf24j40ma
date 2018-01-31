#include "Mqtt.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

Mqtt::Mqtt(const char * _id,const char * _topic, const char * _host, int _port) : mosqpp::mosquittopp(_id)
{
	mosqpp::lib_init();        // Mandatory initialization for mosquitto library
	this->keepalive = 60;    // Basic configuration setup for Mqtt class
	this->id = _id;
	this->port = _port;
	this->host = _host;
	this->topic = _topic;
	connect_async(host,     // non blocking connection to broker request
			port,
			keepalive);
	loop_start();            // Start thread managing connection / publish / subscribe
};

Mqtt::~Mqtt() {
 loop_stop();            // Kill the thread
 mosqpp::lib_cleanup();    // Mosquitto library cleanup
 }

bool Mqtt::send_message(const  char * _message)
 {
 // Send message - depending on QoS, mosquitto lib managed re-submission this the thread
 //
 // * NULL : Message Id (int *) this allow to latter get status of each message
 // * topic : topic to be used
 // * lenght of the message
 // * message
 // * qos (0,1,2)
 // * retain (boolean) - indicates if message is retained on broker or not
 // Should return MOSQ_ERR_SUCCESS
 int ret = mosquittopp::publish(NULL,this->topic,strlen(_message),_message,1,false);
 return ( ret == MOSQ_ERR_SUCCESS );
 }

void Mqtt::on_disconnect(int rc) {
 std::cout << ">> Mqtt - disconnection(" << rc << ")" << std::endl;
 }

void Mqtt::on_connect(int rc)
 {
 if ( rc == 0 ) {
 std::cout << ">> Mqtt - connected with server" << std::endl;
 } else {
 std::cout << ">> Mqtt - Impossible to connect with server(" << rc << ")" << std::endl;
 }
 }

void Mqtt::recieve_message(){
	int messageId = 0;
	int ret = mosquittopp::subscribe(&messageId,"test1");


}
void Mqtt::on_message(const struct mosquitto_message *message) {

//	struct mosquitto_message{
//		uint16_t mid;
//		char *topic;
//		uint8_t *payload;
//		uint32_t payloadlen;
//		int qos;
//		bool retain;
//	};
	std::cout <<
			"Topic: " << message->topic << ", payload: " <<
			reinterpret_cast<char*>(message->payload) << std::endl;
	return;
}

void Mqtt::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
	std::cout << "mid: " << std::to_string(mid) ;
	return;
}

void Mqtt::on_publish(int mid)
 {
 std::cout << ">> Mqtt - Message (" << mid << ") succeed to be published " << std::endl;
 }
