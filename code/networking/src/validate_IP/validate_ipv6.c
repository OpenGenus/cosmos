/* This implementation reads in a file as argv[1] and checks if each line of the file is a valid IPv6 address.
Algorithm of the IPv6 validation is in the char *is_ipv6(char *ip_addr) function.

Implementation utilized inet_pton() and information about that function 
from https://beej.us/guide/bgnet/html/multi/inet_ntopman.html */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

char*
is_ipv6(char *ip_addr);

char*
is_ipv6(char *ip_addr) 
{
	char *ans = "";
	struct sockaddr_in6 sa_6;
	ans = inet_pton(AF_INET6, ip_addr, &(sa_6.sin6_addr)) ? "yes" : "no";
	return ans;
}

int 
main(int argc, char *argv[]) 
{
	ssize_t n;
	char *line = NULL;
	char *ip_addr;
	size_t size = 32;
	FILE *fp;

	const char *filename = argv[1];
	fp = fopen(filename, "r");

	if (!fp) {
		fprintf(stderr, "Error in opening the file!\n");
		exit(1);
	}

	while ((n = getline(&line, &size, fp)) != -1) {
		if (line[n-1] == '\n') {
			line[n-1] = '\0';
			ip_addr = (char *) malloc(n-2);
			strncpy(ip_addr, line, n-2);
		} else {
			ip_addr = (char *) malloc(n);
			strncpy(ip_addr, line, n);
		}
		printf("Is '%s' valid IPv6? \n%s\n", ip_addr, is_ipv6(ip_addr));
	}

	fclose(fp);
	return(0);

}
