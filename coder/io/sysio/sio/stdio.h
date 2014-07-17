#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM 1024
#define HOLE "/tmp/hole"


int main()
{
	int fd;
	ssize_t size, ret;
	char buf[NUM];
	char * str = "hello";

	fd = open(HOLE, O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if (fd < 0) {
		perror("open()");
		exit(1);
	}

	ret = write(fd, str, strlen(str));
	if (ret < 0) {
		perror("write()");
		exit(1);
	}

	ret = lseek(fd, 1024*1024*1024, SEEK_CUR);
	if (ret < 0) {
		perror("lseek()");
		exit(1);
	}
	
	ret = write(fd, str, strlen(str));
	if (ret < 0) {
		perror("write()");
		exit(1);
	}

	close(fd);
	exit(0);
}
