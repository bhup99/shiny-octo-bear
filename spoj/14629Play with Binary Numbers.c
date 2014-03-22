#include<stdio.h>
int main()
{
    long long test,m,n,kInp,i,j,k,a,b,bak,out=0;
    char str[26000],finStr[26000];
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        out=0;
        scanf("%lld %lld %lld",&m,&n,&kInp);
        for(j=m;j<n+1;j++)
        {
            bak=j;
            str[0]='\0';
            while(bak>0)
            {
                if(bak%2==0)
                    strcat(str,"0");
                else
                    strcat(str,"1");
                bak=bak/2;

            }
            for(k=0;k<strlen(str);k++)
                finStr[k]=str[strlen(str)-1-k];
            finStr[strlen(str)]='\0';
            a=0;
            b=0;
            for(k=0;k<strlen(str);k++)
            {
                if(finStr[k]=='1')
                {
                    if((k+1)%2==0)
                        b++;
                    else
                        a++;
                }
            }
            if(a>b)
                if(a-b==kInp)
                    out++;
            else
                if(b-a==kInp)
                    out++;

        }
        printf("%lld\n",out);
    }
    return 0;
}
