#include <stdio.h>
#include <time.h>

int main(){
time_t s,val=1;
struct tm* current_time;
s=time(NULL);
current_time=localtime(&s);
printf("%02dH:%02dM:%02dS\t",current_time->tm_hour,current_time->tm_min,current_time->tm_sec);
printf("day:%02d,month:%02d,year:%02d\n",current_time->tm_mday,current_time->tm_mon,(current_time->tm_year)+1900);
return 0;
}

/*
       tm_mday   The day of the month, in the range 1 to 31.

       tm_mon    The number of months since January, in the range 0 to 11.

       tm_year   The number of years since 1900.

       tm_wday   The number of days since Sunday, in the range 0 to 6.

       tm_yday   The number of days since January 1, in the range 0 to 365.

       tm_isdst*/
