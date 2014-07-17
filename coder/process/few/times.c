#include <stdio.h>
#include <sys/times.h>
#include <stdlib.h>

#define START 1010001
#define END 1020000

int main()
{
	int i, j, flag = 0;
	clock_t t;
	struct tms tmsbuf;

	t = times(NULL);

	for (i=START;i<END;i+=2) {
		for (j=2;j<i/2;j++) {
			if (i%j == 0) {
				flag = 0;
				break;
			} else {
				flag = 1;
				continue;
			}
		}

		if (flag == 1) {
			printf("%d\n", i);
		}
	}

	printf("real time: %d\n", times(&tmsbuf)-t);
	printf("user time: %d\n", tmsbuf.tms_utime);
	printf("system time: %d\n", tmsbuf.tms_stime);
	printf("child user time: %d\n", tmsbuf.tms_cutime);
	printf("child system time: %d\n", tmsbuf.tms_cstime);

	exit(0);
}
