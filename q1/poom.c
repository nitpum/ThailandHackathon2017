#include <stdio.h>
#include <string.h>
#include <time.h>

char line[1000000][300];

struct timestamp{
  int year,month,date,hour,min,sec;
};
struct customer{
  double caller;
  int promo;
  double ans;
  struct timestamp startCall,endCall;
};

struct tm time;

struct customer data[1000000];

int main () {

    int count = 0;
    while(gets(line[count])) {
        int i = count;
        sscanf(line[count],"%lf,%d,%lf,%d-%d-%d %d:%d:%d,%d-%d-%d %d:%d:%d"
            ,&data[i].caller,&data[i].promo,&data[i].ans
            ,&data[i].startCall.year
            ,&data[i].startCall.month
            ,&data[i].startCall.date
            ,&data[i].startCall.hour
            ,&data[i].startCall.min
            ,&data[i].startCall.sec
            ,&data[i].endCall.year
            ,&data[i].endCall.month
            ,&data[i].endCall.date
            ,&data[i].endCall.hour
            ,&data[i].endCall.min
            ,&data[i].endCall.sec);
        count++;
    }

    strptime("2011-04-01", "%Y-%m-%d", &time);


    //printf("0%10.0lf", data[2].caller);



    return 0;
}

void toTime

int calculateTime () {
    if 
        return mktime(&tmE)-mktime(&tmS);
    else return 
}
