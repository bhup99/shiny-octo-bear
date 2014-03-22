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

    for(i=1;i<=m;i++)
    {
        inp[i][0]=out[i][0];
        inp[i][1]=out[i][1];
    }
    for(i=m;i>=m;i--)
        divid(i);
    if(one>two)
        printf("%d\n",one-two);
    else
        printf("%d\n",two-one);
    return 0;
}

void divid(int x)
{
    

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
