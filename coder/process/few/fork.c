#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	pid_t pid;

	printf("calling fork!\n");
	fflush(stdout); /* !!!!!!!!!! */
	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}

	if (pid == 0) {
		printf("I'm child!\n");
		printf("My pid is: %d\n", getpid());
		printf("My ppid is: %d\n", getppid());
		exit(0);
	}

	wait(NULL);

	printf("I'm parent!\n");
	printf("My pid is: %d\n", getpid());
	printf("My ppid is: %d\n", getppid());
	exit(0);
}
