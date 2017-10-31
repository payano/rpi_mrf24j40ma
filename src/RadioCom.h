/*
 * Radiocom.h
 *
 *  Created on: Oct 31, 2017
 *      Author: johan
 */

#pragma once

class RadioCom {
public:
	RadioCom();
	virtual ~RadioCom();
	virtual void start();
	void static start_mqtt();
	void static start_radio();
};
