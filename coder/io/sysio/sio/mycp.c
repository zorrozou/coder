#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM 4096

int main(int argc, char *argv[])
{
	int fd1, fd2;
	ssize_t size, ret;
	char buf[NUM];

	if (argc != 3) {
		fprintf(stderr, "Argument Error!....\n");
		exit(1);
	}

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 < 0) {
		perror("open(read)");
		exit(1);
	}

	fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);
	if (fd2 < 0) {
		perror("open(write)");
		exit(1);
	}

	while ((size = read(fd1, buf, NUM)) > 0) {
		ret = write(fd2, buf, size);
		if (ret < 0) {
			perror("write()");
			exit(1);
		}
	}


	close(fd1);
	close(fd2);
	exit(0);
}
