#include<stdio.h>
int src[30][3],tar[30][3],sorMoves[30][30],target[40]={0},inpMat[30][30];
static int x;
main()
{
    int cord[30][2],minMoves,i,j,k,n,l,c,val;
    while(1)
    {
        scanf("%d %d",&n,&c);
        if(n==0 && c==0)
            break;
        else
        {
            for(i=0;i<n;i++)
            {
                scanf("%d %d",&cord[i][0],&cord[i][1]);
            }
            for(i=0;i<n;i++)
                for(j=0;j<n;j++)
                    scanf("%d",&inpMat[i][j]);
            k=0;
            for(l=0;l<n;l++)
            {
                minMoves=0;
                target[l]=k+1;
                minMoves+=inpMat[k][l];
                final(target,1,n,minMoves);
                target[l]=0;
            }
            val=
        }
    }
    printf("Minimum number of moves is %d",x);
}

void final(int *target,int curSor,int limit,int minMoves)
{
    int i;
    if(curSor>=limit)
    {
        if(x>minMoves || x==0)
        {
            x=minMoves;
        }
    }
    else
    {
        for(i=0;i<limit;i++)
        {
            if(!target[i])
            {
                target[i]=curSor+1;
                minMoves+=inpMat[curSor][i];
                final(target,curSor+1,limit,minMoves);
                target[i]=0;
                minMoves-=inpMat[curSor][i];
            }
        }
    }
}
