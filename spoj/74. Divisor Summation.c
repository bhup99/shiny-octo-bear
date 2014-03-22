#include<stdio.h>
main()
{
    int sum[200],i,test,input[200],output[200];
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&input[i]);
        sum[i]=summat(input[i]);
    }
    for(i=0;i<test;i++)
    {
        printf("%d\n",sum[i]);
    }
}

int summat(int val)
{
    int sum=0,r=0,div;
    if(val%2==0)
    {
        div=1;  r=1;
        while(div<=(val/2))
        {
            r=val%div;
            if(r==0)
            {
                sum+=div;
            }
            div++;
        }
    }
    else
    {
        div=1;  r=1;
        while(div<(val/2))
        {
            r=val%div;
            if(r==0)
            {
                sum+=div;
            }
            div+=2;
        }
    }
    return sum;
}
