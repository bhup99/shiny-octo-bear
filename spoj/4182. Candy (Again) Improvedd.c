#include<stdio.h>
int n,inp[100][2],one=0,two=0,out[100][2],m,sum=0,fin,fin2;
int diff,diff1;
int main()
{
    int i,j,k;
    scanf("%d",&n);
    m=n;
    for(i=1;i<=n;i++)
        scanf("%d %d",&inp[i][0],&inp[i][1]);
    for(i=n/2;i>0;i--)
    {
        heap(i);
    }
    heapSort();
    for(i=1;i<=m;i++)
    {
        sum+=out[i][0]*out[i][1];
    }
    for(i=1;i<=m;i++)
    {
        divid(i);
        printf("%d \t",one);
        if(one>sum/2)
            break;
    }
    one=one-out[i][1];
    printf("%d\n",one);
    for(j=m;j>=i;j--)
    {
        divid(j);
        if(one>sum/2)
            break;
    }
    two=sum-one;
    printf("%d %d %d\n",one,two,j);
    diff=one-two;
    one=one-out[j][1];
    two=sum-one;
    diff1=two-one;
    if(diff1>=0 && (diff>diff1 || diff<0 ))
        fin=diff1;
    else
        fin=diff;
    printf("%d\n",fin);
    one+=out[j][1];
    two=sum-one;
    for(j=m;j>=i;j--)
    {
        diff=0;
        while(diff<one-two-out[j][1] && diff>=0 && inp[j][0]>0)
        {
            one-=out[j][1];
            two=sum-one;
            diff=one-two;
            inp[j][0]--;
        }
        if(diff<=0)
            break;
    }
    two=sum-one;
    diff=one-two;
    one=one-out[j][1];
    two=sum-one;
    diff1=two-one;
    if(diff1>=0 && (diff>diff1 || diff<0 ))
        fin2=diff1;
    else
        fin2=diff;
    printf("%d\n",fin2);
    if(fin<fin2)
        printf("%d",fin);
    else
        printf("%d",fin2);
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

void heap(int tes)
{
    int i,j,k,l,r;
    l=2*tes;
    r=2*tes+1;
    if(l<=n)
    {
        if(r<=n)
        {
            if(inp[l][1]>inp[r][1])
                i=l;
            else
                i=r;
        }
        else
            i=l;
        if(inp[tes][1]<inp[i][1])
        {
            j=inp[tes][0];
            k=inp[tes][1];
            inp[tes][1]=inp[i][1];
            inp[tes][0]=inp[i][0];
            inp[i][0]=j;
            inp[i][1]=k;
            heap(i);
        }
    }
}

void heapSort()
{
    int i;
    for(i=1;i<=m;i++)
    {
        out[i][0]=inp[1][0];
        out[i][1]=inp[1][1];
        inp[1][0]=inp[n][0];
        inp[1][1]=inp[n][1];
        heap(1);
        n--;
    }
}

