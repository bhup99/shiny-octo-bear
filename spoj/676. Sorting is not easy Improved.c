#include<stdio.h>
long long out[11];
int k,test,n[11],inp[11][1000],i,j,sum=0;
int main()
{
    int left,right,l=1,sub[1000]={0},eme=0,m;
    scanf("%d",&test);
    for(i=0;i<test;i++)
        out[i]=10000;
    for(i=0;i<test;i++)
    {
        scanf("%d",&n[i]);
        for(j=1;j<=n[i];j++)
            scanf("%d",&inp[i][j]);
    }
    for(i=0;i<test;i++)
    {
        for(j=1;j<=n[i];j++)
        {
            left=inp[i][j]-1;
            right=inp[i][j]+1;
            sub[inp[i][j]]=1;
            sum+=j;
            eme=1;
            for(;;)
            {
                k=rand()%n[i]+1;
                if(sub[inp[i][k]])
                    continue;
                for(m=1;m<=k;m++)
                {
                    if(sub[m]==0)
                        eme++;
                }
                if(inp[i][k]==left && left!=0 && left>=0)
                {
                    left--;
                    sub[inp[i][k]]=1;
                    sum+=(eme)*(l+1);
                    l++;
                    k=0;
                    eme=0;
                }
                else if(inp[i][k]==right && right!=n[i]+1 && right<=n[i])
                {
                    right++;
                    sum+=(eme)*(l+1);
                    sub[inp[i][k]]=1;
                    l++;
                    k=0;
                    eme=0;
                }
                if(left<1 && right>n[i])
                    break;
            }
            if(out[i]>sum)
                out[i]=sum;
            sum=0;
            l=1;
            eme=0;
            for(k=1;k<=n[i];k++)
                sub[k]=0;
        }
    }
    for(i=0;i<test;i++)
        printf("%d\n",out[i]);
    return 0;
}
