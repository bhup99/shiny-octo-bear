#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <stdlib.h>


using namespace std;

typedef struct stringNode
{
    struct stringNode *child[26];
    int LORCount[2], solved;
    int correspondingIndex, index;
}stringNode;

typedef struct countNode
{
    struct countNode *child[10];
    vector<int> rows;
}countNode;

int n;

class stringOperation
{
    public:

    stringNode *stringEncodedHead, *stringDecodedHead;
    vector< vector<string> > encodedTable, decodedTable;
    vector<string> encodedString, decodedString;
    countNode *countHead, *stringCountHead;
    int solvedCount;

    stringOperation()
    {
        solvedCount = 0;
    }


    void sort()
    {
        int j;
        for(int i = 1; i < encodedString.size(); i++)
        {
            j = i - 1;
            string temp;
            while(j >= 0 && lexicographical_compare(encodedString[j + 1].begin(), encodedString[j + 1].end(), encodedString[j].begin(), encodedString[j].end()))
            {
                temp = encodedString[j + 1];
                encodedString[j + 1] = encodedString[j];
                encodedString[j] = temp;
                j--;
            }
        }
    }

    int strcmp(string a, string b)
    {
        int i = 0;
        if(a.size() != b.size())
            return 1;
        while(i < a.size())
        {
            if(a[i] != b[i])
                return 1;
            i++;
        }
        return 0;
    }

    vector<string> split(string str)
    {
        vector<string> output;
        istringstream iss(str);
        iss >> str;
        output.push_back(str);
        iss >> str;
        output.push_back(str);
        return output;
    }

    int charToInt(char c)
    {
        if(c >='A' && c <= 'Z')
            return c - 'A';

        else if(c >= 'a' && c <= 'z')
            return c - 'a';
    }

    int solveCount(vector<string> str, stringNode *stringEncodedHead, vector<int> rowCounts)
    {
        string decodedRow;
        countNode *countIter = countHead;
        for(int i = 0; i < 2; i++)
            countIter = countIter->child[rowCounts[i]];

        for(int i = 0; i < 2; i++)
        {
            stringNode *iter = stringEncodedHead, *decodedIter;
            for(int j = 0; j < str[i].size(); j++)
            {
                iter = iter->child[charToInt(str[i][j])];
            }

            decodedRow = decodedTable[countIter->rows[0]][i];
            decodedIter = stringDecodedHead;

            for(int j = 0; j < decodedRow.size(); j++)
            {
                decodedIter = decodedIter->child[charToInt(decodedRow[j])];
            }
            iter->correspondingIndex = decodedIter->index;
            iter->solved = 1;
        }
    }

    int getIndex(stringNode *head, string s)
    {
        stringNode *stringIter = head;
        for(int i = 0; i < s.size(); i++)
            stringIter = stringIter->child[charToInt(s[i])];
    }

    int isSolved(string s)
    {
        stringNode *stringIter = stringEncodedHead;
        for(int i = 0; i < s.size(); i++)
            stringIter = stringIter->child[charToInt(s[i])];
        return stringIter->solved;
    }

    void doExtract(string solvedString, string unsolvedString, int leftOrRight, vector<int> rowCounts)
    {
        int countSolvedString = 0, store = -1;
        countNode *countIter = countHead;
        stringNode *encodedSolvedIter = stringEncodedHead;
        stringNode *encodedUnsolvedIter = stringEncodedHead;
        for(int i = 0; i < solvedString.size(); i++)
        {
            encodedSolvedIter = encodedSolvedIter->child[charToInt(solvedString[i])];
        }

        for(int i = 0; i < unsolvedString.size(); i++)
        {
            encodedUnsolvedIter = encodedUnsolvedIter->child[charToInt(unsolvedString[i])];
        }

        for(int i = 0; i < 2; i++)
        {
            countIter = countIter->child[rowCounts[i]];
        }

        for(int i = 0; i < countIter->rows.size(); i++)
        {
            if(strcmp(decodedString[encodedSolvedIter->index], decodedTable[countIter->rows[i]][0]) == 0)
            {
                countSolvedString++;
                store = i;
            }
            if(strcmp(decodedString[encodedSolvedIter->index], decodedTable[countIter->rows[i]][1]) == 0)
            {
                countSolvedString++;
                store = i;
            }
        }
        if(countSolvedString == 1)
        {
            encodedUnsolvedIter->solved = 1;

            if(strcmp(decodedString[encodedSolvedIter->index], decodedTable[countIter->rows[store]][0]) == 0)
                encodedUnsolvedIter->correspondingIndex = getIndex(stringDecodedHead, decodedTable[countIter->rows[store]][1]);
            else
                encodedUnsolvedIter->correspondingIndex = getIndex(stringDecodedHead, decodedTable[countIter->rows[store]][0]);
        }
    }

