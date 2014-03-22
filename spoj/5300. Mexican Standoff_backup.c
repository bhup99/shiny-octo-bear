#include<stdio.h>
char inp[30][30][3][20],l[20][3][20],r[20][3][20];
main()
{
    int test,n[30],i,j,k,l,reTi[30];
    printf("Enter test cases");
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d",&n[i]);
        for(j=0;j<n[i];j++)
        {
            scanf("%s %s %s",inp[i][j][0],inp[i][j][1],inp[i][j][2]);
        }
    }
    for(i=0;i<test;i++)
    {
            merge(i,0,n[i]);
    }
    for(i=0;i<test;i++)
    {
        for(j=0;j<n[i];j++)
            printf("%s %s %s\n",inp[i][j][0],inp[i][j][1],inp[i][j][2]);
    }
}


int merge(int test,int left,int right)
{
    int mid,i;
    static sub;
    if(left>=right)
        return 0;
    else
    {
        mid=(left+right)/2;
        sub++;
        merge(test,left,mid);
        merge(test,mid+1,right);
        mergeSort(test,left,mid,right);
    }
}

int mergeSort(int test,int left,int mid,int right)
{
    int m,i,j,k,n1,n2;
    n1=mid-left+1;
    n2=right-mid;
    for(i=1;i<=n1;i++)
    {
        strcpy(l[i][0],inp[test][i+left-1][0]);
        strcpy(l[i][1],inp[test][i+left-1][1]);
        strcpy(l[i][2],inp[test][i+left-1][2]);
    }
    for(i=1;i<=n2;i++)
    {
        strcpy(r[i][0],inp[test][i+mid][0]);
        strcpy(r[i][1],inp[test][i+mid][1]);
        strcpy(r[i][2],inp[test][i+mid][2]);
    }
    i=1;	j=1;
    for(m=left;m<=right;m++)
    {
        if(i>n1 || j>n2)
            break;
        k=comp(test,i,j);
        if(k==1)
        {
            strcpy(inp[test][m][0],l[i][0]);
            strcpy(inp[test][m][1],l[i][1]);
            strcpy(inp[test][m][2],l[i][2]);
            i++;
        }
        else if(k==2)
        {
            strcpy(inp[test][m][0],r[j][0]);
            strcpy(inp[test][m][1],r[j][1]);
            strcpy(inp[test][m][2],r[j][2]);
            j++;
        }
    }
    while(i<=n1)
    {
        strcpy(inp[test][m][0],l[i][0]);
        strcpy(inp[test][m][1],l[i][1]);
        strcpy(inp[test][m][2],l[i][2]);
	i++;	m++;
    }
    while(j<=n2)
    {
        strcpy(inp[test][m][0],r[j][0]);
        strcpy(inp[test][m][1],r[j][1]);
        strcpy(inp[test][m][2],r[j][2]);
	j++;	m++;
    }
}


int comp(int test,int fir,int two)
{
    int i,j,k,jus;
    i=strlen(l[fir][0]);
    j=strlen(r[two][0]);
    k=0;	jus=0;
    if(i==0 && j>0)
        return 2;
    if(i>0 && j==0)
        return 1;
    while(k<i && jus<j)
    {
        if(l[fir][0][k]<r[two][0][jus])
            return 1;
        else if(l[fir][0][k]>r[two][0][jus])
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
