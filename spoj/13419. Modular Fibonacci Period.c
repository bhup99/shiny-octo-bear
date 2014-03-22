#include<stdio.h>
long long m[10000],fib[100000000];
long long out[10000],inp[10000];
int main()
{
    long long  i,test,j;
    fib[0]=0;
    fib[1]=1;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
        scanf("%lld",&m[i]);
    for(i=0;i<test;i++)
    {
        for(j=2;;j++)
        {
            fib[j]=fib[j-1]+fib[j-2];
            fib[j]=fib[j]%m[i];
            if(check(j)==1)
                break;
        }
        out[i]=j/2;
    }
    for(i=0;i<test;i++)
        printf("%lld\n",out[i]);
}

int check(long long sno)
{
    long long i,j,sub;
    sub=sno%1000000;
    for(i=0;i<sub/2;i++)
    {
        if(fib[i]!=fib[i+sno/2])
            break;
    }
    if(i==sno/2)
        return 1;
    else
        return 0;
}
