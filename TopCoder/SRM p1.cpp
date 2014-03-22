#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<stdlib.h>


using namespace std;

class BinaryCode
{
    public:
    vector<string> decode(string input)
    {
        vector<string> out;
        int i;
        if(input.size()<=1 && input[0]!='0')
            out.push_back("NONE");
        else if(input.size()<=1 && input[0]=='0')
            out.push_back("0");
        else
        {
            out.push_back("0");
            out[0] += input[0];
            for(i=1;i<input.size()-1;i++)
            {
                out[0] += input[i] - out[0][i-1] - out[0][i] + '0'+'0';
            }

        }
        if(input[input.size()-1]!=(out[0][out[0].size()-1]+out[0][out[0].size()-2]-'0'))
            out[0] = "NONE";
        else
            for(i=0;i<input.size();i++)
                if(out[0][i]!='0' && out[0][i]!='1')
                {
                    out[0] = "NONE";
                    break;
                }

        if(input.size()<=1 && input[0]!='1')
            out.push_back("NONE");
        else if(input.size()<=1 && input[0]=='1')
            out.push_back("1");
        else
        {
            out.push_back("1");
            out[1] += input[0] - '1'+'0';
            for(i=1;i<input.size()-1;i++)
            {
                out[1] += (input[i] + '0' - out[1][i-1] ) +'0' -out[1][i];
            }
        }
        if(input[input.size()-1]!= out[1][out[1].size()-1]+out[1][out[1].size()-2]-'0')
            out[1] = "NONE";
        else
            for(i=0;i<out[1].size();i++)
            {
                if(out[1][i]!='0' && out[1][i]!='1')
                {
                    out[1] = "NONE";
                    break;
                }
            }
        return out;
    }

};


int main()
{
    BinaryCode ob1;
    vector<string> out;
    out = ob1.decode("123210122");
    cout<<out[0]<<endl<<out[1];
}

