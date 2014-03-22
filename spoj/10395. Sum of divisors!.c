#include<stdio.h>
int main()
{
    int test,a,b,i,j,out=0,l,one,two,ini,n,sum1,sum2;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        out=0;
        one=0;
        two=0;
        scanf("%d %d",&a,&b);
        for(j=a;j<=b;j++)
        {
            if(j==2)
                out++;
            else if(j==1)
                continue;
            else
            {
                l=(int)sqrt(j);
                if(l*l==j)
                {
                    ini=l-2;
                    one=j;
                    break;
                }
            }
        }
        if(one)
        {
            ini=5+(ini-1)*2;
            n=((1-ini)+(int)sqrt(pow(ini-1,2)+4*(b-one)))/2;
            sum1=(n)*(ini+(n-1))+one;
            sum2=(n+1)*(ini+(n))+one;
            if(sum2>b)
                out+=n+1;
            else
                out+=n;
        }
        printf("%d\n",out);
    }
    return 0;
}
