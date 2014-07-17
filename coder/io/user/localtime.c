#include "header.h"

int main()
{
	struct tm *lt;
	time_t t;
	time(&t);
	lt = localtime(&t);

	printf("sec is %d\n", lt->tm_sec);
	printf("min is %d\n", lt->tm_min);
	printf("hour is %d\n", lt->tm_hour);
	printf("mday is %d\n", lt->tm_mday);
	printf("mon is %d\n", lt->tm_mon);
	printf("year is %d\n", lt->tm_year);
	printf("wday is %d\n", lt->tm_wday);
	printf("yday is %d\n", lt->tm_yday);
	printf("isdst is %d\n", lt->tm_isdst);

	printf("%s\n", asctime(lt));
	printf("%s\n", ctime(&t));

	exit(0);
}
