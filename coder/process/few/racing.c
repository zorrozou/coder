#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#define PATH "/tmp/count"
#define NUM 1000

void child(void)
{
	int ret;
	char buf[BUFSIZ];
	int fd;

	fd = open(PATH, O_RDWR);
	if (fd < 0) {
		perror("open()");
		exit(1);
	}

/********************************/
	ret = read(fd, buf, BUFSIZ);
	if (ret < 0) {
		perror("perror()");
		exit(1);
	}

	printf("ret: %d\n", ret);

	buf[ret]='\0';
	fprintf(stderr, "%s\n", buf);
	lseek(fd, 0, SEEK_SET);
	snprintf(buf, BUFSIZ, "%d", atoi(buf)+1);
	write(fd, buf, strlen(buf));

/******************************/
	close(fd);
}

int main()
{
	int i;
	pid_t pid;
	for (i=0;i<NUM;i++) {
		pid = fork();
		if (pid < 0) {
			perror("fork()");
			exit(1);
		}
		if (pid == 0) {
			child();
			exit(0);
		}
		wait(NULL);
	}	
/*
	for (i=0;i<NUM;i++) {
		wait(NULL);
	}
*/
	exit(0);
}
