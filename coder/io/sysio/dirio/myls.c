#include "header.h"

int main(int argc, char *argv[])
{
	DIR * dp;
	struct dirent * dent;

	if (argc != 2) {
		fprintf(stderr, "Error!\n");
		exit(1);
	}

	dp = opendir(argv[1]);
	if (dp == NULL) {
		perror("opendir()");
		exit(1);
	}

	errno = 0;
	while ((dent = readdir(dp)) != NULL) {
		printf("%s\n", dent->d_name);
	}

	if (errno != 0) {
		perror("readdir()");
		closedir(dp);
		exit(1);
	}
	
	closedir(dp);
	exit(0);
}
