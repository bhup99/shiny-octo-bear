#include<stdio.h>
int test,m,s,sub[50][1000];
long long out[20000]={0},output=1;
char str[20];
int main()
{
    int i,j,k;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        str[0]='\0';
        scanf("%d %d",&m,&s);
        if(m%10!=0)
        {
            strcpy(str,"0");
            for(j=0;j<s-1;j++)
                strcat(str,"0");

            str[0]='1';
            str[s-1]='1';
            output=strtoll(str,(char **)NULL,10);
            if(output%m!=0)
            {
                prepare(output%m);

                for(j=0;j<5;j++)
                {
                    k=0;
                    while(sub[j][k]<=m)
                    {
                        printf("%d\t",sub[j][k]);
                        k++;
                    }
                    printf("\n");
                }
                if(s%2==0)
                    even(s/2,i,output%m);

                else
                    odd(s/2,i,output%m);
            }

        }
    }
    for(i=0;i<test;i++)
        printf("%d\n",out[i]);
    return 0;
}


void even(int index,int t)
{
    int i,j,k;
    if(index==s-1)
    {
        if(m%5!=0 && m%2!=0)
        {
            for(i=1;i<10;i++)
            {
                str[index]=48+i;
                str[s-index-1]=48+i;
                if(strtoll(str,(char **)NULL,10)%m==0)
                {
                    out[t]++;
                }
            }
        }
        else if(m%2==0)
        {
            for(i=2;i<10;i+=2)
            {
                str[index]=48+i;
                str[s-index-1]=48+i;
                if(strtoll(str,(char **)NULL,10)%m==0)
                {
                    out[t]++;
                }
            }
        }

        else if(m%5==0)
        {
            str[index]=48+5;
            str[s-index-1]=48+5;
            if(strtoll(str,(char **)NULL,10)%m==0)
                out[t]++;
        }
    }
    else
    {
        for(i=0;i<10;i++)
        {
            str[index]=48+i;
            str[s-index-1]=48+i;
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
        if(m%5!=0 && m%2!=0)
        {
            for(i=1;i<10;i++)
            {
                str[index]=48+i;
                str[0]=48+i;
                if(strtoll(str,(char **)NULL,10)%m==0)
                    out[t]++;
            }
        }
        else if(m%2==0)
        {
            for(i=2;i<10;i+=2)
            {
                str[index]=48+i;
                str[0]=48+i;
                if(strtoll(str,(char **)NULL,10)%m==0)
                    out[t]++;
            }
        }
        else
        {
            str[index]=48+5;
            str[0]=48+5;
            if(strtoll(str,(char **)NULL,10)%m==0)
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

void prepare(int x)
{
    int i,j=0,k,l;
    for(i=0;i<5;i++)
    {
        k=0;
        j=0;
        l=m*(i+1);
        while((l-k)%x!=0)
        {
            k++;
        }
        while(1==1)
        {
            sub[i][j]=k+x*(j);
            if(sub[i][j]>m)
            {
                break;
            }
            j++;
        }
    }
}
