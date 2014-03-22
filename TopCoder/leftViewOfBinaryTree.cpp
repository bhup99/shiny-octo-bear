#include<iostream>
#include<stdlib.h>

using namespace std;

class tree
{
    typedef struct node
    {
        struct node *left, *right, *parent ;
        int data;
    }node;

    typedef struct list
    {
        struct list *next;
        node *sibling;
    }link;

    public:

    node *T ;
    void insert(int n)
    {
        node *np = (node *)calloc(3, sizeof(np)), *x, *y;
        np->data = n;
        if(T == NULL)
            T = np;
        else
        {
            x = y = T;
            while(x)
            {
                y = x;
                if(x->data < n)
                    x = x->right;
                else
                    x = x->left;
            }
            if(y->data < n)
                y->right = np;
            else
                y->left = np;
        }
    }

    void inorder(node *nod)
    {
        if(nod->left)
            inorder(nod->left);
        cout << nod->data << endl;
        if(nod->right)
            inorder(nod->right);
    }

    void leftView()
    {
        link *stack = NULL, *np, *tail, *x, *y;
        link *nod;
        np = (link *)calloc(1, sizeof(np));
        np->sibling = T;
        stack = tail = nod = np;
        while(nod!= NULL)
        {
            cout << nod->sibling->data << endl;
            x = tail;
            while(1)
            {
                if(nod->sibling->left)
                {
                    np = (link *)calloc(1, sizeof(np));
                    np->sibling = nod->sibling->left;
                    tail->next = np;
                    tail = np;
                }
                if(nod->sibling->right)
                {
                    np = (link *)calloc(1, sizeof(np));
                    np->sibling = nod->sibling->right;
                    tail->next = np;
                    tail = np;
                }
                if(nod == x)
                {
                    nod = nod->next;
                    break;
                }
                nod = nod->next;
            }
        }
    }

};

int main()
{
    tree ob1;
    int n, no;
    int i;
    cin >> n;
    ob1.T = NULL;
    for(i = 0; i < n; i++)
    {
        cin >> no;
        ob1.insert(no);
    }
    ob1.leftView();
}
