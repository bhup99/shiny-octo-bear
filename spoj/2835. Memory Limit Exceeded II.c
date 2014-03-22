#include<stdio.h>

int minDist,finDis[100000];
int med[2];

typedef struct  abc
{
    int x,y,h,index;
    struct abc *left,*right,*p;
}tree;

void sort(int left,int right,int n,int a[n][2])
{
    int i,j,temp[2];

    for(i=left;i<right-1;i++)
        for(j=left;j<right-i-1;j++)
            if(a[j+1]<a[j])
            {
                temp[0]=a[j][0];
                temp[1]=a[j][1];
                a[j][0]=a[j+1][0];
                a[j][1]=a[j+1][1];
                a[j+1][0]=temp[0];
                a[j+1][1]=temp[1];
            }


}

int median(int n,int inp[n][2],int height)
{
    int i;
    if(n<2)
    {
        med[0]=inp[0][0];
        med[1]=inp[0][1];
        return 0;
    }
    for(i=0;i<n;i+=5)
    {
        if(i+5<n)
        {
            sort(i,n,inp,height);
            if((n-i)%2==0)
            {
                inp[i/5][0]=inp[i+(n-i)%2][0];
                inp[i/5][1]=inp[i+(n-i)%2-1][1];

            }
            else
            {
                inp[i/5][0]=inp[i+(n-i)%2][0];
                inp[i/5][1]=inp[i+(n-i)%2][1];
            }
        }
        else
        {
            sort(i,i+5,inp,height);
            inp[i/5][0]=inp[i+2][0];
            inp[i/5][1]=inp[i+2][1];
        }

    }
}

void insert(int n,int inp[n][2],tree **head,int height)
{
    if(*head!=NULL)
        printf("%d",(*head)->left);
    printf("WTF\n");
    tree *l=NULL,*r=NULL,*np;
    int lArr[n][2],rArr[n][2],i,iter1=0,iter2=0;
    if(n<2)
        return 0;
    median(n,inp,(height+1)%2);
    for(i=0;i<n;i++)
    {
        if(inp[i][0]==med[0] && inp[i][1]==med[1])
            continue;
        if(inp[i][height]<med[height])
        {
            lArr[iter1][0]=inp[i][0];
            lArr[iter1][1]=inp[i][1];
            iter1++;
        }
        else
        {
            rArr[iter2][0]=inp[i][0];
            rArr[iter2][1]=inp[i][1];
            iter2++;
        }
    }
    np=malloc(sizeof(tree));
    np->left=l;
    np->right=r;
    np->x=med[0];
    np->y=med[1];
    np->p=*head;
    *head=np;
    l=r=np;
    insert(iter1,lArr,&l,(height+1)%2);
    insert(iter2,rArr,&r,(height+1)%2);
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
    int test,n,i,j,a,b,inp[100000][2];
    tree *head=NULL;
    scanf("%d",&test);
    for(i=0;i<test;i++)
    {
        head=NULL;
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d %d",&inp[j][0],&inp[j][1]);

        }
        insert(n,inp,&head,0);

        nNeighbour(head,head);
        for(j=0;j<n;j++)
            printf("%d\n",finDis[j]);
    }
    return 0;
}

