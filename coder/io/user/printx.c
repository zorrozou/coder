#include "header.h"

int main()
{
	time_t t;

	t = time(NULL);

	while (time(NULL) < t+5) {
		printf("x");
		fflush(stdout);
	}

	exit(0);
}
