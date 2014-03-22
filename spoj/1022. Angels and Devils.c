#include<stdio.h>
char inp[40][40][2];
main()
{
    int k,x,y,test,i,j;
    printf("Enter the number of test cases");
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d %d",&x,&y);

        fflush(stdin);
        for(j=0;j<x;j++)
            for(k=0;k<y;)
            {
                scanf("%c",&inp[j][k][0]);
                inp[j][k][1]='1';
                if(inp[j][k][0]!=' ' && inp[j][k][0]!=10)
                    k++;
            }
        occ(x,y);
        for(j=0;j<x;j++)
        {
            printf("\n");
            for(k=0;k<y;k++)
                printf("%c %c",inp[j][k][0],inp[j][k][1]);
        }
    }

}

void occ(int x,int y)
{
    int i,j,k,l=0,m,n;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            if(inp[i][j][0]=='H' && inp[i][j][1]=='1')
            {
                for(k=i;k<x;k++)
                {
                    if(inp[k][j][0]=='A')
                        break;
                    inp[k][j][1]='0';
                    printf("%d %d %d %c %c\n",k,j,i,inp[i][j][0],inp[k][j][0]);
                }
                for(k=j;k<y;k++)
                {
                    if(inp[i][k][0]=='A')
                        break;
                    inp[i][k][1]='0';
                    printf("%d %d %d %c %c\n",k,j,i,inp[i][j][0],inp[k][j][0]);
                }
                l++;
                for(k=0;k<x;k++)
                {
                    for(m=0;m<y;m++)
                        printf("%c %c\t",inp[k][m][0],inp[k][m][1]);
                    printf("\n");
                }
                printf("\n");
            }
        }
    }
    printf("Maximum possible fighters that can be settled are %d",l);
}
