#include <stdio.h>
#include <stdlib.h>

#define START 1010001
#define END 1020000

int main()
{
	int i, j, flag = 0;
	pid_t pid;

	for (i=START;i<END;i+=2) {
		pid = fork();
		if (pid < 0) {
			perror("fork()");
			exit(1);
		}
		if (pid == 0) {
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
			exit(0);
		}
	}

	for (i=START;i<END;i++) {
		wait(NULL);
	}

	exit(0);
}
