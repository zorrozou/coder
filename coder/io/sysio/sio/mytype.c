#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct stat buf;
	int ret;

	if (argc != 2) {
		fprintf(stderr, "Argument error!\n");
		exit(1);
	}

	ret = lstat(argv[1], &buf);
	if (ret<0) {
		perror("stat()");
		exit(1);
	}

	if (S_ISREG(buf.st_mode)) {
		printf("%s is a file!\n", argv[1]);
	} else if (S_ISDIR(buf.st_mode)) {
		printf("%s is a dir!\n", argv[1]);
	} else if (S_ISCHR(buf.st_mode)) {
		printf("%s is a char device!\n", argv[1]);
	} else if (S_ISBLK(buf.st_mode)) {
		printf("%s is a block device!\n", argv[1]);
	} else if (S_ISFIFO(buf.st_mode)) {
		printf("%s is a pipe!\n", argv[1]);
	} else if (S_ISLNK(buf.st_mode)) {
		printf("%s is a slink!\n", argv[1]);
	} else {
		printf("%s is a socket!\n", argv[1]);
	}

	exit(0);
}
