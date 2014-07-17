#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define NUM 1024
#define PATH "/etc/"

int main()
{
	char buf[NUM];

	if (getcwd(buf, NUM) == NULL) {
		perror("getcwd()");
		exit(1);
	}

	printf("current work dir is: %s\n", buf);

	if (chdir(PATH) < 0) {
		perror("chdir()");
		exit(1);
	}
	if (getcwd(buf, NUM) == NULL) {
		perror("getcwd()");
		exit(1);
	}

	printf("current work dir is: %s\n", buf);
	exit(0);
}
