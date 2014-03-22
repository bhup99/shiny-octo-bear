#include<stdio.h>
int n,inp[100][2],one=0,two=0,out[100][2],m;
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
    for(i=1;i<m;i++)
    {
        j=i;
        while(out[j][1]==out[i+1][1])
        {
            out[j][0]+=out[i+1][0];
            out[i+1][0]=0;
            i++;
        }
    }
    for(i=1;i<=m;i++)
    {
        inp[i][0]=out[i][0];
        inp[i][1]=out[i][1];
    }
    for(i=1;i<=m;i++)
    {
        divid(i);
    }
    if(one>two)
        printf("%d\n",one-two);
    else
        printf("%d\n",two-one);
    return 0;
}

void divid(int tes)
{
    int i,j,k=0;
    i=out[tes][0]/2;
    j=out[tes][0]-i;
    if(out[tes][0]==0)
        return 0;
    else if(one==two)
    {
        one+=out[tes][1]*i;
        two+=out[tes][1]*j;
        out[tes][0]=0;
    }
    else if(one<two)
    {
        if(two-one>=out[tes][0]*out[tes][1])
            one+=out[tes][1]*out[tes][0];
        else
        {
            one+=out[tes][1]*j;
            if(one>two)
            {
                while(one>two)
                {
                    one=one-out[tes][1];
                    k++;
                }
                one+=out[tes][1];
                k=k-1;
                out[tes][0]=out[tes][0]-j+k;
            }
            divid(tes);
        }
    }
    else if(two<one)
    {
        if(one-two>=out[tes][0]*out[tes][1])
            two+=out[tes][1]*out[tes][0];
        else
        {
            two+=out[tes][1]*j;
            if(one<two)
            {
                while(one<two)
                {
                    two=two-out[tes][1];
                    k++;
                }
                two+=out[tes][1];
                k=k-1;
                out[tes][0]=out[tes][0]-j+k;
            }
            divid(tes);
        }
    }
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
