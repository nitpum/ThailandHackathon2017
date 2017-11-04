#include<stdio.h>
#include<time.h>
#include<map>
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
map<int,double> proCount;
map<int,double> proTime;
map<int,double> inNetCallTime;
map<int,double> outNetCallTime;
map<int,double> inNetCallCount;
map<int,double> outNetCallCount;

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

void printProStat(int proId){
  printf("%d count: %lf\n",proId,proCount[proId]);
  printf("  Time: %lf\n",proTime[proId]);
  printf("  TimeAvg: %lf\n",proTime[proId]/proCount[proId]);
  printf("  In: %lf\n",inNetCallTime[proId]/inNetCallCount[proId]);
  printf("  Out: %lf\n\n",outNetCallTime[proId]/outNetCallCount[proId]);
}

int main(){
  double avgSec=0,outNetworkCount=0;
  double avgSecIn=0,inNetworkCount=0;
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

    proCount[data[i].promo]++;
    proTime[data[i].promo]+=data[i].secUse;

    if(oper(data[i].caller)!=oper(data[i].ans)){
      outNetCallTime[data[i].promo]+=data[i].secUse;
      outNetCallCount[data[i].promo]++;
    }
    else{
      inNetCallTime[data[i].promo]+=data[i].secUse;
      inNetCallCount[data[i].promo]++;
    }

    //max
    /*callStat[data[i].caller]+=data[i].secUse;
    if(callStat[data[i].caller]>maxCallStat){
      maxCallStat=callStat[data[i].caller];
      maxCallNum=data[i].caller;
    }*/

  }

  printProStat(811);
  printProStat(812);
  printProStat(813);
  printProStat(821);
  printProStat(822);
  printProStat(831);
  printProStat(832);
  //printf("%010.0lf",maxCallNum);
  return 0;
}
