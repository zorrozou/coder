#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define PATH "/etc/passwd"

int main()
{
	int ret;
	ret = access(PATH, F_OK);
	if (ret < 0) {
		perror("access()");
		exit(1);
	}

	if (ret == 0) {
		printf("%s is exist!\n", PATH);
	} else {
		printf("%s is not found!\n", PATH);
	}
	exit(0);
}
