#include "header.h"

extern char **environ;

int main()
{
	int i;
	for (i=0;environ[i] != NULL;i++) {
		printf("%s\n", environ[i]);
	}

	exit(0);
}
