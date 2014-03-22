#include<stdio.h>

typedef struct AdjList
{
    struct AdjList *next;
    int dest,cost;
}AdjLink;

int main()
{
    int s, n, i, nr, cost, j, k, r;
    int p[10000];
    scanf("%d",&s);
    char CityName[10000][10],name1[11],name2[11];
    AdjLink *heads[10000];

    for(i=0;i<s;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
            heads[j] = NULL;

        for(j=0;j<n;j++)
        {
            scanf("%s\n%d",CityName[j],p[j]);
            for(k=0;k<p[j];k++)
            {
                scanf("%d %d",nr,cost);
                insert(heads,j,nr,cost);
            }
        }
        scanf("%d",&r);
        for(j=0;j<r;j++)
        {
            scanf("%s %s",name1,name2)
        }
    }
}

void insert(AdjLink *heads[10000],int index,int nr,int cost)
{
    AdjLink *np = calloc(1,sizeof(np));
    np->dest = nr;
    np->cost = cost;
    if(heads[index]==NULL)
        heads[index] = np;
    else
    {
        np->next = heads[index];
        heads[index] = np;
    }
}
