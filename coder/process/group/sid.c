#include <stdio.h>
#include <stdlib.h>

void child(void)
{
	printf("I'm a child! my sid: %d\n", getsid(getpid()));
	printf("my pid is: %d\n", getpid());
	sleep(3);
}

int main()
{
	int i;
	pid_t pid;
	printf("uid: %d\n", getuid());
	printf("gid: %d\n", getgid());
	printf("euid: %d\n", geteuid());
	printf("egid: %d\n", getegid());
	printf("sid: %d\n", getsid(getpid()));
	printf("pid: %d\n", getpid());

	for (i=0;i<4;i++) {
		pid = fork();
		if (pid < 0) {
			perror("fork()");
			exit(1);
		}
		if (pid == 0) {
			child();
			exit(0);
		}
	}

	for (i=0;i<4;i++) {
		wait(NULL);
	}

	if (setsid() < 0) {
		perror("setsid()");
		exit(1);
	}
	
	printf("sid: %d\n", getsid(getpid()));
	printf("pid: %d\n", getpid());
	for (i=0;i<4;i++) {
		pid = fork();
		if (pid < 0) {
			perror("fork()");
			exit(1);
		}
		if (pid == 0) {
			child();
			exit(0);
		}
	}

	for (i=0;i<4;i++) {
		wait(NULL);
	}


}
