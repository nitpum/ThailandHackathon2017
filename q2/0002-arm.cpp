#include<stdio.h>
#include<time.h>
#include<map>
#include<algorithm>
using namespace std;
struct timestamp{
  int year,month,date,hour,min,sec;
};
struct customer{
  double caller;
  int promo;
  double ans;
  struct timestamp startCall,endCall;
  double secUse;
};

struct customer data[1000000];

double toTimestamp(struct timestamp a){
  struct tm tm;
  tm.tm_year=a.year;
  tm.tm_mon=a.month;
  tm.tm_mday=a.date;
  tm.tm_hour=a.hour;
  tm.tm_min=a.min;
  tm.tm_sec=a.sec;
  return mktime(&tm);
}

double maxCallStat=0;
double maxCallNum;
map<double,double> callStat;

int main(){
  char str[1000];
  for(int i=0;fgets(str,sizeof(str),stdin)!=NULL;i++){
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

    double tStartC=toTimestamp(data[i].startCall);
    double tEndC=toTimestamp(data[i].endCall);
    struct timestamp tmTmpA,tmTmpB;
    for(int sec=tStartC;sec<=tEndC;sec++){
      time_t t=(time_t)sec;
      struct tm tmA = *localtime(&t);
      tmTmpA.year=tmA.tm_year + 1900;
      tmTmpA.month=tmA.tm_mon + 1;
      tmTmpA.date=tmA.tm_mday;
      tmTmpA.hour=17;
      tmTmpA.min=0;
      tmTmpA.sec=0;

      tmTmpB.year=tmA.tm_year + 1900;
      tmTmpB.month=tmA.tm_mon + 1;
      tmTmpB.date=tmA.tm_mday;
      tmTmpB.hour=22;
      tmTmpB.min=0;
      tmTmpB.sec=0;
      if(sec>=toTimestamp(tmTmpA)&&sec<=toTimestamp(tmTmpB)){
        data[i].secUse+=1;
      }
    }
    //max
    callStat[data[i].caller]+=data[i].secUse;
    if(callStat[data[i].caller]>maxCallStat){
      maxCallStat=callStat[data[i].caller];
      maxCallNum=data[i].caller;
    }
  }
  printf("%010.0lf",maxCallNum);
  return 0;
}
