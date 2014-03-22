 #include<stdio.h>
long long i,j,k,km;
int test;
long long fib[1000000]={0},maxfib[2000000]={0},input[10000],output[10000],kilo[10000],val;
int main()
{
    int dist;
    scanf("%d",&test);
    for(dist=0;dist<test;dist++)
    {
        scanf("%lld",&input[dist]);
        val=input[dist];
        output[dist]=mitoki();
    }
    for(i=0;i<test;i++)
        printf("%lld\n",output[i]);
    return 0;
}

int mitoki()
{
    km=0;
    i=2;
    fib[0]=1;
    fib[1]=1;
    while(1)
    {
        if(fib[i-1]<=val)
        {
            fib[i]=fib[i-1]+fib[i-2];
            i++;
        }
        else
            break;
    }
    maxfib[0]=fib[i-1];
    val=val-fib[i-2];
    j=1;
    while(val>0)
    {
        for(k=0;k<i;k++)
        {
            if(fib[k]>val)
                break;
        }
        maxfib[j]=fib[k];
        val=val-fib[k-1];
        j++;
    }
    for(k=0;k<j;k++)
    {
        km+=maxfib[k];
    }
    return km;
}
