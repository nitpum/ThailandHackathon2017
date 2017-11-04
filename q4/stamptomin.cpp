double convertTime(double time)
{
    int min=0;
    min=time/60;
    min-=time*60;
    if(time>0)
        min++;
    return min
}
