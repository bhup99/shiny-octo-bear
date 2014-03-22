#include<stdio.h>

typedef struct node
{
    struct node *left,*right;
    int data,c;
}tree;

int main()
{
    int n,i,number,j;
    scanf("%d",&n);
    tree *head=NULL, *AddStore[n+1];
    for(i=0;i<n;i++)
    {
        scanf("%d",&number);
        insert(&head,number,n,AddStore);
    }
    return 0;
}

void insert(tree **head,int number,int max,tree *AddStore[max+1])
{
    static int count=0;
    int i, pre;
    tree *np=calloc(2,sizeof(tree)), *x,*y;
    np->data = number;

    if(*head==NULL)
    {
        *head = np;
        np->c = 0;
        for(i=1;i<=max;i++)
            AddStore[i] = np;
    }

    else if(number > AddStore[number]->data)
    {
        np->c = AddStore[number]->c+1;
        AddStore[number]->right = np;
        pre = i = AddStore[number]->data;
        i++;
        while(AddStore[i]->data==pre && i<=max)
        {
            AddStore[i] = np;
            i++;
        }
    }
    else
    {
        np->c = AddStore[number]->c+1;
        AddStore[number]->left = np;
        pre = i = AddStore[number]->data;
        i--;
        while(AddStore[i]->data==pre && i>0)
        {
            AddStore[i] = np;
            i--;
        }
    }
    count += np->c;
    printf("%d\n",count);
}
