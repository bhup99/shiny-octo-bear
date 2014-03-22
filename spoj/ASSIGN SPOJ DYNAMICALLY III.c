#include<stdio.h>
#include <stdlib.h>

char *LastHope;


int CalAssign(int InpMat[20][20],int sub[20][20],int row,int col,int BlockedCol[20],int index)
{
    int x = 0, i;
    x = row;
    x = 20*x + col;
    for(i = 0; i < index; i++)
        x = x*2 + BlockedCol[i];
    x=LastHope[x];
    if(x>=0)
    {
        sub[row][col]=x;
        return 0;
    }
    int j;

    sub[row][col]=0;

    if(row==index-2)
    {
        for(i=0; i<index; i++)
            if(BlockedCol[i]==0)
                sub[row][col]+=InpMat[row+1][i];
    }
    else if(row==index-1)
    {
        for(i=0; i<index; i++)
            if(BlockedCol[i]==0)
                sub[row][col]=InpMat[row][i];
    }
    else
    {
        for(j=0; j<index; j++)
        {
            if(BlockedCol[j]==0 && InpMat[row+1][j]!=0)
            {
                BlockedCol[j]=1;
                CalAssign(InpMat,sub,row+1,j,BlockedCol,index);
                BlockedCol[j]=0;
            }
        }
        sub[row][col]=0;
        for(j=0; j<index; j++)
            if(BlockedCol[j]==0)
                sub[row][col]+=sub[row+1][j];
        x = row;
        x = x*20 + col;
        for(j = 0; j < index; j++)
            x = x*2 + BlockedCol[i];
        LastHope[x] *= sub[row][col];
    }


}

void negatify(int row,int col,int BlockedCol[20],int index,int LHCol)
{
    int i, x = 0;
    if(LHCol==index)
    {
        x = row;
        x = x*20 + col;
        for(i = 0; i < index; i++)
            x = x*2 + BlockedCol[i];
        LastHope[x] = -1;
        return;
    }
    for(i=0;i<2;i++)
    {
        BlockedCol[LHCol]=i;
        negatify(row,col,BlockedCol,index,LHCol+1);
    }
}




int main()
{

    int test,BlockedCol[20]={0};
    int sub[20][20],k,l,iter1,iter2;
    scanf("%d",&test);
    int i,j,InpMat[20][20],index;
    long long out;
    for(i=0; i<test; i++)
    {
        LastHope=(char * )malloc(419430400*sizeof(char));
        scanf("%d",&index);

        for(j=0; j<index; j++)
            for(k=0; k<index; k++)
            {
                scanf("%d",&InpMat[j][k]);
                sub[j][k]=0;
                negatify(j,k,BlockedCol,index,0);
            }

        for(j=0;j<index;j++)
            BlockedCol[j]=0;
        for(l=0; l<index; l++)
        {
            BlockedCol[l]=1;
            if(InpMat[0][l]!=0)
                CalAssign(InpMat,sub,0,l,BlockedCol,index);
            BlockedCol[l]=0;
        }
        out=0;
        for(k=0; k<index; k++)
        {
            out+=sub[0][k];
        }
        printf("%lld\n",out);
        free(LastHope);
    }
    return 0;
}

