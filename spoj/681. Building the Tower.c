#include<stdio.h>

typedef struct abc
{
    int key,height,sum;
    struct abc *left,*right,*parent;
}tree;

int test,n[30],h[30],m[30],out[30]={0};
int main()
{
    tree *head=NULL;
    int i,j;
    scanf("%d",&test);
    for(i=0;i<test;i++)
        scanf("%d %d %d",&n[i],&h[i],&m[i]);

    for(i=0;i<test;i++)
        for(j=0;j<h[i];j++)
            insert(i,&head);

    for(i=0;i<test;i++)
    {
        scan(i,head);
        printf("%d\n",out[i]);
    }
}

int scan(int test,tree *head)
{
    if(head->left!=NULL)
        scan(test,head->left);
    if(head->height==h[test] && head->sum<=n[test])
        out[test]++;
    if(head->right!=NULL)
        scan(test,head->right);
}

int insert(int test,tree **head)
{
    tree *np;
    int i,j,k;
    if(*head==NULL)
    {
        np=malloc(sizeof(tree));
        np->left=NULL;
        np->right=NULL;
        if(*head==NULL)
        np->key=m[test];
        np->sum=m[test];
        np->height=1;
        np->parent=*head;
        *head=np;
    }
    else
    {
        inorder(test,head);
    }
}

int inorder(int test,tree **head)
{
    tree *nod,*np;
    nod=malloc(sizeof(tree));
    np=malloc(sizeof(tree));
    nod->left=NULL; nod->right=NULL;
    np->left=NULL;  np->right=NULL;
    if((*head)->left!=NULL)
        inorder(test,&((*head)->left));
    if((*head)->left==NULL && (*head)->right==NULL && (*head)->sum<n[test])
    {
        nod->parent=*head;      np->parent=*head;
        if(((*head)->key-1))
        {
            nod->key=(*head)->key-1;
            nod->sum=(*head)->sum+nod->key;
            np->height=nod->height=(*head)->height+1;
            np->key=(*head)->key+1;
            np->sum=(*head)->sum+np->key;
            (*head)->right=np;
            (*head)->left=nod;
        }
        else if(!((*head)->key-1))
        {
            np->height=(*head)->height+1;
            np->key=(*head)->key+1;
            np->sum=(*head)->sum+np->key;
            (*head)->right=np;
        }
        else
        {
            nod->key=(*head)->key-1;
            nod->sum=(*head)->sum+nod->key;
            nod->height=(*head)->height+1;
        }
    }
    if((*head)->right!=NULL)
        inorder(test,&((*head)->right));
}
