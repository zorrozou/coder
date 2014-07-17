#include "header.h"

int main()
{
	struct passwd *pent;

	errno = 0;
	while ((pent = getpwent()) != NULL) {
		printf("%s:", pent->pw_name);
		printf("%s:", pent->pw_passwd);
		printf("%d:", pent->pw_uid);
		printf("%d:", pent->pw_gid);
		printf("%s:", pent->pw_gecos);
		printf("%s:", pent->pw_dir);
		printf("%s\n", pent->pw_shell);
	}
	if (pent == NULL && errno != 0) {
		perror("getpwent()");
		exit(1);
	}

	exit(0);
}
