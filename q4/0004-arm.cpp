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

int oper(double number){
  if(number >= 810000000 && number <= 819999999){
    return 1;
  }

  if(number >= 820000000 && number <= 829999999){
    return 2;
  }

  if(number >= 830000000 && number <= 839999999){
    return 3;
  }
}

double convertTime(double time)
{
    int min=0;
    min=time/60;
    time-=min*60;
    if(time>0)
        min++;
    return (double)min;
}

double maxCallStat=0;
double maxCallNum;
map<double,map<int,struct paid> > callData;

void callInNetwork(int i,int pro,int minUse,int freeMin,double overCost){
  double minOver;
  if(callData[data[i].caller][pro].inNetwork+minUse<=freeMin){
    callData[data[i].caller][pro].inNetwork+=minUse;
  }
  else if(callData[data[i].caller][pro].inNetwork==freeMin){
    callData[data[i].caller][pro].cost+=minUse*overCost;
  }
  else{
    callData[data[i].caller][pro].inNetwork=freeMin;
    minOver=callData[data[i].caller][pro].inNetwork+minUse-freeMin;
    callData[data[i].caller][pro].cost+=minOver*overCost;
  }
  return;
}

void callOutNetwork(int i,int pro,int minUse,int freeMin,double overCost){
  double minOver;
  if(callData[data[i].caller][pro].outNetwork+minUse<=freeMin){
    callData[data[i].caller][pro].outNetwork+=minUse;
  }
  else if(callData[data[i].caller][pro].outNetwork==freeMin){
    callData[data[i].caller][pro].cost+=minUse*overCost;
  }
  else{
    callData[data[i].caller][pro].outNetwork=freeMin;
    minOver=callData[data[i].caller][pro].outNetwork+minUse-freeMin;
    callData[data[i].caller][pro].cost+=minOver*overCost;
  }
  return;
}

void callAnyNetwork(int i,int pro,int minUse,int freeMin,double overCost){
  double minOver;
  if(callData[data[i].caller][pro].anyNetwork+minUse<=freeMin){
    callData[data[i].caller][pro].anyNetwork+=minUse;
  }
  else if(callData[data[i].caller][pro].anyNetwork==freeMin){
    callData[data[i].caller][pro].cost+=minUse*overCost;
  }
  else{
    callData[data[i].caller][pro].anyNetwork=freeMin;
    minOver=callData[data[i].caller][pro].anyNetwork+minUse-freeMin;
    callData[data[i].caller][pro].cost+=minOver*overCost;
  }
  return;
}

double callInTime(struct timestamp startCall,struct timestamp endCall,int startFree,int endFree){
  double startT,endT;
  struct timestamp tmpTmS;
  tmpTmS.year=startCall.year;
  tmpTmS.month=startCall.month;
  tmpTmS.date=startCall.date;
  tmpTmS.hour=startFree;
  tmpTmS.min=0;
  tmpTmS.sec=0;

  struct timestamp tmpTmE;
  tmpTmE.year=startCall.year;
  tmpTmE.month=startCall.month;
  tmpTmE.date=startCall.date;
  tmpTmE.hour=endFree;
  tmpTmE.min=0;
  tmpTmE.sec=0;

  int checkA=0;
  bool err=0;

  if(toTimestamp(startCall)>toTimestamp(tmpTmE)) continue;
  if(toTimestamp(startCall)>toTimestamp(tmpTmS)){
    startT=toTimestamp(startCall);
  }
  else{
    startT=toTimestamp(tmpTmS);
  }
  if(startCall.year==endCall.year){
    if(startCall.month==endCall.month){
      if(startCall.date==endCall.date){
        checkA=1;
        if(toTimestamp(endCall)<toTimestamp(tmpTmE)){
          if(toTimestamp(endCall)>toTimestamp(tmpTmS)){
            endT=toTimestamp(endCall);
          }
          else{
            continue;
          }
        }
        else{
          endT=toTimestamp(tmpTmE);
        }
      }
    }
  }
  if(checkA==0){
    endT=toTimestamp(tmpTmE);
  }

  return endT-startT;
}

void callInNetworkTime(int i,int pro,struct timestamp startCall,struct timestamp endCall,int startFree,int endFree){
  double minOver;
  if(callData[data[i].caller][pro].inNetwork+minUse<=freeMin){
    callData[data[i].caller][pro].inNetwork+=minUse;
  }
  else if(callData[data[i].caller][pro].inNetwork==freeMin){
    callData[data[i].caller][pro].cost+=minUse*overCost;
  }
  else{
    callData[data[i].caller][pro].inNetwork=freeMin;
    minOver=callData[data[i].caller][pro].inNetwork+minUse-freeMin;
    callData[data[i].caller][pro].cost+=minOver*overCost;
  }
  return;
}

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
      //cal package 811
      if(oper(data[i].caller)==oper(data[i].ans)){
        callInNetwork(i,811,convertTime(data[i].secUse),200,1);
      }
      else{
        callOutNetwork(i,811,convertTime(data[i].secUse),100,1.5);
      }

      //cal package 812
      if(oper(data[i].caller)==oper(data[i].ans)){
        callInNetwork(i,812,convertTime(data[i].secUse),400,1);
      }
      else{
        callOutNetwork(i,812,convertTime(data[i].secUse),150,1.5);
      }

      //cal package 813
      callAnyNetwork(i,813,convertTime(data[i].secUse),600,1.5);
    }
    else if(oper(data[i].caller)==2){
      //
    }
    else if(oper(data[i].caller)==3){

    }

  }
  //printf("%010.0lf",maxCallNum);
  return 0;
}
