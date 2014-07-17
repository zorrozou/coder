#include "header.h"

int a = 10;
int b;

extern char **environ;

int main(int argc, char *argv[])
{
	int *p;	
	int c;
	int d = 10;

	p = (int *)malloc(sizeof(int));
	printf("hello world!\n");
	printf("c: %d\n", c);
	printf("b: %d\n", b);
	printf("address of a is: %p\n", &a);
	printf("address of b is: %p\n", &b);
	printf("address of c is: %p\n", &c);
	printf("address of d is: %p\n", &d);
	printf("address of argv[1] is: %p\n", argv[1]);
	printf("address of argv[2] is: %p\n", argv[2]);
	printf("address of environ is: %p\n", environ);
	printf("address of p is: %p\n", p);
	exit(0);
}
