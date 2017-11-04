double checkperiod(int period1,int period2)
{
    double startT,endT;
    struct timestamp tmpTmS;
    tmpTmS.year=data[i].startCall.year;
    tmpTmS.month=data[i].startCall.month;
    tmpTmS.date=data[i].startCall.date;
    tmpTmS.hour=period1;
    tmpTmS.min=0;
    tmpTmS.sec=0;

    struct timestamp tmpTmE;
    tmpTmE.year=data[i].startCall.year;
    tmpTmE.month=data[i].startCall.month;
    tmpTmE.date=data[i].startCall.date;
    tmpTmE.hour=period2;
    tmpTmE.min=0;
    tmpTmE.sec=0;

    int checkA=0;
    bool err=0;

    if(toTimestamp(data[i].startCall)>toTimestamp(tmpTmE)) continue;
    if(toTimestamp(data[i].startCall)>toTimestamp(tmpTmS))
    {
        startT=toTimestamp(data[i].startCall);
    }
    else
    {
        startT=toTimestamp(tmpTmS);
    }
    if(data[i].startCall.year==data[i].endCall.year)
    {
        if(data[i].startCall.month==data[i].endCall.month)
        {
            if(data[i].startCall.date==data[i].endCall.date)
            {
                checkA=1;
                if(toTimestamp(data[i].endCall)<toTimestamp(tmpTmE))
                {
                    if(toTimestamp(data[i].endCall)>toTimestamp(tmpTmS))
                    {
                        endT=toTimestamp(data[i].endCall);
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    endT=toTimestamp(tmpTmE);
                }
            }
        }
    }
    if(checkA==0)
    {
        endT=toTimestamp(tmpTmE);
    }
    return endT-startT;
}
