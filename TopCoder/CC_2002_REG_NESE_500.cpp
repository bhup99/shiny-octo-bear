#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Checker
{
    public:

    bool CheckData(vector <string> param0)
    {
        bool valid = false;
        string names1, names2, loves;
        vector<string> secondary, primary;
        istringstream ss;

        if(param0.size() < 2 || param0.size() > 20)
            return false;

        for(int i = 0; i < param0.size(); i++)
            if(param0[i].size() > 40)
                return false;

        for(int i = 0; i < param0.size(); i++)
        {
            ss.str(param0[i]);
            ss >> names1;
            ss >> loves;
            ss >> names2;
            secondary.push_back(names2);
            primary.push_back(names1);
            if(loves != "LOVES")
                return false;
            if(param0[i][names1.size()] != ' ' || param0[i][names1.size() + 6] == ' ' || param0[i].size() != (names1.size() + names2.size() + 8))
                return false;

            for(int j = 0; j < names1.size(); j++)
                if(names1[j] != '-' || (names1[j] < 'A' && names1[j] > 'Z'))
                    return false;

            for(int j = 0; j < names2.size(); j++)
                if(names2[j] != '-' || (names2[j] < 'A' && names2[j] > 'Z'))
                    return false;
        }

        sort(secondary.begin(), secondary.end());
        sort(primary.begin(), primary.end());

        int j;
        for(int i = 0; i < secondary.size(); i++)
        {
            for(j = 0; j < primary.size(); j++)
            {
                if(secondary[i] == primary[j])
                    break;
            }
            if(j == primary.size())
                return false;
        }
        return true;

    }
};

int main()
{
    vector<string> s;
    s.push_back("D-G LOVES M");
    s.push_back("M LOVES D-G");
    s.push_back("T LOVES G");

}
