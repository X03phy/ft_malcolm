#include "ft_malcolm.h"
#include <signal.h> // signal(), SIGINT, 
#include <stdio.h> // printf()
#include <unistd.h> // sleep()


static int g_sig = 0;

int main(int argc, char **argv)
{
	if (!parse_input(argc, argv))
		return (1);

	while (g_sig)
	signal(SIGINT, 0);

	return (0);
}
