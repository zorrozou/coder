#include "header.h"

#define NUM 5

int main()
{
	int i;
	char buf[1024];
	//setvbuf(stdout, NULL, _IONBF, 0);
	for (i=0;i<NUM;i++) {
		fprintf(stdout, "x");
		fflush(stdout);
		sleep(1);
	}
	setvbuf(stdout, buf, _IOLBF, 1024);
	for (i=0;i<NUM;i++) {
		fprintf(stdout, "x");
		sleep(1);
	}
}
