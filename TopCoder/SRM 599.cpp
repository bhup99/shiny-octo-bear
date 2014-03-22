#include <iostream>
#include <vector>

typedef struct t
{
    struct t *child[26];
    int leaf, prefixof;
}trie;

class SimilarNames2
{
    public:

    trie *head;

    void SimilarNames2()
    {
        head = calloc(28, sizeof(head));
    }

    void insert(trie *head, string s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(head->child[s[i] - 'a'] == NULL)
                head->child[s[i] - 'a'] = calloc(28, sizeof(head));
            head = head->child[s[i] - 'a'];
        }
        head->leaf = 1;
    }

    int count(vector <string> names, int L)
    {
        for(int i = 0; i < names.size(); i++)
        {
            insert(head, names[i]);
        }

    }
}
