#include<stdio.h>
#include<time.h>
#include<map>
using namespace std;
struct timestamp
{
    int year,month,date,hour,min,sec;
};
struct customer
{
    double caller;
    int promo;
    double ans;
    struct timestamp startCall,endCall;
    double secUse;
};

struct customer data[1000000];

double toTimestamp(struct timestamp a)
{
    struct tm t;
    t.tm_year=a.year;
    t.tm_mon=a.month;
    t.tm_mday=a.date;
    t.tm_hour=a.hour;
    t.tm_min=a.min;
    t.tm_sec=a.sec;
    return mktime(&t);
}
double maxCallStat=0;
double maxCallNum1,maxCallNum2;
map<double,map<double,int> > callStat;

int main()
{
    char str[1000];
    for(int i=0; fgets(str,sizeof(str),stdin)!=NULL; i++)
    {
        //input data
        sscanf(str,"%lf,%d,%lf,%d-%d-%d %d:%d:%d,%d-%d-%d %d:%d:%d"
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
        //second use each time
        data[i].secUse=toTimestamp(data[i].endCall)-toTimestamp(data[i].startCall);
        //max
        callStat[data[i].caller][data[i].ans]=callStat[data[i].caller][data[i].ans]+callStat[data[i].ans][data[i].caller]+data[i].secUse;
        printf("%lf",toTimestamp(data[i].endCall));
        if(callStat[data[i].caller][data[i].ans]>maxCallStat)
        {
            maxCallStat=callStat[data[i].caller][data[i].ans];
            maxCallNum1=data[i].caller;
            maxCallNum2=data[i].ans;
        }
    }
    if(maxCallNum1>maxCallNum2)
    {
        printf("%010.0lf\n",maxCallNum2);
        printf("%010.0lf\n",maxCallNum1);
    }
    else
    {
        printf("%010.0lf\n",maxCallNum1);
        printf("%010.0lf\n",maxCallNum2);
    }
    int h,m,s;
    h=maxCallStat/3600;
    maxCallStat-=h*3600;
    m=maxCallStat/60;
    maxCallStat-=h*60;
    s=maxCallStat;
    printf("%lf:%lf:%lf",h,m,s);
    return 0;
}
