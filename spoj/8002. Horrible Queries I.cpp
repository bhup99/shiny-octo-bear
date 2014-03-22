#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct
{
    int low, high, childSum;
}segmentTree;

class treeQueries
{
    public:

    void addV(segmentTree *head, int p, int q, int v)
    {
        if(head->low == head->high && head->low >= p && head->high <= q)
            head->childSum += v;
        else if(q >= head->low && p <= head->high)
        {
            addV(head->left, p, q, v);
            addV(head->right, p, q, v);
            head->childSum = head->left->childSum + head->right->childSum;
        }
    }

    int sumOfPQ(segmentTree *head, int p, int q)
    {
        if(head->low >= p && head->high <= q)
            return head->childSum;

        if(head->high >= p && head->low <= q)
            return sumOfPQ(head->left, p, q) + sumOfPQ(head->right, p, q);

        return 0;
    }

    segmentTree* initialise(int low, int high)
    {
        segmentTree *newNode;j
        newNode = (segmentTree *)malloc(sizeof(segmentTree));
        newNode->low = low;
        newNode->high = high;
        newNode->childSum = 0;
        if(low >= high)
            newNode->left = newNode->right = NULL;
        else
        {
            newNode->left = initialise(low, (high + low) / 2);
            newNode->right = initialise((high + low) / 2 + 1, high);
        }
        return newNode;
    }

    void inorder(segmentTree *head)
    {
        if(head->left != NULL)
            inorder(head->left);
        cout << head->low << head->high << head->childSum << endl;
        if(head->right != NULL)
            inorder(head->right);
    }
};

class horribleQueries:public treeQueries
{
    int n, c;
    int num;
    segmentTree head[n + 1];
    public:

    void getData()
    {
        cin >> n >> c;
        segmentTree head[n + 1];
        for(int i = 0; i < c; i++)
        {
            cin >> num;
            if(num == 0)
            {
                zeroQuery();
            }
            else if(num == 1)
            {
                oneQuery();
            }
        }
    }

    void zeroQuery()
    {
        int p, q, v;
        cin >> p >> q >> v;
        addV(head, p, q, v);
        //inorder(head);
    }

    void oneQuery()
    {
        int p, q;
        cin >> p >> q;
        cout << sumOfPQ(head, p, q) << endl;
    }
};

int main()
{
    int test;
    cin >> test;
    horribleQueries ob;
    for(int i = 0; i < test; i++)
        ob.getData();
    return 0;
}

