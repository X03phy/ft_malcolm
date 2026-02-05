#include "ft_malcolm.h"
#include <signal.h> // signal(), SIGINT
#include <sys/socket.h> // socket(), AF_INET, SOCK_RAW

#include <stdio.h> // printf()
#include <unistd.h> // sleep()


static int g_sig = 1;


int ft_malcolm()
{
	return (0);
}


static void signal_handler()
{
	g_sig = 0;
	printf("yess\n");
}


int main(int argc, char **argv)
{
	int sockfd;

	// if (!parse_input(argc, argv))
	// 	return (1);

	signal(SIGINT, signal_handler);
	while (g_sig) {
		sockfd = socket(AF_INET, SOCK_RAW, 0);
	}

	return (0);
}
