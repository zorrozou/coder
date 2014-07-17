#include <stdio.h>
#include <string.h>

#define STR "zorro is a good boy"

int main()
{
	char *tok;
	char *tmp = strdup(STR);
	for (tok=strtok(tmp, " ");tok!=NULL;tok=strtok(NULL, " ")) {
		printf("%s\n", tok);
	}
}
