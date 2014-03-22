#include<stdio.h>
int test,m,s,out[20000]={0};
char str[20];
int main()
{
    int i,j,sub,k;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        str[0]='\0';
        scanf("%d %d",&m,&s);
        if(m%10!=0)
        {
            strcpy(str,"0");
            for(j=0;j<s-1;j++)
            {
                strcat(str,"0");
            }
            if(m<12)
            {
                if(s%2==0)
                {
                    even(s/2,i);
                }
                else
                {
                    odd(s/2,i);
                }
            }
            else
            {
                str[0]='1';
                str[s-1]='1';
                if(s%2==0)
                {
                    sub=sEven(s/2,i);
                }
                else
                {
                    sub=sOdd(s/2,i);
                }
                if(sub>power(10,s-1))
                {
                    for(k=sub+m;k<power(10,s);k+=m)
                    {
                        if(checkPal(k))
                        {
                            out[i]++;
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<test;i++)
        printf("%d\n",out[i]);
    return 0;
}

int checkPal(int x)
{
    int r=1,i,j,k;
    for(i=0;i<s/2;i++)
    {
        r=power(10,s-i-1);
        k=x/r;
        k=k%10;

        r=power(10,i);
        j=x/r;
        j=j%10;

        if(k!=j)
        {
            r=0;
            break;
        }

    }
    if(r==0)
    {
        return 0;
    }
    else
        return 1;
}

int sEven(int index,int t)
{
    int i,j,k;
    if(index==s-1)
    {
        for(i=1;i<10;i++)
        {
            str[index]=48+i;
            str[s-index-1]=48+i;
            if(atoi(str)%m==0)
            {
                out[t]++;
                return atoi(str);
            }
        }
    }
    else
    {
        for(i=0;i<10;i++)
        {
            str[index]=48+i;
            str[s-index-1]=48+i;
            sEven(index+1,t);
            if(out[t]!=0)
                return atoi(str);
        }
    }
}

void sOdd(int index,int t)
{
    int i,j,k;
    if(index==s/2 && index!=s-1)
    {
        for(i=0;i<10;i++)
        {
            str[index]=48+i;
            sOdd(index+1,t);
            if(out[t]!=0)
                return atoi(str);
        }
    }
    else if(index==s-1)
    {
        for(i=1;i<10;i++)
        {

            str[index]=48+i;
            str[s-index-1]=48+i;
            if(atoi(str)%m==0)
            {
                out[t]++;
                return atoi(str);
            }
        }
    }
    else
    {
        for(i=0;i<10;i++)
        {
            str[index]=48+i;
            str[s-index-1]=48+i;
            sOdd(index+1,t);
            if(out[t]!=0)
                return atoi(str);
        }
    }

}


void even(int index,int t)
{
    int i,j,k;
    if(index==s-1)
    {
        for(i=1;i<10;i++)
        {
            str[index]=48+i;
            str[s-index-1]=48+i;
            if(atoi(str)%m==0)
                out[t]++;

        }
    }
    else
    {
        for(i=0;i<10;i++)
        {
            str[index]=48+i;
            str[s-index-1]=48+i;
            k=atoi(str);
            even(index+1,t);
        }
    }
}

void odd(int index,int t)
{
    int i,j,k;
    if(index==s/2 && index!=s-1)
    {
        for(i=0;i<10;i++)
        {
            str[index]=48+i;
            odd(index+1,t);
        }
    }
    else if(index==s-1)
    {
        for(i=1;i<10;i++)
        {
            str[index]=48+i;
            if(atoi(str)%m==0)
                out[t]++;
        }
    }
    else
    {
        for(i=0;i<10;i++)
        {
            str[index]=48+i;
            str[s-index-1]=48+i;
            odd(index+1,t);
        }
    }
}

int power(int x,int y)
{
    int i,j=1,k;
    for(i=0;i<y;i++)
        j=j*x;
    return j;
}
