#include<stdio.h>
int main()
{
    int test,i,j,inp[10],inp2[10],out[10],out2[10];
    for(i=0;i<10;i++)
        scanf("%d %d",&inp[i],&inp2[i]);
    for(i=0;i<10;i++)
    {
        out[i]=(inp[i]+inp2[i])/2;
        out2[i]=(inp[i]-inp2[i])/2;
        printf("%d\n%d\n",out[i],out2[i]);
    }
    return 0;
}

