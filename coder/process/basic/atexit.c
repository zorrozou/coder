#include "header.h"

void at_exit(void)
{
	printf("process is going to exit!\n");
//	exit(0);
	return;
}

int main()
{
	atexit(at_exit);
	printf("process is running!\n");

//	_exit(0);
	exit(0);
}
