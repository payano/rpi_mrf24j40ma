//============================================================================
// Name        : radio_com.cpp
// Author      : Johan Svensson
// Version     :
// Copyright   : Free For All
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "RadioCom.h"

using namespace std;

int main() {
	cout << "Starting program." << endl; // prints Hello!

	RadioCom radioCom;
	radioCom.start();
	return 0;
}
