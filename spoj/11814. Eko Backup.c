#include<stdio.h>
long long n,m,out=0,inp[1000000];
long long l[1000000],r[1000000];
int main()
{
    long long i;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%lld",&inp[i]);
    merge(0,n);
    inp[n]=0;
    for(i=0;i<n;i++)
        printf("%d ",inp[i]);
    printf("\n");
    cal();
    printf("%d\n",out);
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
            out+=k;
        else if((out+k)==m)
        {
            out+=k;
            break;
        }
        else
        {
            x=inp[j-1];     y=inp[j];
            k=((x-y))*j;
            printf("%d\t",j);
            printf("%lld\t%lld\t",x,y);
            printf("%lld\n",k+out);
            while((out+k<m || out+k>=m+j) && k!=0)
            {
                if(out+k>m)
                {
                    printf("qwerty%lld %lld %lld %d\n",out+k,x,y,j);
                    y=(x+y)/2;
                    inp[j]=y;
                }
                else
                {
                    printf("ytrewq%lld %lld %lld %d\n",out+k,x,y,j);
                    out=out+k;
                    x=y;
                    y=inp[j-1];
                    x=x+(x-y)/2;
                    inp[j]=y;
                }
                k=((x-y))*j;
            }
            if(out+k>m+j)
            {
                k=k-j;
                inp[j]--;
            }
            else if(out+k<m || out+k==m+j)
            {
                k=k+j;
                inp[j]++;
            }
            out+=k;
            break;
        }
        j++;
    }
    if(out)
        out=inp[j];
    else
        out=inp[j-1];

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
