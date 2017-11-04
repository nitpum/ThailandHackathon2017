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
struct paid{
  double inNetwork,outNetwork,anyNetwork,cost;
}

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

int oper(double number){
  if(number >= 0810000000 && number <= 0819999999){
    return 1;
  }

  if(number >= 0820000000 && number <= 0829999999){
    return 2;
  }

  if(number >= 0830000000 && number <= 0839999999){
    return 3;
  }
}

double maxCallStat=0;
double maxCallNum;
map<double,map<int,struct piad> > callData;

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

    //second use each time
    //printf("%lf\n",toTimestamp(data[i].startCall));
    data[i].secUse=toTimestamp(data[i].endCall)-toTimestamp(data[i].startCall);

    if(oper(data[i].caller)==1){
      double minUse=data[i].secUse;
      //cal package 811
      if(oper(data[i].caller)==oper(data[i].ans)){
        if(callData[data[i].caller][811].inNetwork+data[i].secUse<=200){
          callData[data[i].caller][811].inNetwork+=data[i].secUse;
        }
        else{
          callData[data[i].caller][811].inNetwork+data[i].secUse-200;
        }
      }
      else{
        //
      }
    }
    else if(oper(data[i].caller)==2){

    }
    else if(oper(data[i].caller)==3){

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
