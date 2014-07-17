#include "header.h"

int main(int argc, char *argv[])
{
	struct spwd *pent;

	if (argc != 2) {
		fprintf(stderr, "Error!\n");
		exit(1);
	}

	errno = 0;
	pent = getspnam(argv[1]);
	if (pent == NULL) {
		if (errno == 0) {
			fprintf(stderr, "User is not exist!\n");
			exit(1);
		}
		perror("getspnam()");
		exit(1);
	}

	printf("Username: %s\n", pent->sp_namp);
	printf("Password: %s\n", pent->sp_pwdp);
	printf("Password last chage time: %ld\n", pent->sp_lstchg);
	printf("Min: %ld\n", pent->sp_min);
	printf("Max: %ld\n", pent->sp_max);
	printf("Warn: %ld\n", pent->sp_warn);
	printf("Inact: %ld\n", pent->sp_inact);
	printf("Expire: %ld\n", pent->sp_expire);
	printf("Reserved: %ld\n", pent->sp_flag);
	
	exit(0);
}
