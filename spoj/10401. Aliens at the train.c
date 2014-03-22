#include<stdio.h>
long long s[10000],sub[100000]={0},n,m,out[10000]={0};
long long sum=0,inp[100000],i,k;
int main()
{
    int x=0,y=0,test,l;
    scanf("%d",&test);
    for(l=0;l<test;l++)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0;i<n;i++)
            scanf("%lld",&inp[i]);
        sub[0]=inp[0];
        for(i=1;i<n;i++)
            sub[i]=inp[i]+sub[i-1];
        sub[n]=10000000;
        for(i=0;i<=n;i++)
            if(sub[i]>m)
            {
                x=i;
                break;
            }
        out[l]=sub[x-1];
        s[l]=x;
        for(i=x;i<n;i++)
        {
            for(k=y;k<i;k++)
            {
                sum=sub[i]-sub[k];
                if(sum<=m)
                    break;
            }
            y=k;
            if(i-k>s[l] && sum<=m)
            {
                out[l]=sum;
                s[l]=i-k;
            }
            else if(i-k==s[l] && out[l]>sum && sum<=m)
            {
                out[l]=sum;
                s[l]=i-k;
            }
        }
        y=0;
    }
    for(l=0;l<test;l++)
        printf("%lld %lld\n",out[l],s[l]);
    return 0;

}

