#include "dns_lookup.hpp"
#include <iostream>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    std::string input_host;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s HOST...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_host = argv[1];

    cDnsLookup* pDnsLookup = new cDnsLookup(input_host);


    pDnsLookup->lookup_host();


    

    return 0;
}

