#include "header.h"

int main(int argc, char *argv[])
{
	struct passwd *pent;

	if (argc != 2) {
		fprintf(stderr, "Error!\n");
		exit(1);
	}

	errno = 0;
	pent = getpwnam(argv[1]);
	if (pent == NULL) {
		if (errno == 0) {
			fprintf(stderr, "User is not exist!\n");
			exit(1);
		}
		perror("getpwnam()");
		exit(1);
	}

	printf("Username: %s\n", pent->pw_name);
	printf("Uid: %d\n", pent->pw_uid);
	printf("Gid: %d\n", pent->pw_gid);
	printf("Password: %s\n", pent->pw_passwd);
	printf("Comment: %s\n", pent->pw_gecos);
	printf("Dir: %s\n", pent->pw_dir);
	printf("Shell: %s\n", pent->pw_shell);
	
	exit(0);
}
