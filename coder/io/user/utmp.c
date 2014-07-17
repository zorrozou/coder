#include "header.h"

int main()
{
	struct utmp ut;
	FILE *fp;
	size_t ret;

	fp = fopen("/var/log/wtmp", "r");
	if (fp == NULL) {
		perror("fopen()");
		exit(1);
	}

	while ((ret = fread(&ut, sizeof(ut), 1, fp)) > 0) {
		printf("%d\t", ut.ut_pid);
		printf("%s\t", ut.ut_line);
		printf("%s\t", ut.ut_user);
		printf("%s\n", ut.ut_host);
	}
	if (!feof(fp)) {
		fclose(fp);
		perror("fread()");
		exit(1);
	}

	fclose(fp);
	exit(0);
}
