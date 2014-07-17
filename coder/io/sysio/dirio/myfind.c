#include "header.h"

//int level = 0;

int max(int a, int b)
{
	return a > b ? a : b;
}

int searchdir(char *dirname, char *filename)
{
	
	DIR * dp;
	struct dirent * dent;
	int ret;
	struct stat buf;

	//printf("%s -> %s\n", dirname, filename);

	if (strcmp(".", dirname) == 0 || strcmp("..", dirname) == 0) {
		return(1);
	}
	if (lstat(dirname, &buf) < 0) {
		perror("lstat()");
		exit(1);
	}
	if (!S_ISDIR(buf.st_mode)) {

		if (strncmp(dirname, filename, max(strlen(dirname), strlen(filename))) == 0) {
			printf("%s/%s\n", get_current_dir_name(),filename);
		}
		return(1);
	}

	dp = opendir(dirname);
	if (dp == NULL) {
		perror("opendir()");
		if (errno == EACCES) {
			return(1);
		}
		exit(1);
	}

	chdir(dirname);

	errno = 0;
	while ((dent = readdir(dp)) != NULL) {
		searchdir(dent->d_name, filename);
	}

	if (errno != 0) {
		perror("readdir()");
		exit(1);
	}

	closedir(dp);
	chdir("..");
	return(1);
}

int main(int argc, char *argv[])
{

	if (argc != 3) {
		fprintf(stderr, "Error!\n");
		exit(1);
	}

	searchdir(argv[1], argv[2]);

	exit(0);
}
