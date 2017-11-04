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
};

struct customer data[1000000];

int maxCallCount=0;
double maxCallNum;
map<double,int> callCount;
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
    callCount[data[i].caller]++;
    if(callCount[data[i].caller]>maxCallCount){
      maxCallCount=callCount[data[i].caller];
      maxCallNum=data[i].caller;
    }
  }
  printf("%10.0lf",maxCallNum);
  return 0;
}
