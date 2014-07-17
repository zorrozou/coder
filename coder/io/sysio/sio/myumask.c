#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define FPATH "/tmp/test"

int main()
{
	int fd;
	int ret;

	umask(0002);
	exit(0);
}
