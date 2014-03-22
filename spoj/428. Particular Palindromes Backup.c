#include<stdio.h>
int test,s,out[20000]={0};
long long output=1,sub,m;
char str[100];
int main()
{
    int i,j;
    long long k,back;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d %d",&m,&s);
        if(m%10!=0)
        {
            output=1;
            power(10,s-1);
            sub=output;

            sub=sub/m;
            sub=sub*m;

            if(m%5==0)
            {
                back=sub*5;
                for(k=back;k<sub+back;k+=m)
                    if(checkPal(k))
                    {
                        out[i]++;
                    }
            }
            else
            {
                for(k=2*sub+m;k<sub*10;k+=m)

                    if(checkPal(k))
                    {
                        out[i]++;
                        printf("%lld\n",k);
                    }
            }

        }
    }
    for(i=0;i<test;i++)
        printf("%d\n",out[i]);
    return 0;
}

int checkPal(long long x)
{
    int i;
    long long r,j,k;
    for(i=0;i<s/2;i++)
    {
        output=1;
        power(10,s-i-1);
        r=output;
        k=x/r;
        k=k%10;

        output=1;
        power(10,i);
        r=output;
        j=x/r;
        j=j%10;

        if(k!=j)
        {
            r=0;
            break;
        }
    }
    if(r==0)
        return 0;
    else
        return 1;
}


int power(int x,int y)
{
    int iter;
    for(iter=0;iter<y;iter++)
        output=output*x;
    return output;
}


