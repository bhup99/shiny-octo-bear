#include<stdio.h>
long long n,m,out=0,inp[1000000];
long long l[1000000],r[1000000];
int main()
{
    long long i;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&inp[i]);
    merge(0,n);
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
void merge(int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        merge(left,mid);
        merge(mid+1,right);
        merge_sort(left,mid,right);
    }
}

void merge_sort(int left,int mid,int right)
{
    long long n1,n2,i,j,k;
    n1=mid-left+1;
    n2=right-mid;
    for(i=1;i<=n1;i++)
        l[i]=inp[left+i-1];
    for(j=1;j<=n2;j++)
        r[j]=inp[mid+j];

    l[i]=0;
    r[j]=0;

    i=1;    j=1;
    for(k=left;k<=right;k++)
    {
        if(l[i]>=r[j])
        {
            inp[k]=l[i];
            i++;
        }
        else
        {
            inp[k]=r[j];
            j++;
        }
    }

}
