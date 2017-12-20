/*
 * Mqtt.h
 *
 *  Created on: Oct 30, 2017
 *      Author: johan
 */

#pragma once
#include <mosquittopp.h>

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
public:
 Mqtt(const char *id, const char * _topic, const char *host, int port);
 ~Mqtt();
 bool send_message(const char * _message);
};
