#include<stdio.h>
char inp[10000][100],l[10005][100],r[10005][100];

int merge(int left,int right,int length)
{
    int mid,i;
    static sub;
    if(left>=right)
        return 0;
    else
    {
        mid=(left+right)/2;
        sub++;
        merge(left,mid,length);
        merge(mid+1,right,length);
        mergeSort(left,mid,right);
    }
}

int mergeSort(int left,int mid,int right)
{
    int m,i,j,k,n1,n2;
    n1=mid-left+1;
    n2=right-mid;
    for(i=1;i<=n1;i++)
        strcpy(l[i],inp[i+left-1]);
    for(i=1;i<=n2;i++)
        strcpy(r[i],inp[i+mid]);
    i=1;	j=1;
    for(m=left;m<=right;m++)
    {
        if(i>n1 || j>n2)
            break;
        k=comp(i,j);
        if(k==1)
        {
            strcpy(inp[m],l[i]);
            i++;
        }
        else if(k==2)
        {
            strcpy(inp[m],r[j]);
            j++;
        }
    }
    while(i<=n1)
    {
        strcpy(inp[m],l[i]);
	i++;	m++;
    }
    while(j<=n2)
    {
        strcpy(inp[m],r[j]);
	j++;	m++;
    }
}


int comp(int fir,int two)
{
    int i,j,k,jus;
    i=strlen(l[fir]);
    j=strlen(r[two]);
    k=0;	jus=0;
    if(i==0 && j>0)
        return 2;
    if(i>0 && j==0)
        return 1;
    while(k<i && jus<j)
    {
        if(l[fir][k]<r[two][jus])
            return 1;
        else if(l[fir][k]>r[two][jus])
            return 2;
        else
	{
            k++;	jus++;
	}
    }
    if(i<j)
        return 1;
    else
        return 2;
}


char no[]={"NO"},yes[]={"YES"},out[40][3];
int n;
int main()
{
    int test,i,j;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%s",inp[j]);
        }
        merge(0,n,n);
        check(i);
    }
    for(i=0;i<test;i++)
        printf("%s\n",out[i]);
    return 0;
}

void check(int test)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        j=i+1;
        k=com(i,j);
        while(k<0 && j<n)
        {
            j++;
            k=com(i,j);
        }
        if(k==0)
        {
            strcpy(out[test],no);
            break;
        }
    }
    if(i==n-1)
        strcpy(out[test],yes);
}

int com(int head,int subs)
{
    int len,i,j;
    len=strlen(inp[head]);
    for(i=0;i<len;i++)
    {
        if(inp[head][i]!=inp[subs][i])
            break;
    }
    if(i==len)
        return 0;
    else
        return -1;
}
