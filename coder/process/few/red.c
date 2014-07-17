#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define PATH "/tmp/redirect"

int main()
{
	pid_t pid;
	int fd;
	pid = fork();
	if (pid < 0) {
		perror("fork()");
		exit(1);
	}

	if (pid == 0) {
		fd = open(PATH, O_WRONLY|O_CREAT|O_TRUNC, 0644);
		if (fd < 0) {
			perror("open()");
			exit(1);
		}

		if (dup2(fd, 1) < 0) {
			perror("dup2()");
			exit(1);
		}
		close(fd);

		execl("/bin/ls", "ls", "-l", NULL);
		perror("execl()");
		exit(1);
	}
	wait(NULL);
	exit(0);
}
