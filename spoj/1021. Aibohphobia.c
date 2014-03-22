#include<stdio.h>
int sub[26]={0};
long int test,spe;
char inp[6100];
static int y,z;
int main()
{
    int i,j,x=0;
    scanf("%ld",&test);

    for(spe=0;spe<test;spe++)
    {
        scanf("%s",inp);
        for(i=0;i<strlen(inp);i++)
        {
            sub[inp[i]-97]++;
        }
        printf("%d\n",aipho());
        for(i=0;i<26;i++)
            sub[i]=0;
    }
}

int aipho()
{
    int x=0,i=0,j=0,k=0,l=0;
    for(i=0;i<26;i++)
        if(sub[i]!=1 && sub[i]!=0)
        {
            x++;
            j=i;
        }
    if(x==0)
    {
        k=strlen(inp)-1;
        if(k<0)
            k=0;
        return k;
    }
    else if(x>=1)
    {
        y=0;
        z=0;
        l=final(0,strlen(inp));
        k=strlen(inp)-z;
        return k;
    }
}

int final(int left,int right)
{
    int i,j,k,l,m;
    if(left>=right)
        return z;
    else
    {
        for(i=left;i<right-1;i++)
            sub[inp[i]-97]++;
        for(i=left;i<right-1;i++)
        {
            for(j=right-1;j>left;j--)
            {
                if(j<=i)
                {
                    break;
                }
                else
                {
                    if(inp[i]==inp[j] && j!=i+1 && sub[inp[i]-97]!=1 && sub[inp[j]-97]!=1)
                    {
                        k=sub[inp[i]-97];   l=sub[inp[j]-97];
                        sub[inp[i]-97]=1;
                        sub[inp[j]-97]=1;
                        if(y)
                            y+=2;
                        else
                            y+=3;
                        final(i+1,j);
                        sub[inp[i]-97]=k;   sub[inp[j]-97]=l;
                    }
                    else if(inp[i]==inp[j] && j==i+1 && sub[inp[i]-97]!=1 && sub[inp[j]-97]!=1)
                    {
                        k=sub[inp[i]-97];   l=sub[inp[j]-97];
                        sub[inp[i]-97]=1;
                        sub[inp[j]-97]=1;
                        if(y)
                            y+=1;
                        else
                            y+=2;
                        final(i+1,j);
                    }
                }
            }
            if(y>=z)
                z=y;
            y=0;

        }
        for(j=left;j<right;j++)
            sub[inp[j]-97]=0;
    }
}
