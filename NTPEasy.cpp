/*
 * NTPEasy.cpp
 *
 *  Created on: 5 lis 2018
 *      Author: Lukasz Blaszka
 */

#include "NTPEasy.h"

NTPEasy::NTPEasy()
{
	this->ntpServerAddress = "200.20.186.76";
	this->ntpServerPort = 123;
}

NTPEasy::NTPEasy( std::string ntpServerAddress )
{
	this->ntpServerAddress = ntpServerAddress;
	this->ntpServerPort = 123;
}

NTPEasy::NTPEasy( std::string ntpServerAddress, int ntpServerPort )
{
	this->ntpServerAddress = ntpServerAddress;
	this->ntpServerPort = ntpServerPort;
}

NTPEasy::~NTPEasy() {
	// TODO Auto-generated destructor stub
}


time_t NTPEasy::getNtpServerTime()
{
	unsigned long buf[1024];
	unsigned char msg[48]={010,0,0,0,0,0,0,0,0};
	struct protoent *protocolUDP =getprotobyname("udp");
	int netSocket = socket(PF_INET, SOCK_DGRAM, protocolUDP->p_proto);
	struct sockaddr_in server_addr;

	memset( &server_addr, 0, sizeof( server_addr ));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr = inet_addr( this->ntpServerAddress.c_str() );
	server_addr.sin_port=htons( this->ntpServerPort );

	sendto( netSocket,msg,sizeof(msg),0,(struct sockaddr *)&server_addr,sizeof(server_addr));
	struct sockaddr saddr;
	socklen_t saddr_l = sizeof (saddr);
	recvfrom(netSocket,buf,48,0,&saddr,&saddr_l);
	return ( ntohl((time_t)buf[4]) - 2208988800U);
}
