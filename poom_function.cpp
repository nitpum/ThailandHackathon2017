#include<stdio.h>

int timestampToMinute (double timestamp) { return timestamp /60; }

int timestampToHour (double timestamp) { return timestamp / 3600; }

int timestampToDay (double timestamp) { return timestamp / 86,400; }

int getValueBetweenCallTime (int startCall, int endCall, int date1, int date2)
{
    int startRange = startCall, endRange = endCall;
    if (startRange < date1)
        startRange = date1;
    if (endRange > date2 )
        endRange = date2;

        printf("Raw: %d %d\n", startRange, endRange);
    return (endRange - startRange);
}

int main() {

    int value;
    value = getValueBetweenCallTime( 1509537600, 1509624000, 1509577200, 1509580800);
    printf("%d %d\n", timestampToHour(value), value);

    printf("Hour : %d", timestampToHour(value));

    //printf("Hour: %d  Minute: %d", timestampToHour(00000100000), timestampToMinute(00000100000));

    return 0;
}
