#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
	struct rlimit rlim;
	if (getrlimit(RLIMIT_CPU, &rlim) < 0) {
		perror("getrlimit()");
		exit(1);
	}

	printf("rlim_cur: %d\n", rlim.rlim_cur);
	printf("rlim_max: %d\n", rlim.rlim_max);

	rlim.rlim_cur = 10;
	rlim.rlim_max = 10;

	if (setrlimit(RLIMIT_CPU, &rlim) < 0) {
		perror("setrlimit()");
		exit(1);
	}

	printf("rlim_cur: %d\n", rlim.rlim_cur);
	printf("rlim_max: %d\n", rlim.rlim_max);
	while (1) {};
}
