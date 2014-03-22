#include<stdio.h>
char backUp[15],n[13];
int start[100000],test;
int main()
{
    int i;
    scanf("%d",&test);
    for(i=0;i<test;i++)
        scanf("%s %d",n,&start[i]);
    for(i=0;i<test;i++)
    {
        if(start[i]==0)
            printf("Airborne wins.\n");
        else
            printf("Pagfloyd wins.\n");
    }
    return 0;
}

