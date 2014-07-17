#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

jmp_buf buf;

int a()
{
	int ret;
	int auto autoval = 1;
	int register regival = 2;
	int volatile volaval = 3;
	static int statval = 4;

	if ((ret = setjmp(buf)) != 0) {
		printf("jump back!\n");
		printf("return value is: %d!\n", ret);
		printf("autoval is: %d!\n", autoval);
		printf("regival is: %d!\n", regival);
		printf("volaval is: %d!\n", volaval);
		printf("statval is: %d!\n", statval);
		return 1;
	}
	autoval = 10;
        regival = 20;
        volaval = 30;
        statval = 40;
	printf("I'm a, calling b()\n");
	b();
	return 1;
}

int b()
{
	printf("I'm b, calling c()\n");
	c();
	return 1;
}

int c()
{
	printf("I'm c, jump!\n");
	longjmp(buf, 5);
	printf("I'm c, return!\n");
	return 1;
}

int main()
{
	printf("I'm main, calling a()\n");
	a();
	exit(0);
}
