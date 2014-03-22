#include<stdio.h>
int main()
{
    int out[11],k,test,n,inp[1000],i,j,sum;
    int left,right,l,sub[1000],eme,checkPoint;
    int numPos[1000],iter;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        out[i]=100000;
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&inp[j]);
            numPos[inp[j]]=j;
        }
        numPos[n+1]=10000;
        numPos[0]=10000;
        for(j=1;j<=n;j++)
        {
            eme=0;
            checkPoint=0;
            left=inp[j]-1;
            right=inp[j]+1;
            sub[checkPoint++]=j;
            sum=j;
            l=2;
            for(k=1;k<n;k++)
            {
                eme=0;
                if(numPos[left]<numPos[right])
                {
                    for(iter=0;iter<checkPoint;iter++)
                        if(sub[iter]<numPos[left])
                            eme++;
                    sum+=(l++)*(numPos[left]-eme);
                    sub[checkPoint++]=numPos[left--];
                }
                else
                {
                    for(iter=0;iter<checkPoint;iter++)
                        if(sub[iter]<numPos[right])
                            eme++;
                    sum+=(l++)*(numPos[right]-eme);
                    sub[checkPoint++]=numPos[right++];
                }
            }
            if(out[i]>sum)
                out[i]=sum;
        }
    }
    for(i=0;i<test;i++)
        printf("%lld\n",out[i]);
    return 0;
}
