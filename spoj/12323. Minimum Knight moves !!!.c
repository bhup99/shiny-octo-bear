#include<stdio.h>
char s[2],t[2];
int f,g,h,j,dis,y,movef=0,sorMoves[200001],side[9][9];
int main()
{
    int n,i,k,l,m,j=0;
    for(i=0;i<9;i++)
        for(k=0;k<9;k++)
            side[i][k]=100000;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s",s,t);
        f=s[0]-96;
        g=s[1]-48;
        h=t[0]-96;
        j=t[1]-48;
        side[f][g]=0;
        if(f-h==0 && j-g==0)
            side[h][j]=0;
        else
            cal2(i,f,g,h,j,1);
        sorMoves[i]=side[h][j];
        for(j=1;j<9;j++)
            for(k=1;k<9;k++)
                side[j][k]=10000;
    }
    k=0;
    for(i=0;i<n;i++)
        printf("%d\n",sorMoves[i]);
    return 0;
}

int cal2(int k,int a,int b,int c,int d,int val)
{
    int move[8],max=1000000,i,xc;
    dis=c-a;
    y=d-b;
    if(a+2<9 && b+1<9 && side[a+2][b+1]>val)
    {
        side[a+2][b+1]=val;
        cal2(k,a+2,b+1,c,d,val+1);
    }
    if(a-2>0 && b+1<9 && side[a-2][b+1]>val)
    {
        side[a-2][b+1]=val;
        cal2(k,a-2,b+1,c,d,val+1);
    }
    if(b-1>0 && a-2>0 && side[a-2][b-1]>val)
    {
        side[a-2][b-1]=val;
        cal2(k,a-2,b-1,c,d,val+1);
    }
    if(a+2<9 && b-1>0 && side[a+2][b-1]>val)
    {
        side[a+2][b-1]=val;
        cal2(k,a+2,b-1,c,d,val+1);
    }
    if(a+1<9 && b+2<9 && side[a+1][b+2]>val)
    {
        side[a+1][b+2]=val;
        cal2(k,a+1,b+2,c,d,val+1);
    }
    if(b-2>0 && a+1<9  && side[a+1][b-2]>val)
    {
        side[a+1][b-2]=val;
        cal2(k,a+1,b-2,c,d,val+1);
    }
    if(a-1>0 && b-2>0 && side[a-1][b-2]>val)
    {
        side[a-1][b-2]=val;
        cal2(k,a-1,b-2,c,d,val+1);
    }
    if(b+2<9 && a-1>0 && side[a-1][b+2]>val)
    {
        side[a-1][b+2]=val;
        cal2(k,a-1,b+2,c,d,val+1);
    }

}



