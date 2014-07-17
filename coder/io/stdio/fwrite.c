#include "header.h"

#define NUM 64

struct item {
	char name[64];
	int math;
	int chinese;
};

int main()
{
	struct item a;
	FILE *fp;
	size_t ret;

	strcpy(a.name, "zorro");
	a.math = 99;
	a.chinese = 89;

	fp = fopen("/tmp/item.data", "w+");
	if (fp == NULL) {
		perror("fopen()");
		exit(1);
	}

	ret = fwrite(&a, sizeof(struct item), 1, fp);
	if (ret <= 0) {
		perror("fwrite()");
	}

	fclose(fp);
	exit(0);
}
