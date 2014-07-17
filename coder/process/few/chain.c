#include <stdio.h>
#include <stdlib.h>

int level = 5;

int do_child()
{
	pid_t pid;
	level--;
/*************************************/
	printf("pid is: %d\n", getpid());
	printf("ppid is: %d\n", getppid());
/*************************************/
	pid = fork(); 
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}

	if (pid == 0) {
		if (level > 0) {
			do_child();
		}
	}

	wait(NULL);
/*************************************/
	sleep(3);
	printf("%d exit!\n", getpid());
/*************************************/
	exit(1);
}

int main()
{
	printf("pid is: %d\n", getpid());
	sleep(2);
	
	do_child();
	exit(0);
}
