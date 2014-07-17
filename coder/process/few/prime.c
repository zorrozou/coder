#include <stdio.h>
#include <stdlib.h>

#define START 1010001
#define END 1020000

int main()
{
	int i, j, flag = 0;

	for (i=START;i<END;i+=2) {
		for (j=2;j<i/2;j++) {
			if (i%j == 0) {
				flag = 0;
				break;
			} else {
				flag = 1;
				continue;
			}
		}

		if (flag == 1) {
			printf("%d\n", i);
		}
	}

	exit(0);
}
