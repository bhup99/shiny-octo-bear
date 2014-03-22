#include<stdio.h>
int n,one=0,two=0,out[100][2],m,input[100][2];
int main()
{
    int i,j,k;
    scanf("%d",&n);
    m=n;
    for(i=0;i<n;i++)
        scanf("%d %d",&input[i][0],&input[i][1]);

    compSort(n);
    for(i=1;i<=n;i++)
        printf("%d %d\n",out[i][0],out[i][1]);
    for(i=0;i<m;i++)
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
                    one=one-out[tes][1]*(j/2);
                    k+=j/2;
                }
                if(k>1)
                {
                    one+=out[tes][1];
                    k=k-1;
                }
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
                    two=two-out[tes][1]*(j/2);
                    k+=j/2;
                }
                if(k>1)
                {
                    two+=out[tes][1];
                    k=k-1;
                }
                out[tes][0]=out[tes][0]-j+k;
            }
            divid(tes);
        }
    }
}

int compSort(int n)
{
    int i,j,k=0,sub[30000]={0},max=0,total=0;
    for(i=0;i<n;i++)
    {
        if(max<input[i][1])
            max=input[i][1];
    }
    printf("%d",max);
    for(i=0;i<=max;i++)
        sub[i]=0;
    for(i=0;i<n;i++)
    {
        sub[input[i][1]]++;
    }

    for(i=1;i<=max;i++)
    {
        printf("%d\n",sub[i-1]);
        sub[i]+=sub[i-1];
    }
    for(i=0;i<=max;i++)
        total+=sub[i];
    for(i=n-1;i>=0;i--)
    {
        out[sub[input[i][1]]][0]=input[i][0];
        out[sub[input[i][1]]][1]=input[i][1];
        sub[input[i][1]]--;
    }
    return total;
}
