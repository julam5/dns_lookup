#ifndef __gcs_receiver_H__
#define __gcs_receiver_H__

#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include <arpa/inet.h>
#include <errno.h>

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>

class cDnsLookup
{

	private:
        std::string hostname;

	public:
		cDnsLookup(std::string host);
		~cDnsLookup();
		void lookup_host();

};

#endif
