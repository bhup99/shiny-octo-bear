#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef struct T
{
    struct T *child[26];
}node;

class trie
{
    public:

    node *head;
    int count;

    trie()
    {
        head = (node *)calloc(26, sizeof(node));
        count = 0;
    }

    void insert(string input)
    {
        node *iterator = head;
        for(int i = 0; i < input.size(); i++)
        {
            if(iterator->child[input[i] - 'a'] == NULL)
            {
                iterator->child[input[i] - 'a'] = (node *)calloc(26, sizeof(node));
                count ++;
            }
            iterator = iterator->child[input[i] - 'a'];
        }
    }
    int printNodes()
    {
        return count;
    }
};

int main()
{
    trie ob;
    int test;
    string s;
    cin >> test;
    for(int i = 0; i < test; i++)
    {
        cin >> s;
        ob.insert(s);
    }
    cout << ob.printNodes() + 1 << endl;
}
