#include<stdio.h>

typedef struct node
{
    struct node *left,*right;
    int data;
}tree;

int main()
{
    int n,i,number;
    tree *head=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&number);
        insert(&head,number);
    }
    return 0;
}

void insert(tree **head,int number)
{
    static int count=0;
    tree *np=calloc(2,sizeof(tree)), *x,*y;
    np->data = number;

    if(*head==NULL)
        *head = np;

    else
    {
        x = y = *head;
        while(x!=NULL)
        {
            y=x;
            count++;
            if(x->data > number)
                x = x->left;
            else
                x = x->right;
        }
        if(y->data>number)
            y->left = np;
        else
            y->right = np;
    }
    printf("%d\n",count);
}
