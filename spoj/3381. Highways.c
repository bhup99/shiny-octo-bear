#include<stdio.h>

typedef struct graph
{
    struct graph *next;
    int time,dest;
}graph;

typedef struct list
{
    int time,data;
    struct graph *value;
    struct list *next,*previous;
}link;

int main()
{
    int test,i,j,k;
    int n,m,start,end;
    int city1,city2,TravelTime;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        scanf("%d %d %d %d",&n,&m,&start,&end);
        n++;
        graph *heads[n],*node;
        for(j=0;j<n;j++)
            heads[j]=NULL;

        for(k=0;k<m;k++)
        {
            scanf("%d %d %d",&city1,&city2,&TravelTime);
            insert(n,&heads,city1,city2,TravelTime);
        }
        dijkstra(n,heads,start,end);
    }
    return 0;
}

void dijkstra(int n,graph *heads[n],int start,int end)
{
    int county[n],i,min;
    char check[n];
    for(i=0;i<n;i++)
    {
        county[i]=100000000;
        check[i]='w';
    }
    link *queue=calloc(5,sizeof(link)),*np,*iter1,*SuitableChoice=NULL;
    graph *node;
    queue->value=heads[start];
    queue->data=start;
    county[start]=0;
    while(queue!=NULL)
    {
        SuitableChoice = iter1 = queue;
        while(iter1!=NULL)
        {
            if(SuitableChoice->time>iter1->time)
                SuitableChoice=iter1;

            iter1=iter1->next;
        }
        min=SuitableChoice->data;
        if(SuitableChoice->next!=NULL && SuitableChoice->previous!=NULL)
        {
            SuitableChoice->previous->next=SuitableChoice->next;
            SuitableChoice->next->previous=SuitableChoice->previous;
        }
        else if(SuitableChoice->next==NULL && SuitableChoice->previous==NULL)
            queue=NULL;

        else if(SuitableChoice->previous==NULL)
        {
            queue=SuitableChoice->next;
            queue->previous=NULL;
        }
        else
            SuitableChoice->previous->next=NULL;

        node=NULL;
        if(check[min]!='b')
            node=heads[min];
        else
            queue=NULL;
        check[min]='b';
        while(node!=NULL)
        {
            if(check[node->dest]=='w')
            {
                check[node->dest]='g';
                np=calloc(5,sizeof(link));
                np->time=county[node->dest] = county[node->dest] = county[min]+node->time;
                np->value=node;
                np->data=node->dest;
                if(queue==NULL)
                    queue=np;
                else
                {
                    np->next=queue;
                    queue->previous=np;
                    queue=np;
                }

            }
            else if(check[node->dest]=='g' && county[node->dest]>county[min]+node->time)
            {
                county[node->dest]=county[min]+node->time;
            }
            node=node->next;
        }
        for(i=0;i<n;i++)
            printf("(%d,%d)\t",i,county[i]);
        printf("\n");

    }
    if(county[end]!=100000000)
        printf("%d\n",county[end]);
    else
        printf("NONE\n");
}

void insert(int n,graph *heads[n],int city1,int city2,int TravelTime)
{
    graph *np=calloc(1,sizeof(graph));
    np->dest=city2;
    np->time=TravelTime;
    if(heads[city1]==NULL)
        heads[city1]=np;
    else
    {
        np->next=heads[city1];
        heads[city1]=np;
    }
    np=calloc(1,sizeof(graph));
    np->dest=city1;
    np->time=TravelTime;
    if(heads[city2]==NULL)
        heads[city2] = np;
    else
    {
        np->next = heads[city2];
        heads[city2] = np;
    }
}