    void checkCountUnique(vector<int> stringCounts, countNode *stringCountHead, string s)
    {
        int countSolved = 0, solvedIndex;
        stringNode *stringIter = stringEncodedHead, *stringDecodedIter;
        countNode *countIter = stringCountHead;

        for(int i = 0; i < s.size(); i++)
            stringIter = stringIter->child[charToInt(s[i])];
        if(stringIter->solved == 1)
            return;

        for(int i = 0; i < 2; i++)
            countIter = countIter->child[stringCounts[i]];

        if(countIter->rows.size() == 1)
        {
            stringIter->correspondingIndex = countIter->rows[0];
            solvedCount++;
        }
        else
        {
            for(int i = 0; i < countIter->rows.size(); i++)
            {
                stringDecodedIter = stringDecodedHead;
                for(int j = 0; j < encodedString[countIter->rows[i]].size(); j++)
                    stringDecodedIter = stringDecodedIter->child[charToInt(encodedString[countIter->rows[i]][j])];

                if(stringDecodedIter->solved == 1)
                {
                    countSolved++;
                    solvedIndex = i;
                }
                if(countSolved > 1)
                    return;
            }
            stringIter->solved = 1;
            stringIter->correspondingIndex = solvedIndex;
        }
    }
};

class trie:public stringOperation
{
    public:

    int searchCountTrie(countNode *head, vector<int> rowCounts)
    {
        countNode *iter = head;
        for(int i = 0; i < 2; i++)
            iter = iter->child[rowCounts[i]];
        if(iter->rows.size() == 1)
            return 1;
        else
            return 0;
    }

    void stringInsert(stringNode *head, string str, int leftOrRight, int EOD)        // to insert the count of left and right string in a row
    {
        stringOperation objectString;
        int x, isStringPresent = 1;
        for(int i = 0; i < str.size(); i++)
        {
            x = charToInt(str[i]);
            if(head->child[x] == NULL)
            {
                head->child[x] = (stringNode *)calloc(29, sizeof(stringNode));
                isStringPresent = 0;
            }
            head = head->child[x];
        }
        head->LORCount[leftOrRight]++;
        if(!isStringPresent)
        {
            if(EOD == 0)
            {
                head->index = encodedString.size();
                encodedString.push_back(str);
            }
            else
            {
                head->index = decodedString.size();
                decodedString.push_back(str);
            }
        }
    }

    void countInsert(countNode *head, vector<int> stringCounts, int index)      // to insert the left and right counts of a string in  the trie
    {
        for(int i = 0; i < 2; i++)
        {
            if(head->child[stringCounts[i]] == NULL)
                head->child[stringCounts[i]] = (countNode *)calloc(10, sizeof(countNode));
            head = head->child[stringCounts[i]];
        }
        head->rows.push_back(index);
    }

    void columnCountInsert(countNode *head, vector<int> colCounts, int index)
    {
        for(int i = 0; i < 2; i++)
        {
            if(head->child[colCounts[i]] == NULL)
                head->child[colCounts[i]] = (countNode *)calloc(10, sizeof(countNode));
            head = head->child[colCounts[i]];
        }
        head->rows.push_back(index);
    }

};

class translation:public trie
{
    public:

    stringOperation stringObject;
    trie trieObject;
    int dualEncodedStringIndex, countDualString, dualDecodedStringIndex;

    translation()
    {
        countDualString = 0;
        stringEncodedHead = (stringNode *)calloc(28, sizeof(stringNode));
        stringDecodedHead = (stringNode *)calloc(28, sizeof(stringNode));
        countHead = (countNode *)calloc(10, sizeof(countNode));
        stringCountHead = (countNode *)calloc(10, sizeof(countNode));

        getInput();
        for(int i = 0; i < n; i++)
        {
            stringInsert(stringEncodedHead, encodedTable[i][0], 0, 0);
            stringInsert(stringEncodedHead, encodedTable[i][1], 1, 0);
            if(strcmp(encodedTable[i][0], encodedTable[i][1]) == 0)
            {
                dualEncodedStringIndex = encodedString.size();
                countDualString++;
            }

            stringInsert(stringDecodedHead, decodedTable[i][0], 0, 1);
            stringInsert(stringDecodedHead, decodedTable[i][1], 1, 1);

            if(strcmp(decodedTable[i][0], decodedTable[i][1]) == 0)
                dualDecodedStringIndex = decodedString.size();
        }

        for(int i = 0; i < n; i++)
        {
            vector<int> v;
            v = makeVector(getCount(stringDecodedHead, decodedTable[i][0], 0), getCount(stringDecodedHead, decodedTable[i][1], 1));
            trieObject.countInsert(countHead, v, i);
        }

        for(int i = 0; i < encodedString.size(); i++)
        {
            vector<int> v;
            v = makeVector(getCount(stringEncodedHead, encodedString[i], 0), getCount(stringEncodedHead, encodedString[i], 1));
            trieObject.columnCountInsert(stringCountHead, v, i);
        }
    }

