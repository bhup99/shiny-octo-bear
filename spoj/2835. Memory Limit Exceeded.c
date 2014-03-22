#include<stdio.h>

int minDist,finDis[100000];

typedef struct  abc
{
    int x,y,h,index;
    struct abc *left,*right,*p;
}tree;

void insert(int **head,int a,int b,int i)
{
    tree *np,*side,*side1;
    np=malloc(sizeof(tree));
    np->left=NULL;
    np->right=NULL;
    np->index=i;
    np->x=a;
    np->y=b;
    if(*head==NULL)
    {
        np->p=NULL;
        *head=np;
        np->h=0;
    }
    else
    {
        side=*head;
        side1=*head;
        while(1)
        {
            if(side==NULL)
                break;
            side1=side;
            if(side->h==0)
            {
                if(side->x>a)
                    side=side->left;
                else
                    side=side->right;
            }
            else
            {
                if(side->y>b)
                    side=side->left;
                else
                    side=side->right;
            }
        }
        side=side1;
        np->p=side;
        np->h=(side->h+1)%2;
        if(side->h==0)
        {
            if(side->x>a)
                side->left=np;
            else
                side->right=np;
        }
        else
        {
            if(side->y>b)
                side->left=np;
            else
                side->right=np;
        }
    }
}

void botUp(tree *mHead,tree *sHead,tree *nod)
{
    tree *box,*back;
    box=nod;
    while(box->p!=NULL)
    {
        if(sqrt(minDist)>abs(nod->x-box->x) || sqrt(minDist)>abs(nod->y-box->y))
        {
            if(box==box->p->left && box->p->right!=NULL)
            {
                back=box->p->right;
                back->p=NULL;
                toDown(back,sHead);
                back->p=box->p;
            }
            else if(box==box->p->right && box->p->left!=NULL)
            {
                back=box->p->left;
                back->p=NULL;
                toDown(back,sHead);
                back->p=box->p;
            }
        }


        box=box->p;
    }
}

void toDown(tree *mHead,tree *sHead)
{
    tree *nod,*buck;
    int dis;
    nod=mHead;
    buck=mHead;
    while(nod!=NULL)
    {
        dis=pow(sHead->x-nod->x,2)+pow(sHead->y-nod->y,2);
        if(minDist>dis && dis!=0)
        {
            minDist=dis;
        }
        buck=nod;

        if(nod->h==0)
        {
            if(sHead->x>nod->x)
            {
                if(nod->right!=NULL)
                    nod=nod->right;
                else
                    nod=nod->left;
            }
            else
            {
                if(nod->left!=NULL)
                    nod=nod->left;
                else
                    nod=nod->right;
            }
        }
        else
        {
            if(sHead->y>nod->y)
                nod=nod->right;
            else
                nod=nod->left;

        }
    }
    botUp(mHead,sHead,buck);
}

void nNeighbour(tree *mHead,tree *sHead)
{
    tree *back;
    int s=0;
    if(sHead->left!=NULL)
        nNeighbour(mHead,sHead->left);


    minDist=100000;

    toDown(mHead,sHead);
    finDis[sHead->index]=minDist;


    if(sHead->right!=NULL)
        nNeighbour(mHead,sHead->right);
}

void inorder(tree *head)
{
    if(head->left!=NULL)
        inorder(head->left);
    printf("%d %d %d\n",head->x,head->y,head->h);
    if(head->right!=NULL)
        inorder(head->right);
}

int main()
{
    int test,n,i,j,a,b;
    tree *head=NULL;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        head=NULL;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d %d",&a,&b);
            insert(&head,a,b,j);
        }
        nNeighbour(head,head);
        for(j=0;j<n;j++)
            printf("%d\n",finDis[j]);
    }
    return 0;
}
