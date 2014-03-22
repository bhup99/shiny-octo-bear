#include<stdio.h>

int main()
{
    int test,i,j,n,m,d,h,c =0;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d %d %d",&n,&m,&d);
        c = 0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&h);
            if(h<=d)
                c = 1;
        }
        if(c==0)
            printf("YES\n\n");
        else
            printf("NO\n\n");
    }
    return 0;
}
