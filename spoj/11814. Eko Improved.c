#include<stdio.h>
long long n,m,out=0,inp[10000000]={0};
long long ou[10000000];
long long sub[10000000]={0},max=0,total=0,dist;


int main()
{
    long long i;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&inp[i]);
    compSort();
    for(i=1;i<=n;i++)
        inp[n-i]=ou[i];

    inp[n]=0;
    cal();
    return 0;
}

void cal()
{
    long long int j=1,k=0;
    long long x,y;
    while(out<m)
    {
        k=(inp[j-1]-inp[j])*j;
        if(out+k<m)
        {
            out+=k;
            y=inp[j];
        }
        else if((out+k)==m)
        {
            out+=k;
            y=inp[j];
            break;
        }
        else
        {
            x=inp[j-1];     y=inp[j];
            k=((x-y))*j;
            while((out+k<m || out+k>=m+j) && k!=0)
            {
                if(out+k>m)
                {
                    y=(x+y)/2;
                }
                else
                {
                    out=out+k;
                    x=y;
                    y=(inp[j]+y)/2;
                }
                k=((x-y))*j;
            }
            if(out+k>m+j || out+k==m+j)
            {
                k=k-j;
                y++;
                inp[j]++;
            }
            if(out+k<m)
            {
                k=k+j;
                y--;
                inp[j]--;
            }
            out+=k;
        }
        j++;
    }
    if(out)
        printf("%lld\n",y);
    else
        printf("%lld\n",inp[j-1]);

}

int compSort()
{
    for(dist=0;dist<n;dist++)
    {
        if(max<inp[dist])
            max=inp[dist];
    }
    for(dist=0;dist<=max;dist++)
        sub[dist]=0;
    for(dist=0;dist<n;dist++)
    {
        sub[inp[dist]]++;
    }

    for(dist=1;dist<=max;dist++)
    {
        sub[dist]+=sub[dist-1];
    }
    for(dist=n-1;dist>=0;dist--)
    {
        ou[sub[inp[dist]]]=inp[dist];
        sub[inp[dist]]--;
    }
    return 0;
}
