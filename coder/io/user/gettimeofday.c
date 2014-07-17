#include "header.h"

int main()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	printf("%d.%d\n", tv.tv_sec, tv.tv_usec);
}
