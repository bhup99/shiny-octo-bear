#include<stdio.h>
long long int order[7000000],check[7000000],test,inp[100][2],sub[7000000],out,max=0,i,j;
int main()
{
    int bak,k=0;;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
        scanf("%lld %lld",&inp[i][0],&inp[i][1]);
    sub[1]=2;
    sub[2]=3;
    for(i=0;i<test;i++)
    {
        if(max<inp[i][0])
            max=inp[i][0];
    }
    for(j=3;j<=max;j++)
    {
        sub[j]=(sub[j-1]+sub[j-2])%100000;
        if(check[sub[i]])
            break;

        check[sub[i]]=1;
        k++;
    }
    bak=k;
    for(i=0;i<test;i++)
    {
        if(inp[i][0]==1)
            printf("%lld\n",sub[1]%inp[i][1]);
        else if(inp[i][0]==2)
            printf("%lld\n",sub[2]%inp[i][1]);
        else
        {
            out=0;
            k=inp[i][0]%inp[i][1];
            for(j=1;j<=k;j++)
            {
                out+=sub[j];
                if(out>1000000)
                    out=out%inp[j][1];
            }
            printf("%lld\n",out%inp[i][1]);
        }
        k=bak;
    }
    return 0;
}
