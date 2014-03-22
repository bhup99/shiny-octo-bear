#include<stdio.h>
int main()
{
    int n=0,inp,i=0,out[200000]={0};
    while(1)
    {
        scanf("%d",&inp);
        if(inp==0)
            break;
        for(i=0;i<inp;i++)
            out[n]+=pow(inp-i,2);
        n++;
    }
    for(i=0;i<n;i++)
        printf("%d\n",out[i]);
    return 0;
}
