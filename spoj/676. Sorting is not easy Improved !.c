#include<stdio.h>
long long out[11]={0};
int k,test,n,inp[1000],sub[1000]={0},i,j,sum=0,wor[1000]={0};
int main()
{
    int left,right,l=1,eme=0,m;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        out[i]=1000000000000;
        scanf("%d",&n);
        for(j=1;j<=n;j++)
            scanf("%d",&inp[j]);
        for(j=1;j<=n;j++)
            sub[inp[j]]=j;
        for(j=1;j<=n/3;j++)
        {
            if(j%2==0)
                eme=cal(j,i,0);
            else
                eme=cal(j,i,-1);
            if(eme<out[i])
                out[i]=eme;
        }
        if(j%2==0)
        {
            for(k=1;k<=n;k++)
                wor[k]=0;
        }
    }

    for(i=0;i<test;i++)
        printf("%lld\n",out[i]);
    return 0;
}

int cal(int fir,int test,int val)
{
    int left,right,i,j,k=2,cv,l=0;
    cv=fir;
    wor[inp[fir]]=val;
    left=inp[fir]-1;
    right=inp[fir]+1;
    for(i=1;i<=n;i++)
    {
        if((sub[left]>sub[right]||left==0) && right<=n)
        {
            for(j=1;j<sub[right];j++)
                if(wor[inp[j]]==val)
                    l++;
            cv+=(sub[right]-l)*k;
            k++;
            l=0;
            wor[right]=val;
            right++;
        }
        else if(left>0)
        {
            for(j=1;j<sub[left];j++)
                if(wor[inp[j]]==val)
                    l++;
            cv+=(sub[left]-l)*k;
            k++;
            l=0;
            wor[left]=val;
            left--;
        }
    }
    return cv;
}
