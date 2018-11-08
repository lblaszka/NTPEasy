/*
 * NTPEasy.h
 *
 *  Created on: 5 lis 2018
 *      Author: Lukasz Blaszka
 */

#ifndef NTPEASY_H_
#define NTPEASY_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <string.h>
#include <iostream>

class NTPEasy {
public:
	NTPEasy();
	NTPEasy( std::string ntpServerAddress );
	NTPEasy( std::string ntpServerAddress, int ntpServerPort );
	virtual ~NTPEasy();

	time_t getNtpServerTime();


private:
	std::string ntpServerAddress;
	int ntpServerPort;
};

#endif /* NTPEASY_H_ */
