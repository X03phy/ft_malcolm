#include "ft_malcolm.h"
#include <signal.h> // signal(), SIGINT, 
#include <stdio.h> // printf()
#include <unistd.h> // sleep()


static int g_sig = 1;


static void signal_handler()
{
	g_sig = 0;
}

int main(int argc, char **argv)
{
	if (!parse_input(argc, argv))
		return (1);

	signal(SIGINT, signal_handler);
	while (g_sig) {
		ft_malcolm();
	}

	return (0);
}