    void getInput()
    {
        string str;
        for(int i = 0; i < n; i++)
        {
            getline(cin, str, '\n');
            encodedTable.push_back(stringObject.split(str));
        }

        for(int i = 0; i < n; i++)
        {
            getline(cin, str, '\n');
            decodedTable.push_back(stringObject.split(str));
        }
    }

    int getCount(stringNode *head, string s, int leftOrRight)
    {
        stringNode *iter = head;
        for(int i = 0; i < s.size(); i++)
            iter = iter->child[stringObject.charToInt(s[i])];

        return iter->LORCount[leftOrRight];
    }

    vector<int> makeVector(int a, int b)
    {
        vector<int> out;
        out.push_back(a);
        out.push_back(b);
        return out;
    }

    void dualCaseHandle()
    {
        if(countDualString != 1)
            return;

        stringNode *stringEncodedIter= stringEncodedHead;
        for(int i = 0; i < encodedString[dualEncodedStringIndex].size(); i++)
            stringEncodedIter = stringEncodedIter->child[charToInt(encodedString[dualEncodedStringIndex][i])];
        stringEncodedIter->solved = 1;
        stringEncodedIter->correspondingIndex = dualDecodedStringIndex;
    }

    void rowWiseDecode()
    {
        countNode *iterNode = countHead;
        int leftCount, rightCount;
        for(int i = 0; i < n; i++)
        {
            if(solvedCount == encodedString.size())
                return;
            leftCount = getCount(stringEncodedHead, encodedTable[i][0], 0);
            rightCount = getCount(stringEncodedHead, encodedTable[i][1], 1);
            if(trieObject.searchCountTrie(countHead, makeVector(leftCount, rightCount)) == 1)
            {
                solveCount(encodedTable[i], stringEncodedHead, makeVector(leftCount, rightCount));
                solvedCount += 2;
            }
            else
            {
                int left =  isSolved(encodedTable[i][0]);
                int right = isSolved(encodedTable[i][1]);
                if((left + right) == 1)
                {
                    solvedCount++;
                    if(left == 1)
                        doExtract(encodedTable[i][0], encodedTable[i][1], 1, makeVector(leftCount, rightCount));
                    else
                        doExtract(encodedTable[i][1], encodedTable[i][0], 0, makeVector(leftCount, rightCount));
                }
            }
        }
    }

    void countWiseDecode()
    {
        vector<int> stringCounts;
        stringNode *encodedIterString = stringEncodedHead;
        for(int i = 0; i < encodedString.size(); i++)
        {
            if(solvedCount == encodedString.size())
                return ;
            stringCounts.push_back(getCount(stringEncodedHead, encodedString[i], 0));
            stringCounts.push_back(getCount(stringEncodedHead, encodedString[i], 1));
            checkCountUnique(stringCounts, stringCountHead, encodedString[i]);
        }
    }

    void putData()
    {
        stringNode *stringIter;
        for(int i = 0; i < encodedString.size(); i++)
        {
            stringIter = stringEncodedHead;
            cout << encodedString[i] << "/" ;
            for(int j = 0; j < encodedString[i].size(); j++)
            {
                stringIter = stringIter->child[charToInt(encodedString[i][j])];
            }
            cout << decodedString[stringIter->correspondingIndex] << endl;
        }
    }

};


int main()
{
    cin >> n;
    while(n != 0)
    {
        fflush(stdin);
        stringOperation objectString;
        translation objectTranslation;
        objectTranslation.dualCaseHandle();
        objectTranslation.rowWiseDecode();
        objectTranslation.countWiseDecode();
        objectString.sort();
        objectTranslation.putData();
        cin >> n;
    }
    return 0;
}
