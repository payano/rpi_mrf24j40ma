/*
 * Radiocom.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: johan
 */

#include "RadioCom.h"

#include "af_ieee802154.h"
#include "Mqtt.h"
#include <iostream>
#include <thread>
#include <chrono> //clock

RadioCom::RadioCom() {
	// TODO Auto-generated constructor stub

}

RadioCom::~RadioCom() {
	// TODO Auto-generated destructor stub
}

void RadioCom::start(){
	std::cout << "Initiating radio and MQTT." << std::endl;
	std::thread radio(start_radio);
	std::thread mqtt(start_mqtt);
	std::cout << "Initiating done." << std::endl;

	mqtt.join();
	radio.join();


}

void RadioCom::start_mqtt(){
	std::cout << "MQTT starting." << std::endl;
	while(1){
		std::cout << "MQTT running." << std::endl;
		std::this_thread::sleep_for (std::chrono::seconds(1));
	}

}
void RadioCom::start_radio(){
	std::cout << "Radio starting." << std::endl;
	while(1){
		std::cout << "Radio running." << std::endl;
		ieee802154_send();
		std::this_thread::sleep_for (std::chrono::seconds(1));
	}
}
