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

int CalAssign(FILE *fp,int InpMat[21][21],int sub[21][21],int row,int col,int BlockedCol[21],int index)
{
    int i,j;
    static int count;
    printf("%d %d %d\n",count++,row,col);
    for(i=0;i<index;i++)
        printf("%d\t",BlockedCol[i]);

    printf("\n\n");

    sub[row][col]=0;

    if(row==index-2)
    {
        for(i=0;i<index;i++)
            if(BlockedCol[i]==0)
                sub[row][col]+=InpMat[row+1][i];
    }
    else if(row==index-1)
    {
        for(i=0;i<index;i++)
            if(BlockedCol[i]==0)
                sub[row][col]=InpMat[row][i];
    }
    else
    {
        for(i=row+1;i<index;i++)
        {
            for(j=0;j<index;j++)
            {
                if(BlockedCol[j]==0 && InpMat[i][j]!=0)
                {
                    BlockedCol[j]=1;
                    CalAssign(fp,InpMat,sub,i,j,BlockedCol,index);
                    BlockedCol[j]=0;
                }
            }
            sub[row][col]=0;
            for(j=0;j<index;j++)
                if(BlockedCol[j]==0)
                    sub[row][col]+=sub[row+1][j];
        }
    }
    for(i=0;i<index;i++)
    {
        for(j=0;j<index;j++)
            fprintf(fp,"%d\t",sub[i][j]);
        fprintf(fp,"\n");
    }
    fprintf(fp,"\n\n");


}


int main()
{
    int test,BlockedCol[21];
    FILE *fp;
    fp=fopen("input.txt","w");
    int sub[21][21],k,l,iter1,iter2;
    scanf("%d",&test);
    int i,j,InpMat[21][21],out,index;
    for(i=0;i<test;i++)
    {
        scanf("%d",&index);

        for(j=0;j<index;j++)
            for(k=0;k<index;k++)
            {
                scanf("%d",&InpMat[j][k]);
                sub[j][k]=0;
            }

        for(j=0;j<index;j++)
            BlockedCol[j]=0;




            for(l=0;l<index;l++)
            {
                    BlockedCol[l]=1;
                    if(InpMat[0][l]!=0)
                        CalAssign(fp,InpMat,sub,0,l,BlockedCol,index);
                    BlockedCol[l]=0;





        }
        for(k=0;k<index;k++)
        {
            for(l=0;l<index;l++)
                printf("%d\t",sub[k][l]);
            printf("\n");
        }

    }
}

