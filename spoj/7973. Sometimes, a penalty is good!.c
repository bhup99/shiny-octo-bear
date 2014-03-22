#include<stdio.h>
int group[100000],teamNo[100000],knock[100000],d[100000],y[100000],match[100000],t_knock[100000];
int main()
{
    int i=0,j;
    while(1)
    {
        scanf("%d%d%d%d",&group[i],&teamNo[i],&knock[i],&d[i]);
        if(group[i]==-1 || teamNo[i]==-1 || knock[i]==-1 || d[i]==-1)
            break;
        else
        {
            t_knock[i]=calc(i);
        }
        i++;
    }
    for(j=0;j<i;j++)
    {
        match[j]=mCount(t_knock[j],j);
        printf("%d*%d/%d+%d=%d+%d\n",group[j],knock[j],teamNo[j],d[j],match[j],y[j]);
    }
return 0;
}

int calc(int i)
{
    int div=1,count,x=0,r=2,n=0,l=1;
    count=group[i]*knock[i]+d[i];
    while(r>1)
    {
        r=count/div;
        div=div*2;
        n++;
    }
    if(div>=2)
        l=div/2;
    if(count%l!=0)
    {
        r=count%l;
    }
    else if(count%l==0)
        n--;
    if(d[i]!=0)
        y[i]=(div/2)-r;
    return n;
}

int mCount(int t_knock,int j)
{
    int comb,i;
    comb=(teamNo[j]*(teamNo[j]-1))/2;
    comb=comb*group[j];
    for(i=t_knock-1;i>=0;i--)
    {
        comb+=pow(2,i);
    }
    return comb;
}



