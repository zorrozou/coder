#include <stdio.h>
#include <stdlib.h>

#define START 10100001
#define END 10200000
#define NUM 4

int main()
{
	int i, j, flag = 0;
	int count;
	pid_t pid;

	for (count=0;count<NUM;count++) {
		pid = fork();
		if (pid < 0) {
			perror("fork()");
			exit(1);
		}
		if (pid == 0) {
			for (i=START+count*2;i<END;i+=2*NUM) {
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
			exit(0);
		}
	}

	for (i=0;i<NUM;i++) {
		wait(NULL);
	}

	exit(0);
}
