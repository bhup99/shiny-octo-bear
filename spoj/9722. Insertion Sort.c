#include<stdio.h>

typedef struct a
{
    int data,cur,orig;
}arr;

void MergeSort(arr input[100000],int left,int mid,int right,int n)
{
    int n1,n2;
    arr l[50000], r[50000];
    int i,j,k;
    n1 = mid-left+1;
    n2 = right-mid;
    for(i=0;i<n1;i++)
        l[i] = input[i+left];
    l[i].data = 100000;

    for(i=0;i<n2;i++)
        r[i] = input[i+1+mid];
    r[i].data = 100000;

    j = k = 0;
    for(i=left;i<=right;i++)
    {
        if(l[j].data<=r[k].data)
            input[i] = l[j++];
        else
            input[i] = r[k++];
    }
}



void Merge(arr input[100000],int left,int right,int n)
{
    if(left>=right)
        return;
    int mid;

    mid = (left+right)/2;
    Merge(input,left,mid,n);
    Merge(input,mid+1,right,n);


    MergeSort(input,left,mid,right,n);
}

int main()
{
    int test,n,i,j;
    int count;
    arr input[100000];
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
	count = 0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&(input[i].data));
            input[i].cur = input[i].orig = i;
        }
        Merge(input,0,n-1,n);
	for(j=0;j<n;j++)
	    if(input[j].orig>j)
        	count += input[j].orig-j;
	printf("%d\n",count);
    }
    return 0;
}

