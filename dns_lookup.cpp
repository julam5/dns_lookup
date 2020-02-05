
#include "dns_lookup.hpp"

cDnsLookup::cDnsLookup(std::string host = "groundspace.local") {
	hostname = host;

}


cDnsLookup::~cDnsLookup()
{

}

void cDnsLookup::lookup_host()
{
    printf("lookup\n");
    struct addrinfo hints, *res;
    int errcode;
    char addrstr[100];
    void *ptr;

    memset (&hints, 0, sizeof (hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags |= AI_CANONNAME;

    errcode = getaddrinfo (hostname.c_str(), NULL, &hints, &res);
    printf("error code %d\n",errcode);
    if (errcode != 0)
    {
        printf("%s\n",gai_strerror(errcode));
        return;
    }

    printf ("Host: %s\n", hostname.c_str());
    while (res)
    {
        inet_ntop (res->ai_family, res->ai_addr->sa_data, addrstr, 100);

        switch (res->ai_family)
        {
            case AF_INET:
                ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
                break;
            case AF_INET6:
                ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
                break;
        }
        inet_ntop (res->ai_family, ptr, addrstr, 100);
        printf ("IPv%d address: %s (%s)\n", res->ai_family == PF_INET6 ? 6 : 4,
                addrstr, res->ai_canonname);
        res = res->ai_next;
        //galaxy_addr = addrstr;	
        printf("host addr  %s addr str %s\n",hostname.c_str(),addrstr);

    }

    return;
}