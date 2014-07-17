#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define FPATH "/tmp/test"

int main()
{
	int fd;

//	fd = open(FPATH, O_WRONLY|O_CREAT|O_TRUNC, 0644);
	fd = create(FPATH, 0644);
	if (fd < 0) {
		perror("open()");
		exit(1);
	}

	close(fd);
	exit(0);
}
