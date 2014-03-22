#include<stdio.h>
int test,y,w,x,m,check[100000]={0},order[100000];
long long sub[20002];
char a[105],b[105],n[105],need[105];
int main()
{
    int i,j,k=0,l;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        sub[i]=1;
        scanf("%s %s %s %d",a,b,n,&m);
        modify();
        if(n[0]=='0')
            printf("%d\n",1);
        else
        {
            for(j=0;j<y;j++)
            {
                sub[i]=(w*sub[i]+x);
                if(sub[i]>=m)
                    sub[i]=sub[i]%m;
                if(check[sub[i]])
                    break;

                check[sub[i]]=1;
                order[k++]=sub[i];
            }
            l=k;
            for(j=0;j<k;j++)
                check[order[j]]=0;
            k=y%k;

            if(k)
                sub[i]=order[k];
            else
                sub[i]=order[l-1];

            k=0;
        }

    }
    for(i=0;i<test;i++)
        printf("%lld\n",sub[i]);
    return 0;
}

void modify()
{
    if(strlen(a)>5)
        w=atoi(&a[strlen(a)-5]);
    else
        w=atoi(a);
    if(strlen(b)>5)
        x=atoi(&b[strlen(b)-5]);
    else
        x=atoi(b);
    if(strlen(n)>5)
        strcpy(n,&n[strlen(n)-5]);
    else
        y=atoi(n);
}

