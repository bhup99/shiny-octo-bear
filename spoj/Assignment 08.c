#include<stdio.h>
#include<stdlib.h>
typedef struct abc
{
    int data,weight;
    struct abc *next,*pre;
}list;

typedef struct xyz
{
    int data,weight;
}kyu;

int main()
{
    list *adjList[10],*relieve,*nod1;
    int n,i,j,inp[10],src,checkNode[10]={0},s=0;
    int maxLength=1,no_of_edges,density;
    int firstNode,secondNode,subMat[10][10],wt;
    kyu queue[100],path[10],back;

    printf("Enter the total number of nodes present");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        inp[i]=i;
        adjList[i]=NULL;
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            subMat[i][j]=0;

    printf("Enter the density present");
    scanf("%d",&density);
    no_of_edges=((n*(n-1))/2)*(density/100.0);
    printf("%d\n",no_of_edges);

    for(i=0;i<no_of_edges;i++)
    {
        firstNode=rand()%n;
        secondNode=rand()%n;
        while(secondNode==firstNode || subMat[secondNode][firstNode]==1)
        {
            if(s==0)
            {
                secondNode=rand()%n;
                s=1;
            }
            else
            {
                firstNode=rand()%n;
                s=0;

            }
        }
        printf("%d %d\n",secondNode,firstNode);
        subMat[firstNode][secondNode]=1;
        subMat[secondNode][firstNode]=1;
        wt=rand()%100;
        insert(adjList,firstNode,secondNode,wt);
        insert(adjList,secondNode,firstNode,wt);
    }





    minHeapDijkstra(n,no_of_edges,queue,path,checkNode,maxLength,adjList);
    for(i=0;i<n;i++)
    {
        printf("%d %d\n",i,path[i].weight);
    }
}



void minHeapDijkstra(int n,int no_of_edges,kyu *queue,kyu *path,int *checkNode,int maxLength,list *adjList[10])
{
    int i,j,src;
    kyu back;
    list *nod1;
    printf("Enter the source vertex");
    scanf("%d",&src);
    nod1=adjList[src];
    while(nod1!=NULL)
    {
        queue[maxLength].data=nod1->data;
        checkNode[nod1->data]=1;
        queue[maxLength++].weight=nod1->weight;
        nod1=nod1->next;
    }
    for(i=0;i<n;i++)
    {
        printf("%d:- ",i);
        nod1=adjList[i];
        while(nod1!=NULL)
        {
            printf("(%d,%d) ",nod1->data,nod1->weight);
            nod1=nod1->next;
        }
        printf("\n");
    }
    minHeap(queue,1,maxLength/2,maxLength);
    checkNode[src]=2;
    path[src].weight=0;
    for(i=1;i<no_of_edges;i++)
    {
        back=queue[1];
        path[queue[1].data].weight=queue[1].weight;
        checkNode[back.data]=2;
        printf("%d has been extracted\n",back.data);
        extractMin(queue,1,maxLength);
        maxLength--;

        for(j=1;j<maxLength;j++)
            printf("(%d,%d) ",queue[j].data,queue[j].weight);

        printf("\n");

        printf("WTF\n");
        nod1=adjList[back.data];
        while(nod1!=NULL)
        {

            if(checkNode[nod1->data]==0)
            {
                queue[maxLength].data=nod1->data;
                queue[maxLength++].weight=nod1->weight+dist(adjList,back.data,nod1->data);
	        checkNode[nod1->data]=1;
            }

            else if(checkNode[nod1->data]==1)
            {
                for(j=0;j<maxLength;j++)
                {
                    if(queue[j].data==nod1->data)
                        break;
                }
                if(queue[j].weight > back.weight+dist(adjList,back.data,nod1->data))
                    queue[j].weight = back.weight+dist(back.data,nod1->data);
            }

            nod1=nod1->next;
        }

    }
}

int dist(list *adjList[10],int source,int dest)
{
    list *nod1;
    nod1=adjList[source];
    while(nod1!=NULL)
    {
        if(nod1->data == dest)
            return nod1->weight;

        nod1=nod1->next;
    }
}

int extractMin(kyu *queue,int start,int maxLength)
{
    kyu back;
    back=queue[start];
    queue[start]=queue[maxLength-1];
    heapify(queue,start,maxLength-1);

}

void heapify(kyu *queue,int start,int maxLength)
{
    if(start>=maxLength/2)
        return 0;
    int l,r,p,min;
    kyu back;
    p=start;
    l=p*2;
    r=p*2+1;
    min=p;
    if(queue[min].weight>queue[l].weight)
        min=l;

    if(r<maxLength && queue[min].weight>queue[r].weight)
	min=r;

    if(min!=p)
    {
        back=queue[p];
        queue[p]=queue[min];
        queue[min]=back;
        heapify(queue,min,maxLength);
    }
}

void minHeap(kyu *queue,int start,int end,int maxLength)
{
    int i,j,min;
    kyu back;
    if(start>end)
        return 0;

    for(i=end;i>=start;i--)
    {
        min=i;
        if(maxLength>i*2 && queue[min].weight>queue[i*2].weight)
            min=i*2;

        if(maxLength>i*2+1 && queue[min].weight>queue[i*2+1].weight)
            min=i*2+1;

        if(min!=i)
        {
            back=queue[i];
            queue[i]=queue[min];
            queue[min]=back;
            minHeap(queue,min,end,maxLength);
        }

    }
}

void insert(list *adjList[10],int firstNode,int secondNode,int wt)
{
    list *np;
    list *nod1,*nod2;
    np=malloc(sizeof(list));
    np->data=secondNode;
    np->next=NULL;
    np->weight=wt;

    if(adjList[firstNode]==NULL)
    {
        np->pre=NULL;
        adjList[firstNode]=np;
        return 0;
    }

    nod1=adjList[firstNode];

    while(nod1->next!=NULL)
    {
        nod1=nod1->next;
    }

    nod1->next=np;
    np->pre=nod1;
}

