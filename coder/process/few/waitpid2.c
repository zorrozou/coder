#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void child(void)
{
	printf("pid is: %d\n", getpid());
	sleep(5);
	exit(0);
}

int main()
{
	pid_t pid, ret;
	int status;

	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}

	if (pid == 0) {
		child();
	}

	while ((ret = waitpid(-1, &status, WNOHANG)) == 0) {
		continue;
	}
	if (ret < 0) {
		perror("wait()");
		exit(1);
	}
	printf("wait for pid is: %d\n", ret);
	if (WIFEXITED(status)) {
		printf("child is exited!\n");
	} else if (WIFSIGNALED(status)) {
		printf("child is signaled!\n");
	}
	exit(0);
}
