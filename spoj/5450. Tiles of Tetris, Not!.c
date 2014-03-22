#include<stdio.h>
long long int inp[700000][2],out[700000];
long long int i=0,lcm,j;
int main()
{
    while(1)
    {
        scanf("%lld %lld",&inp[i][0],&inp[i][1]);
        if(inp[i][0]==0 && inp[i][1]==0)
            break;

        else
        {
            LCM(inp[i][0],inp[i][1]);
        }
    }
    printf("\n");
    for(j=0;j<i;j++)
        printf("%lld\n",out[j]);
    return 0;
}

int LCM(long long int sub1,long long int sub2)
{
    long long int gc;
    if(sub1>sub2)
        gc=gcd(sub1,sub2);
    else
        gc=gcd(sub2,sub1);
    sub1=sub1/gc;
    sub2=sub2/gc;
    gc=(sub1*sub2);
    out[i]=gc;
    i++;
}

int gcd(long long int a,long long int b)
{
    if(b==0)
        return a;
    else
        gcd(b,a%b);

}
