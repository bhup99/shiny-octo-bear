#include<stdio.h>
typedef struct abc
{
    int parent,inp[4];
}s;
s abh[400][10000];
int main()
{
    int n[40000],i,j,t=0;
    while(1)
    {
        scanf("%d",&n[t]);
        if(n[t]==0)
            break;
        for(i=0;i<n[t];i++)
        {
            for(j=0;j<3;j++)
                scanf("%d",&abh[t][i].inp[j]);
        }
        t++;
    }
    for(i=0;i<t;i++)
        trigraph(n[i],i);
    return 0;
}

int trigraph(int n,int t)
{
    int sum=0,i,min,sec_min,ter_min;
    sum=abh[t][0].inp[1];
    abh[t][0].parent=2;
    for(i=1;i<n-1;i++)
    {
        min=low(i,t);
        if(min==abh[t][i].inp[1])
        {
            sum+=min;
            abh[t][i].parent=2;
        }
        else if(min==abh[t][i].inp[0])
        {
            abh[t][i].parent=1;
            if(abh[t][i-1].parent==2 || abh[t][i-1].parent==1)
            {
                sum+=min;
            }
            else
            {
                if(abh[t][i].inp[2]<abh[t][i].inp[1])
                    sec_min=abh[t][i].inp[2];
                else
                    sec_min=abh[t][i].inp[1];
                if(abh[i-1][t].inp[1]<abh[t][i].inp[1])
                    ter_min=abh[t][i-1].inp[1];
                else
                    ter_min=abh[t][i].inp[1];
                if(min+ter_min<sec_min)
                    sum+=min+ter_min;
                else
                    sum+=sec_min;
            }
        }
        else if(min==abh[t][i].inp[2])
        {
            abh[t][i].parent=3;
            if(abh[t][i-1].parent==2 || abh[t][i-1].parent==3)
                sum+=min;
            else
            {
                if(abh[t][i].inp[0]<abh[t][i].inp[1])
                    sec_min=abh[t][i].inp[0];
                else
                    sec_min=abh[t][i].inp[1];
                if(abh[t][i-1].inp[1]<abh[t][i].inp[1])
                    ter_min=abh[t][i-1].inp[1];
                else
                    ter_min=abh[t][i].inp[1];
                if(min+ter_min<sec_min)
                    sum+=min+ter_min;
                else
                    sum+=sec_min;
            }
        }

    }
    sum+=abh[t][n-1].inp[1];
    printf("%d. %d\n",t+1,sum);
}

int low(int i,int t)
{
    int min=100000,j;
    for(j=0;j<3;j++)
    {
        if(min>abh[t][i].inp[j])
            min=abh[t][i].inp[j];
    }
    return min;
}
