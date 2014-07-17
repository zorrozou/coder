#include "header.h"

int main(int argc, char *argv[])
{
	struct spwd *sp;
	char *password;
	size_t n = 0;

	if (argc != 2) {
		fprintf(stderr, "Error!\n");
		exit(1);
	}

	printf("Password: ");
	if (getline(&password, &n, stdin) <= 0) {
		perror("getline()");
		exit(1);
	}

	password[strlen(password)-1] = '\0';

	errno = 0;
	sp = getspnam(argv[1]);
	if (sp == NULL && errno != 0) {
		perror("getspnam()");
		exit(1);
	}

	if (sp == NULL && errno == 0) {
		fprintf(stderr, "User not exist!\n");
		exit(1);
	}

	if (!strncmp(sp->sp_pwdp, crypt(password, sp->sp_pwdp), strlen(sp->sp_pwdp))) {
		printf("Password is match!\n");
		exit(0);
	} else {
		fprintf(stderr, "Password wrong!\n");
		exit(1);
	}
}
