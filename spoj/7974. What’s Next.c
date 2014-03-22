#include<stdio.h>
int main()
{
    int inp[1000][3],out[1000],i,j,test=0,sub[1000];
    while(1)
    {
        scanf("%d %d %d",&inp[test][0],&inp[test][1],&inp[test][2]);
        if(inp[test][0]==0 && inp[test][1]==0 && inp[test][2]==0)
            break;
        else
        {
            if((inp[test][1]-inp[test][0])==(inp[test][2]-inp[test][1]))
                sub[test]=1;
            else
                sub[test]=2;
            switch(sub[test])
            {
                case 1:
                    out[test]=2*inp[test][2]-inp[test][1];
                    break;
                case 2:
                    out[test]=inp[test][2]*(inp[test][1]/inp[test][0]);
                    break;
            }
            test++;
        }
    }
    for(i=0;i<test;i++)
    {
        if(sub[i]==1)
            printf("AP %d\n",out[i]);
        else
            printf("GP %d\n",out[i]);
    }
    return 0;
}
