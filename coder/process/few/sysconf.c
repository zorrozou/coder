#include <unistd.h>

int main()
{
	printf("%ld\n", sysconf(_SC_CLK_TCK));
	printf("%ld\n", sysconf(_SC_ARG_MAX));
}
