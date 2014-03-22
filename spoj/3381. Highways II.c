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

typedef struct fibo
{
    int id,time,degree,mark;
    struct fibo *left,*right,*parent,*child;
}heap;


void dijkstra(int n,graph *heads[n],int start,int end)
{
    heap *H=calloc(8,sizeof(H)), **IndexAddress=calloc(8,sizeof(heap)*n);
    H->id = start;
    H->right = H->left = H;
    int county[n],i,min;
    char check[n];
    for(i=0;i<n;i++)
    {
        county[i] = 1000000;
        check[i] = 'w';
    }
    graph *node;
    county[start] = 0;
    while(H!=NULL)
    {
        min = ExtractMin(&H,n);
        if(check[min]!='b')
            node = heads[min];
        else
            node = H = NULL;
        check[min] = 'b';
        while(node!=NULL)
        {
            if(check[node->dest]=='w')
            {
                check[node->dest] = 'g';
                county[node->dest] = county[min]+node->time;
                HeapInsert(&H,county[node->dest],node->dest,IndexAddress);
            }
            else if(check[node->dest]=='g' && county[node->dest]>county[min]+node->time)
            {
                county[node->dest] = county[min]+node->time;
                DecreaseKey(&H,IndexAddress[node->dest],county[node->dest]);
            }
            node = node->next;
        }
    }
    if(county[end]!=1000000)
        printf("%d\n",county[end]);
    else
        printf("NONE\n");
}

int ExtractMin(heap **H,int n)
{
    heap *node,**order=calloc(8,sizeof(heap)*n),*back,*store,*x;
    node = back = (*H);
    if(node->right==node && node->child==NULL)
    {
        (*H)=NULL;
        return node->id;
    }
    node = (*H)->left;
    if((*H)->child!=NULL)
    {
        node = (*H)->child;
        if(node->right==node)
        {
            node->right = (*H)->right;
            node->left = (*H);
            (*H)->right->left = node;
            (*H)->right = node;
        }
        else
        {
            node->left = (*H);
            node->left->right = (*H)->right;
            (*H)->right->left = node->left;
            (*H)->right = node;
        }
    }
    (*H)->left->right = (*H)->right;
    (*H)->right->left = (*H)->left;
    x = (*H) = node;

    do
    {
        store=node->right;
        if(x->time>node->time)
            x=node;

        while(order[node->degree]!=NULL)
        {
            if(node->degree==0)
            {
                if(order[node->degree]->time>node->time)
                    Relate(node,order[node->degree]);
                else
                {
                    Relate(order[node->degree],node);
                    node=order[node->degree];
                }
            }
            else
            {
                if(order[node->degree]->time>node->time)
                    Relate(node,order[node->degree]);
                else
                {
                    Relate(order[node->degree],node);
                    node=order[node->degree];
                }

            }
            order[node->degree-1]=NULL;
        }
        order[node->degree] = node;
        node=store;
    }while(node!=(*H));
    return back->id;
}

void Relate(heap *p,heap *c)
{
    c->right->left = c->left;
    c->left->right = c->right;
    c->parent=p;

    if(p->degree==0)
    {
        c->right = c->left = c;
        p->child=c;
    }
    else
    {
        c->right=p->child;
        c->left=p->child->left;
        p->child->left = p->child->left->right= c;
    }

    p->degree++;
}

void DecreaseKey(heap **H,heap *x,int k)
{
    heap *y,*back;
    y=x->parent;
    x->time=k;
    if(y!=NULL && k<y->time)
    {
        cut(*H,x,y);
        CascadingCut(*H,y);
    }
    if(k<(*H)->time)
        (*H)=x;
}

void cut(heap *H,heap *x,heap *y)
{
    if(y->child==x)
    {
        if(y->degree==1)
            y->child=NULL;
        else
        {
            y->child=x->right;
            x->right->left=x->left;
            x->left->right = x->right;
        }
    }
    else
    {
        x->right->left=x->left;
        x->left->right = x->right;
    }
    y->degree--;
    x->right = H->right;
    x->left = H;
    x->mark=0;
    x->parent=NULL;
    H->right->left=x;
    H->right=x;
}

void CascadingCut(heap *H,heap *y)
{
    heap *z;
    z=y->parent;
    if(z!=NULL)
    {
        if(y->mark==0)
            y->mark=1;
        else
        {
            cut(H,y,z);
            CascadingCut(H,z);
        }
    }
}


void HeapInsert(heap **H,int time,int value,heap **IndexAddress)
{
    heap *np=calloc(8,sizeof(np));
    np->time=time;
    np->id=value;
    *(IndexAddress+value)=np;
    if(*H==NULL)
        *H=np->right=np->left=np;
    else
    {
        np->right=(*H)->right;
        np->left=(*H);
        (*H)->right->left=np;
        (*H)->right=np;
    }
    if((*H)->time>time)
        (*H)=np;
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
        heads[city2]=np;
    else
    {
        np->next=heads[city2];
        heads[city2]=np;
    }
}


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
            if(city1!=city2)
                insert(n,&heads,city1,city2,TravelTime);
        }
        dijkstra(n,heads,start,end);
    }
    return 0;
}