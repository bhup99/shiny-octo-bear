#include<stdio.h>
double out[100];
int inp[100],i,j;
int main()
{
    int test,sub=0;
    scanf("%d",&test);
    for(i=0;i<test;i++)
        scanf("%d",&inp[i]);
    for(i=0;i<test;i++)
    {
        out[i]=1;
        for(j=1;j<=inp[i];j++)
        {
            out[i]=out[i]*j;
        }
    }
    for(i=0;i<test;i++)
    {
        printf("%lld\n",out[i]);
    }
    return 0;
}
