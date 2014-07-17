#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define MODE 0666

int main(int argc, char *argv[])
{
	int ret;
	if (argc != 2) {
		fprintf(stderr, "Error!\n");
		exit(1);
	}

	ret = chmod(argv[1], MODE);
	if (ret < 0) {
		perror("chmod()");
		exit(1);
	}

	exit(0);
}
