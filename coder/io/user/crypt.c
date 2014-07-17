#include "header.h"

int main()
{
	printf("%s\n", crypt("123456", "$6$XXX$"));
}
