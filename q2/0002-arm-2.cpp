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

    double startT,endT;
    struct timestamp tmpTmS;
    tmpTmS.year=data[i].startCall.year;
    tmpTmS.month=data[i].startCall.month;
    tmpTmS.date=data[i].startCall.date;
    tmpTmS.hour=17;
    tmpTmS.min=0;
    tmpTmS.sec=0;

    struct timestamp tmpTmE;
    tmpTmE.year=data[i].startCall.year;
    tmpTmE.month=data[i].startCall.month;
    tmpTmE.date=data[i].startCall.date;
    tmpTmE.hour=22;
    tmpTmE.min=0;
    tmpTmE.sec=0;
    if(toTimestamp(data[i].startCall)>toTimestamp(tmpTmS)){
      startT=toTimestamp(tmpTmS);
    }
    if(toTimestamp(data[i].endCall)<toTimestamp(tmpTmE)){
      endT=toTimestamp(tmpTmE);
    }

    data[i].secUse+=endT-startT;
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
