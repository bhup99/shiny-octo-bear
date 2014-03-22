#include<stdio.h>
int test,m,s,sub[10][10000],global;
long long out[70000]={0},output=1;
char str[200];
int main()
{
    int i,j,k;
    long long back,star;
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
            if(s<15)
            {
                output=strtoll(str,(char **)NULL,10);
                global=output%m;
                if(global!=0)
                {
                    prepare(global);

                    if(s%2==0)
                        even(s/2,i);

                    else
                        odd(s/2,i);
                }
                else
                {
                    if(s%2==0)
                        even(s/2,i);

                    else
                        odd(s/2,i);
                }
            }
            else
            {
                back=str[s/2];
                str[s/2]='\0';
                output=strtoll(str,(char **)NULL,10);
                global=output%m;
                str[s/2]=back;
                output=strtoll(&str[s/2],(char **)NULL,10);
                output+=global*strlen(&str[s/2]);
                global=output%m;

                if(global!=0)
                {
                    prepare(global);

                    if(s%2==0)
                        even(s/2,i);

                    else
                        odd(s/2,i);
                }
                else
                {
                    if(s%2==0)
                        even(s/2,i);

                    else
                        odd(s/2,i);
                }
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
    long long star,back;
    if(index==s-1)
    {
        if(global!=0)
        {
            j=checkOut();
            if(j)
            {
                out[t]++;
            }
        }
        else if(global==0)
        {
            if(s<15)
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
                for(i=1;i<10;i++)
                {
                    str[index]=48+i;
                    str[0]=48+i;
                    back=str[s/2];
                    str[s/2]='\0';
                    output=strtoll(str,(char **)NULL,10);
                    star=output%m;
                    str[s/2]=back;
                    output=strtoll(&str[s/2],(char **)NULL,10);
                    output+=global*strlen(&str[s/2]);
                    star=output%m;
                    if(star==0)
                        out[t]++;

                }
            }
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
    long long star,back;
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
        if(global!=0)
        {
            j=checkOut();
            if(j)
            {
                out[t]++;
            }
        }
        else if(global==0)
        {
            if(s<15)
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
                for(i=1;i<10;i++)
                {
                    str[index]=48+i;
                    str[0]=48+i;
                    back=str[s/2];
                    str[s/2]='\0';
                    output=strtoll(str,(char **)NULL,10);
                    star=output%m;
                    str[s/2]=back;
                    output=strtoll(&str[s/2],(char **)NULL,10);
                    output+=global*strlen(&str[s/2]);
                    star=output%m;
                    if(star==0)
                        out[t]++;

                }
            }
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
    if(x!=0)
    {
        for(i=0;i<10;i++)
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
}

int checkOut()
{
    long long x;
    int i,j,y,just,style;
    x=strtoll(str,(char **)NULL,10);
    y=x%m;
    for(i=0;i<10;i++)
    {
        j=0;
        while(sub[i][j]<m)
        {
            if(sub[i][j]==y)
            {
                just=m*(i+1);
                just=just-sub[i][j];
                just=just/global;
                if(just<9)
                    return 1;
                else
                    return 0;
            }
            j++;
        }
    }
    return 0;
}
