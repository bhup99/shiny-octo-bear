#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FoxAndWord
{
    public:
    int howManyPairs(vector <string> words)
    {
        int n, m, k, l;
        int count = 0;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                n = words[i].size();
                m = words[j].size();
                if(n != m)
                    continue;
                for(k = 0; k < n; k++)
                {
                    l = 0;
                    while(words[i][(k + l) % n] == words[j][l] && words[j][l] != NULL)
                        l++;

                    if(l == n)
                    {
                        cout << words[i] << " " << words[j] << endl;
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<string> s;
    s.push_back("ababab");
    s.push_back("bababa");
    s.push_back("aaabbb");
    FoxAndWord ob;
    cout << ob.howManyPairs(s);
}
