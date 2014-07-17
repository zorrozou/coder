#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

static int argc = 0;
static char **argv;

void prompt(void)
{
	printf("$ ");
}

int parse(char *line)
{
	char *tok;
	char *tmpstr;
	int i;

	tmpstr = strdup(line);

	argc = 0;
	for (tok=strtok(tmpstr, " ");tok!=NULL;tok=strtok(NULL, " ")) {
		argc++;
	}

	free(tmpstr);
	argv=(char **)malloc(sizeof(char *)*(argc+1));
	for (i=0,tok=strtok(line, " ");tok!=NULL;tok=strtok(NULL, " "), i++) {
		argv[i]=tok;
	}
	argv[i] = NULL;
	return 0;
}

int main(void)
{
	char *linebuf = NULL;
	size_t buflen = 0;
	ssize_t len;
	int i;
	pid_t pid;

	while (1) {
		prompt();
		len = getline(&linebuf, &buflen, stdin);
		if (len == 1) {
			free(linebuf);
			linebuf = NULL;
			continue;
		}
		if (linebuf[0] == '#') {
			free(linebuf);
			linebuf = NULL;
			continue;
		}

		for (i=0;linebuf[i]!='\0';i++) {
			if (linebuf[i]=='\n') {
				linebuf[i]='\0';
				break;
			}
		}

		parse(linebuf);

		printf("%d args parsed.\n", argc);
		for (i=0;i<argc;i++) {
			printf("argv[%d]=%s\n", i, argv[i]);
		}

		if (strcmp(argv[0], "cd") == 0) {
			chdir(argv[1]);
			free(linebuf);
			continue;
		}
		if (strcmp(argv[0], "exit") == 0) {
			exit(atoi(argv[1]));
		}

		/* External commands */
		pid = fork();
		if (pid < 0) {
			perror("fork()");
			continue;
		}
		if (pid == 0) {
			execvp(argv[0], argv);
			perror("execvp()");
			exit(1);
		}
		wait(NULL);

		free(argv);
		free(linebuf);
		linebuf = NULL;
	}
	exit(0);
}
