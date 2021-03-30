int Max(int brr[],int lem)
{
    int max=0,i=0;
    for(i=0;i<lem;i++)
    {
        if(max<=brr[i]) max=brr[i];
    }
    return max;
}
int Min(int crr[],int lem)
{
    int min=0,i=0;
    for(i=0;i<lem;i++)
    {
        if(min>=crr[i]) min=crr[i];
    }
    return min;
}