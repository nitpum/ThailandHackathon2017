#include<bits/stdc++.h>
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
struct tm tmS,tmE;

double maxCallStat=0;
double maxCallNum;
map<double,double> callStat;
int main(){
  char str[1000];
  for(int i=0;fgets(str,sizeof(str),stdin)!=NULL;i++){
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
    /*printf("%010.0lf,%d,%010.0lf,%04d-%02d-%02d %02d:%02d:%02d,%02d-%02d-%02d %02d:%02d:%02d\n"
    ,data[i].caller,data[i].promo,data[i].ans
    ,data[i].startCall.year
    ,data[i].startCall.month
    ,data[i].startCall.date
    ,data[i].startCall.hour
    ,data[i].startCall.min
    ,data[i].startCall.sec
    ,data[i].endCall.year
    ,data[i].endCall.month
    ,data[i].endCall.date
    ,data[i].endCall.hour
    ,data[i].endCall.min
    ,data[i].endCall.sec);*/
    /*if(data[i].endCall.date!=data[i].startCall.date){
      printf("[%d] %010.0lf,%d,%010.0lf,%04d-%02d-%02d %02d:%02d:%02d,%02d-%02d-%02d %02d:%02d:%02d\n"
      ,i+1,data[i].caller,data[i].promo,data[i].ans
      ,data[i].startCall.year
      ,data[i].startCall.month
      ,data[i].startCall.date
      ,data[i].startCall.hour
      ,data[i].startCall.min
      ,data[i].startCall.sec
      ,data[i].endCall.year
      ,data[i].endCall.month
      ,data[i].endCall.date
      ,data[i].endCall.hour
      ,data[i].endCall.min
      ,data[i].endCall.sec);
    }*/
    tmS.tm_year=data[i].startCall.year;
  	tmS.tm_mon=data[i].startCall.month;
  	tmS.tm_mday=data[i].startCall.date;
  	tmS.tm_hour=data[i].startCall.hour;
  	tmS.tm_min=data[i].startCall.min;
  	tmS.tm_sec=data[i].startCall.sec;

    tmE.tm_year=data[i].endCall.year;
  	tmE.tm_mon=data[i].endCall.month;
  	tmE.tm_mday=data[i].endCall.date;
  	tmE.tm_hour=data[i].endCall.hour;
  	tmE.tm_min=data[i].endCall.min;
  	tmE.tm_sec=data[i].endCall.sec;
    data[i].secUse=mktime(&tmE)-mktime(&tmS);

    callStat[data[i].caller]+=data[i].secUse;
    if(callStat[data[i].caller]>maxCallStat){
      maxCallStat=callStat[data[i].caller];
      maxCallNum=data[i].caller;
    }
  }
  printf("%010.0lf",maxCallNum);
  return 0;
}
