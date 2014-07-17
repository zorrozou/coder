#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/file.h>

#define START 1010001
#define END 1020000

int main()
{
	int i, j, flag = 0, fd, ret;
	pid_t pid;
	FILE *fp;

	for (i=START;i<END;i+=2) {
		pid = fork();
		if (pid < 0) {
			perror("fork()");
			exit(1);
		}
		if (pid == 0) {
			for (j=2;j<i/2;j++) {
				if (i%j == 0) {
					flag = 0;
					break;
				} else {
					flag = 1;
					continue;
				}
			}

			if (flag == 1) {
				fd = open("/tmp/prime", O_CREAT|O_WRONLY|O_APPEND);
				if (fd < 0) {
					perror("open()");
					exit(1);
				}

				if (flock(fd, LOCK_EX) < 0) {
					perror("flock()");
					exit(1);
				}

				fp = fdopen(fd, "a");
				if (fp == NULL) {
					perror("fdopen()");
					exit(1);
				}
				fprintf(fp, "%d\n", i);

				if (flock(fd, LOCK_UN) < 0) {
					perror("flock(unlock)");
					exit(1);
				}

				close(fd);
				fclose(fp);
			}
			exit(0);
		}
	}

	for (i=START;i<END;i++) {
		wait(NULL);
	}

	exit(0);
}
