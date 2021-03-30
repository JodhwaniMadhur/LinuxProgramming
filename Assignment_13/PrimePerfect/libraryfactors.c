int sumFactors(int no)
{
    int i,sum=0;
    for(i=1;i<=no/2;i++)
    {
        if((no%i)==0) sum=sum+i;
    }
     return sum;
}