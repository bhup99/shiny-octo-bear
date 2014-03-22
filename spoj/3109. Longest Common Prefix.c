#include<stdio.h>

int main()
{
    int test,q;
    char ch,inp[100000];
    scanf("%d",&test);
    int j,i,k,a,b;
    for(j=0;j<test;j++)
    {
        scanf("%s",inp);
        scanf("%d",&q);
        for(k=0;k<q;k++)
        {
            scanf("\n%c",&ch);
            if(ch=='Q')
            {
                scanf("%d %d",&a,&b);
                for(i=a-1;i<strlen(inp);i++)
                    if(inp[i]!=inp[b+i-a])
                        break;

                printf("%d\n",i-a+1);
            }
            else if(ch=='R')
            {
                scanf("%d %c",&a,&ch);
                inp[a-1] = ch;
            }

            else if(ch=='I')
            {
                scanf("%d %c",&a,&ch);
                for(i=strlen(inp)+1;i>a;i--)
                    inp[i] = inp[i-1];
                inp[a] = ch;
            }
        }
    }
    return 0;
}
