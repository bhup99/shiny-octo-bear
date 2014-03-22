#include<stdio.h>
long long inp[50];
int main()
{
    int k,l,m,i,j,max;
    char out[50];
    out[0]='\0';
    scanf("%d %d %d",&k,&l,&m);
    if(k>l)
        max=k;
    else
        max=l;
    for(i=0;i<m;i++)
    {
        scanf("%lld",&inp[i]);
        if(inp[i]%(1+max))
            strcat(out,"A");
        else
            strcat(out,"B");
    }
    printf("\n%s",out);
    return 0;
}
