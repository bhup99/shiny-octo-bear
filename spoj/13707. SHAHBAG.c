#include<stdio.h>
int p[7000000],group=0;
int sub[7000000]={0},q,i;
int main()
{
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&p[i]);
    }
    for(i=0;i<q;i++)
    {
        sub[p[i]]=1;
        if(sub[p[i]+1]==1 && sub[p[i]-1]==1)
            group--;
        else if(sub[p[i]+1]!=1 && sub[p[i]-1]!=1)
            group++;
        printf("%d\n",group);
    }
    printf("Justice\n");
    return 0;
}
