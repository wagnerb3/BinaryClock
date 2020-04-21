#include <stdio.h>
#include <time.h>

int main()
{
	time_t seconds;
	time(&seconds);
	printf("Seconds since 1970: %d\n", seconds);
	struct tm* local = localtime(&seconds);
	printf("Hours = %d\nMinutes = %d\nSeconds = %d\n",local->tm_hour,local->tm_min, local->tm_sec);
	return 0;
}
