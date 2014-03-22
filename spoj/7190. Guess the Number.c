#include<stdio.h>
int main()
{
    int len,i,out[20000],n=0,j;
    char inp[30];
    while(1)
    {
        scanf("%s",inp);
        if(inp[0]=='*')
            break;
        len=strlen(inp);
        for(i=1;i<=len;i++)
        {
            for(j=i*2;j<=len && inp[i-1]=='Y';j+=i)
            {
                if(inp[j-1]=='Y')
                {
                    inp[i-1]='X';
                    break;
                }
            }
        }
        out[n]=1;
        for(i=1;i<=len;i++)
        {
            if(inp[i-1]=='Y')
            {
                j=gcd(out[n],i);
                out[n]*=i/j;
            }
        }
        n++;
        for(i=1;i<=len;i++)
        {
            if(inp[i-1]=='N' && out[n-1]%i==0)
            {
                out[n-1]=-1;
                break;
            }
        }
    }
    for(i=0;i<n;i++)
        printf("%d\n",out[i]);
    return 0;
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        gcd(b,a%b);

}
