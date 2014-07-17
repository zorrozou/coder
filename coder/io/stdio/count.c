#include "header.h"

int main()
{
	int count;
	FILE *fp;
	char buf[64];

	fp = fopen("/tmp/count", "r+");
	if (fp == NULL) {
		perror("fopen()");
		exit(1);
	}

	while (1) {
		fseek(fp, 0, SEEK_SET);
		fgets(buf, 64, fp);

//		count = atoi(buf);
		sscanf(buf, "%d", &count);
		count++;

		sprintf(buf, "%d", count);

		fseek(fp, 0, SEEK_SET);
		fputs(buf, fp);
		fflush(fp);
		sleep(1);
	}

	fclose(fp);
}
