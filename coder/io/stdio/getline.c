#include "header.h"

int main()
{
	char * line;
	size_t n = 0; /************/

	while (1) {
		printf("# ");
//		if (getline(&line, &n , stdin) >= 0) {
		if (getdelim(&line, &n, '\n', stdin) >= 0) {
			printf("%d\n", n);
			line[strlen(line)-1] = '\0';
			puts(line);
		}
	}

	free(line); /* Never be here, but must free! */
	exit(0);
}
