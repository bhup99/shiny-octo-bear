#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

typedef struct T
{
    int leaf;
    struct T *child[26];
}trie;

class MessageMess
{
    trie *head;
    public:

    void insert(string dic)
    {
        trie *node = head;
        for(int i = 0; i < dic.size(); i++)
        {
            if(node->child[dic[i] - 'A'] == NULL)
                node->child[dic[i] - 'A'] = (trie *)calloc(27, sizeof(trie));
            node = node->child[dic[i] - 'A'];
        }
        node->leaf = 1;
    }

    int parse(string message, int iter)
    {
        int store;
        trie *node = head;
        while(node && !node->leaf && iter < message.size())
        {
            node = node->child[message[iter] - 'A'];
            iter++;
        }
        if(node == NULL)
            return -1;
        if(iter >= message.size() && node->leaf == 0)
            return -1;

        store = iter;
        node = node->child[message[iter++] - 'A'];
        if(node)
        cout << node->leaf << " " << iter << " ";
        while(node && !node->leaf && iter < message.size())
        {
            node = node->child[message[iter] - 'A'];
            iter++;
        }
        cout << node << " " << iter << endl;
        if(node && node->leaf == 1)
            return -2;
        return store;
    }

    string extract(string message, int start, int end)
    {
        string ret = "";
        for(int i = start; i < end; i++)
            ret += message[i];
        return ret;
    }

    string restore(vector <string> dictionary, string message)
    {
        string res = "";
        int store;
        head = (trie *)calloc(27, sizeof(trie));
        for(int i = 0; i < dictionary.size(); i++)
            insert(dictionary[i]);

        int iter = 0;

        while(iter < message.size())
        {
            store = iter;
            if(res.size() != 0)
                res += ' ';
            iter = parse(message, iter);
            if(iter == -1)
                return "IMPOSSIBLE!";
            if(iter == -2)
                return "AMBIGUOUS!";
            res += extract(message, store, iter);
            cout << endl;
        }
        return res;
    }
};

int main()
{
    vector<string> s;
    s.push_back("IMPOSS");
    s.push_back("SIBLE");
    s.push_back("S");
    s.push_back("IMPOSSIBLE");
    MessageMess ob;
    cout << ob.restore(s, "IMPOSSIBLE");
}
