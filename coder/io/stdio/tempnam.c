#include "header.h"

int main()
{
	printf("%s\n", tempnam("/var/tmp", "zorro"));
	printf("%s\n", tmpnam(NULL));
}
