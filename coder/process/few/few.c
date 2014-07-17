#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM 8

int main()
{
	pid_t pid[NUM];
	int i;

	for (i=0;i<NUM;i++) {
		pid[i] = fork();
		if (pid[i] < 0) {
			perror("fork()");
			exit(1);
		}

		if (pid[i] == 0) {
			sleep(3*(i+1));
			printf("I'm child!\n");
			printf("My pid is: %d\n", getpid());
			printf("My ppid is: %d\n", getppid());
			exit(0);
		}
	}

	for (i=0;i<NUM;i++) {
		wait(NULL);
	}

	printf("I'm parent!\n");
	printf("My pid is: %d\n", getpid());
	printf("My ppid is: %d\n", getppid());
	exit(0);
}
