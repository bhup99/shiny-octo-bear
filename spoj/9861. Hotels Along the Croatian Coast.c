#include<stdio.h>
long long sub[300000]={0},n,m,out=0,sum=0,inp[300000],x=0;;
int main()
{
    int j,i,k,x=0,y=0;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%lld",&inp[i]);
    sub[0]=inp[0];
    for(i=1;i<n;i++)
        sub[i]=inp[i]+sub[i-1];

    for(i=0;i<n;i++)
        if(sub[i]>m)
        {
            x=i;
            break;
        }
    out=sub[x-1];
    for(i=x;i<n;i++)
    {
        for(k=y;k<i;k++)
        {
            sum=sub[i]-sub[k];
            if(sum<=m)
                break;
        }
        y=k;
        if(sum>out && sum<=m)
            out=sum;
        if(out==m)
            break;
    }
    printf("%lld",out);
    return 0;

}
