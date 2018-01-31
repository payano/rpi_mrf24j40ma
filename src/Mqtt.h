/*
 * Mqtt.h
 *
 *  Created on: Oct 30, 2017
 *      Author: johan
 */

#pragma once
// #include <mosquittopp.h>
#include "/usr/include/mosquittopp.h"

class Mqtt: public mosqpp::mosquittopp
{
private:
 const char     *     host;
 const char    *     id;
 const char    *     topic;
 int                port;
 int                keepalive;

 void on_connect(int rc);
 void on_disconnect(int rc);
 void on_publish(int mid);
 void on_subscribe(int mid, int qos_count, const int *granted_qos);
 void on_message(const struct mosquitto_message *message);

public:
 void recieve_message();
 Mqtt(const char *id, const char * _topic, const char *host, int port);
 ~Mqtt();
 bool send_message(const char * _message);
};
