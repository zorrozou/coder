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

	fp = fopen("/tmp/item.data", "r");
	if (fp == NULL) {
		perror("fopen()");
		exit(1);
	}

	while (fread(&a, sizeof(struct item), 1, fp) > 0) {
		printf("name: %s\n", a.name);
		printf("math: %d\n", a.math);
		printf("chinese: %d\n", a.chinese);
	}
	if (!feof(fp)) {
		perror("fread()");
		exit(1);
	}

	fclose(fp);
	exit(0);
}
