#include<stdio.h>
double convertTime(double time)
{
    int min=0;
    min=time/60;
    time-=min*60;
    if(time>0)
        min++;
    return (double)min;
}
int main()
{
    printf("%lf",convertTime(5));
}
