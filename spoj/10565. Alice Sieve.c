#include<stdio.h>
int out[10000],sub[1000000][2];
int main()
{
    int p,test,inp,i,j;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&inp);
        out[i]=inp-inp/2;
    }
    for(i=0;i<test;i++)
        printf("%d\n",out[i]);
    return 0;
}
