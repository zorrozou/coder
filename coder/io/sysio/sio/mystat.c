#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define FILEPATH "/etc/passwd"

int main()
{
	struct stat buf;
	int ret;

	ret = stat(FILEPATH, &buf);
	if (ret<0) {
		perror("stat()");
		exit(1);
	}
	
	printf("st_dev: %d\n", buf.st_dev);
	printf("st_ino: %d\n", buf.st_ino);
	printf("st_mode: %d\n", buf.st_mode);
	printf("st_nlink: %d\n", buf.st_nlink);
	printf("st_uid: %d\n", buf.st_uid);
	printf("st_gid: %d\n", buf.st_gid);
	printf("st_rdev: %d\n", buf.st_rdev);
	printf("st_size: %d\n", buf.st_size);
	printf("st_blksize: %d\n", buf.st_blksize);
	printf("st_blocks: %d\n", buf.st_blocks);
	printf("st_atime: %d\n", buf.st_atime);
	printf("st_mtime: %d\n", buf.st_mtime);
	printf("st_ctime: %d\n", buf.st_ctime);

	exit(0);
}
