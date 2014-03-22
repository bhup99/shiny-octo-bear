#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class dieHard
{
    int table[3][2];
    int **goDown;
    public:

    dieHard()
    {
        int health, armor, i, j;
        goDown = (int **)new int[1000];
        for(i = 0; i < 1000; i++)
            goDown[i] = (int *)new int[1000];
        cin >> health >> armor;
        table[0][0] = 3;
        table[0][1] = 2;
        table[1][0] = -5;
        table[1][1] = -10;
        table[2][0] = -20;
        table[2][1] = 5;
        cout << treeCall(health + 3, armor + 2, 0) << endl;
        free(goDown);
    }

    int treeCall(int health, int armor, int state)
    {
        if(health > 0 && armor > 0 && health <1000 && armor < 1000 && goDown[health][armor] > 0)
            return goDown[health][armor];

        if(health <= 0 || armor <= 0)
            return 0;
        int x, y;
        x = treeCall(health + table[(state + 1) % 3][0], armor + table[(state + 1) % 3][1], (state + 1) % 3) + 1;
        y = treeCall(health + table[(state + 2) % 3][0], armor + table[(state + 2) % 3][1], (state + 2) % 3) + 1;
        goDown[health][armor] = (x > y) ? x : y;
        return goDown[health][armor];
    }
};

int main()
{
    int test, i;
    cin >> test;
    for(i = 0; i < test; i++)
        dieHard ob;
    return 0;
}
