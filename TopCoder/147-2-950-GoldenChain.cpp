#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class GoldenChain
{
    public:
    int minCuts(vector <int> sections)
    {
        int joints, cut = 0, i = 0;
        joints = sections.size();
        sort(sections.begin(), sections.end());

        while(1)
        {
            cout << cut << " " << joints << endl;
            if(cut >= joints)
                return cut;
            if(sections[i] == 1)
                joints--;

            if(cut + 1 == joints)
            {
                cut ++;
                return cut;
            }
            cut++;
            sections[i]--;
            if(sections[i] == 0)
            {
                i++;
            }
        }
    }
};

int main()
{
    GoldenChain ob;
    vector<int> a;
    for(int i = 0; i < 50; i++)
        a.push_back(i + 1);
    /*for(int i = 0; i < 5;i++)
        a.push_back(10);
    for(int i = 0; i < 5;i++)
        a.push_back(1);*/
    cout << ob.minCuts(a);
}

