#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	pid_t pid;

	printf("calling fork!\n");
	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}

	if (pid == 0) {
		printf("I'm child!\n");
		printf("My pid is: %d\n", getpid());
		printf("My ppid is: %d\n", getppid());
		execl("/usr/bin/sleep", "zorro", "300", NULL);
		perror("execl()");
		exit(1);
	}

	wait(NULL);

	printf("I'm parent!\n");
	printf("My pid is: %d\n", getpid());
	printf("My ppid is: %d\n", getppid());
	exit(0);
}
