#include<stdio.h>
#include<time.h>
#include<string.h>
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

  struct tm newtm;
  newtm.tm_year=a.year;
  newtm.tm_mon=a.month;
  newtm.tm_mday=a.date;
  newtm.tm_hour=a.hour;
  newtm.tm_min=a.min;
  newtm.tm_sec=a.sec;
  return mktime(&newtm);

return 0;
}

double maxCallStat=0;
double maxCallNum;
map<double,double> callStat;

void timestampToDate (double timestamp, char result[]) {
    time_t rawtime;
    char file[100];
    sscanf(file, "%010d", timestamp);
    rawtime = (time_t)file;

    struct tm * dt;
    char timestr[30];
    char buffer [30];

    dt = localtime(&rawtime);

    strftime(timestr, sizeof(timestr), "%Y-%m-%d %H:%M:%S", dt);
    sprintf(buffer,"%s", timestr);
    strcpy(result, buffer);
}

struct timestamp dateToStructStamp (char date[]) {
    struct timestamp t;
    sscanf(date,"%d-%d-%d %d:%d:%d"
        ,&t.year
        ,&t.month
        ,&t.date
        ,&t.hour
        ,&t.min
        ,&t.sec);
    return t;
}
/*
struct timestamp getTimestampValue (char date[]) {
    char theDate[100], originDate[100];
    timestampToDate(date, theDate);
    timestampToDate("0000000000", originDate);
    struct timestamp ts = dateToStructStamp(theDate);
    printf("Year: %d\n", ts.year);
    struct timestamp origin = dateToStructStamp(originDate);
    struct timestamp result;
    result.year = (ts.year - origin.year);
    result.month = (ts.month - origin.month);
    result.date = (ts.date - origin.date);
    result.hour = (ts.hour - origin.hour);
    result.min = (ts.min - origin.min);
    result.sec = (ts.sec - origin.sec);
    return result;
}
*/
int main(){
  char str[1000];
/*
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
    data[i].secUse=toTimestamp(data[i].endCall)-toTimestamp(data[i].startCall);

    //max
    callStat[data[i].caller]+=data[i].secUse;
    if(callStat[data[i].caller]>maxCallStat){
      maxCallStat=callStat[data[i].caller];
      maxCallNum=data[i].caller;
    }
  }
*/
    printf("%010d", 3597);

    struct timestamp test;
    //test = dateToCustomstamp("2017-10-01 00:00:13");
    //test = getTimestampValue("1509775011");
    printf("Year : %d", test.year);


    //printf("%d", time((time_t*)1509775011));
     //const time_t rawtime = (const time_t)timestamp;

      //  char tt[100];
     //timestampToDate(1506816003, tt);

     /*
     1506819600
     1506816003
     0000003597
     */
     //printf("%9lf", difftime((time_t)1506819600, (time_t)1506816003));


     /*
     char buffer[256];
     timestampToDate("0000000000", buffer);
     printf("\n%s", buffer);
     timestampToDate("0000003597", buffer);
     printf("%s", buffer);
     timestampToDate("0000000000", buffer);
     printf("\n%s", buffer);
     */


  //strftime( buffer, sizeof(buffer), "Now it's %I:%M%p.", (tm*)(time_t*)"16:35:12");


  //printf("Test %s", buffer);

  //printf("%010.0lf",maxCallNum);

  return 0;
}
