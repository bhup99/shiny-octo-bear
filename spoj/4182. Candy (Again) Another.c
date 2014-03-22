#include<stdio.h>
long long one=0,two=0,sum=0,diff,diff1,fin,fin1,fin2,back;
int n,out[1000][2],m;
int main()
{
    int mid,i,j,k;
    scanf("%d",&n);
    m=n;
    for(i=0;i<n;i++)
        scanf("%d %d",&out[i][0],&out[i][1]);

    merge(0,n);
    for(i=1;i<n;i++)
    {
        j=i;
        while(out[j][1]==out[i+1][1])
        {
            out[j][0]+=out[i+1][0];
            out[i+1][0]=0;
            i++;
        }
    }
    for(i=1;i<=n;i++)
        sum+=out[i][0]*out[i][1];
    for(i=1;i<=n;i++)
    {
        divid(i);
        if(one>sum/2)
            break;
    }
    one=one-out[i][1];
    for(j=n;j>=i;j--)
    {
        divid(j);
        if(one>sum/2)
            break;
    }
    two=sum-one;
    diff=one-two;
    one=one-out[j][1];
    two=sum-one;
    diff1=two-one;
    if(diff1>=0 && (diff>diff1 || diff<0 ))
        fin1=diff1;
    else
        fin1=diff;
    one=0;
    two=0;
    for(i=m;i>0;i--)
    {
        divid(i);
        if(one>sum/2)
            break;
    }
    one=one-out[i][1];
    for(j=1;j<=i;j++)
    {
        divid(j);
        if(one>sum/2)
            break;
    }
    two=sum-one;
    diff=one-two;
    one=one-out[j][1];
    two=sum-one;
    diff1=two-one;
    if(diff1>=0 && (diff>diff1 || diff<0 ))
        fin=diff1;
    else
        fin=diff;

    if(fin1<fin)
        fin=fin1;
    one=0;
    two=0;
    for(i=1;i<=m;i++)
    {
        mid=out[i][0]/2;
        one+=out[i][1]*mid;
        out[i][0]=out[i][0]-mid;
    }
    back=one;
    for(i=1;i<=n;i++)
    {
        divid(i);
        if(one>sum/2)
            break;
    }
    two=sum-one;
    diff=one-two;
    one=one-out[i][1];
    two=sum-one;
    diff1=two-one;
    if(diff1>=0 && (diff>diff1 || diff<0 ))
        fin1=diff1;
    else
        fin1=diff;
    if(fin>fin1)
        fin2=fin1;
    else
        fin2=fin;
    one=back;
    for(i=n;i>=1;i--)
    {
        divid(i);
        if(one>sum/2)
            break;
    }
    two=sum-one;
    diff=one-two;
    one=one-out[i][1];
    two=sum-one;
    diff1=two-one;
    if(diff1>=0 && (diff>diff1 || diff<0 ))
        fin1=diff1;
    else
        fin1=diff;
    if(fin1>fin2)
        printf("%lld\n",fin2);
    else
        printf("%lld\n",fin1);
    return 0;
}

void divid(int i)
{
    if((one+(out[i][0]*out[i][1]))>sum/2)
        while(one<=sum/2)
        {
            one+=out[i][1];
        }
    else
        one+=out[i][0]*out[i][1];
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
    int l[100][2],r[100][2],n1,n2,i,j,k;
    n1=mid-left+1;
    n2=right-mid;
    for(i=1;i<=n1;i++)
    {
        l[i][0]=out[left+i-1][0];
        l[i][1]=out[left+i-1][1];
    }
    for(j=1;j<=n2;j++)
    {
        r[j][1]=out[mid+j][1];
        r[j][0]=out[mid+j][0];
    }

    l[n1+1][1]=100000;
    r[n2+1][1]=100000;

    i=1;    j=1;
    for(k=left;k<=right;k++)
    {
        if(l[i][1]<=r[j][1])
        {
            out[k][1]=l[i][1];
            out[k][0]=l[i][0];
            i++;
        }
        else
        {
            out[k][1]=r[j][1];
            out[k][0]=r[j][0];
            j++;
        }
    }

}
