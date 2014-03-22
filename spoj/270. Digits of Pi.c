#include<stdio.h>
int main()
{
    int i,r,d;
    float s;
    r=22%7;
    printf("3.");
    for(i=0;i<10;i++)
    {
        r=r*10;
        d=r/7;
        r=r%7;
        printf("%d",d);
    }
    return 0;
}
