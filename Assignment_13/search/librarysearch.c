int search(int no,int crr[],int lem)
{
    int i=0;
    for(i=0;i<lem;++i)
    {
        if(crr[i]==no)
        {
            break;
        }
    }
    return i;
}





void sort(int brr[],int lem)
{
    int i=0,j=0,key=0;
    for(i=0;i<lem;++i)
    {
        
        key=brr[i];
        j=i-1;
        while((j>=0)&&(brr[j]>key))
        {
            brr[j+1]=brr[j];
            j--;
        }
        brr[j+1]=key;
    }
    for(i=0;i<lem;++i)
    {
        printf("%d\t",brr[i]);
    }
    printf("\n");
}


