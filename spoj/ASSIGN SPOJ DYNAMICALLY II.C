/*

Problem:-Your task will be to calculate number of different assignments of n different topics to n students such
that everybody gets exactly one topic he likes.

Input:First line of input contains number of test cases c (1<=c<=80). Each test case begins with number of
students n (1<=n<=20). Each of the next n lines contains n integers describing preferences of one
student. 1 at the ith position means that this student likes ith topic, 0 means that he definitely doesn’t
want to take it.

Output:-For each test case output number of different assignments (it will fit in a signed 64-bit integer).

Sampple Input:-3
3
1 1 1
1 1 1
1 1 1
11
1 0 0 1 0 0 0 0 0 1 1
1 1 1 1 1 0 1 0 1 0 0
1 0 0 1 0 0 1 1 0 1 0
1 0 1 1 1 0 1 1 0 1 1
0 1 1 1 0 1 0 0 1 1 1
1 1 1 0 0 1 0 0 0 0 0
0 0 0 0 1 0 1 0 0 0 1
1 0 1 1 0 0 0 0 0 0 1
0 0 1 0 1 1 0 0 0 1 1
1 1 1 0 0 0 1 0 1 0 1
1 0 0 0 1 1 1 1 0 0 0
11
0 1 1 1 0 1 0 0 0 1 0
0 0 1 1 1 1 1 1 1 1 1
1 1 0 1 0 0 0 0 0 1 0
0 1 0 1 0 1 0 1 0 1 1
1 0 0 1 0 0 0 0 1 0 1
0 0 1 0 1 1 0 0 0 0 1
1 0 1 0 1 1 1 0 1 1 0
1 0 1 1 0 1 1 0 0 1 0
0 0 1 1 0 1 1 1 1 1 1
0 1 0 0 0 0 0 0 0 1 1
0 1 1 0 0 0 0 0 1 0 1

Sample Output:-
6
7588
7426
*/


#include<stdio.h>

int LastHope[20][20][32][32][32][32];

int CalAssign(int InpMat[20][20],int sub[20][20],int row,int col,int BlockedCol[20],int index)
{
    int a,b,c,d,e;
    a=16*BlockedCol[4]+8*BlockedCol[3]+4*BlockedCol[2]+2*BlockedCol[1]+BlockedCol[0];
    b=16*BlockedCol[9]+8*BlockedCol[8]+4*BlockedCol[7]+2*BlockedCol[6]+BlockedCol[5];
    c=16*BlockedCol[14]+8*BlockedCol[13]+4*BlockedCol[12]+2*BlockedCol[11]+BlockedCol[10];
    d=16*BlockedCol[19]+8*BlockedCol[18]+4*BlockedCol[17]+2*BlockedCol[16]+BlockedCol[15];

    if(LastHope[row][col][a][b][c][d]>=0)
    {
        sub[row][col]=LastHope[row][col][a][b][c][d];
        return 0;
    }
    int i,j;

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

        LastHope[row][col][a][b][c][d]=sub[row][col];
    }


}

int negatify(int row,int col,int BlockedCol[20],int index,int LHCol)
{
    int i;
    int a,b,c,d,e;
    a=16*BlockedCol[4]+8*BlockedCol[3]+4*BlockedCol[2]+2*BlockedCol[1]+BlockedCol[0];
    b=16*BlockedCol[9]+8*BlockedCol[8]+4*BlockedCol[7]+2*BlockedCol[6]+BlockedCol[5];
    c=16*BlockedCol[14]+8*BlockedCol[13]+4*BlockedCol[12]+2*BlockedCol[11]+BlockedCol[10];
    d=16*BlockedCol[19]+8*BlockedCol[18]+4*BlockedCol[17]+2*BlockedCol[16]+BlockedCol[15];

    if(LHCol==index)
    {
        LastHope[row][col][a][b][c][d]=-66;
        return 0;
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
    }
    return 0;
}



