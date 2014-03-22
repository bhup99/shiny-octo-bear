#include <iostream>
#include <string>

using namespace std;

class CircleGame
{
    public:

    bool consecAdd(char a, char b)
    {
        int x, y;
        if(a == 'A')
            x = 1;
        else if(a == 'T')
            x = 10;
        else if(a == 'J')
            x = 11;
        else if(a == 'Q')
            x = 12;
        else
            x = a - '0';

        if(b == 'A')
            y = 1;
        else if(b == 'T')
            y = 10;
        else if(b == 'J')
            y = 11;
        else if(b == 'Q')
            y = 12;
        else
            y = b - '0';
        if(x + y == 13)
            return 1;
        return 0;
    }

    int cardsLeft(string deck)
    {
        while(deck.size() && (deck.find('K') < deck.size() || deck[0] == 'K'))
        {
            deck.erase(deck.begin() + deck.find('K'));
        }
        int j = 0, n;
        n = deck.size();
        cout << n << endl;
        for(int i = 0; i < deck.size();)
        {
            cout << deck << " " << i << " " << n << " " << deck[(i + 1) % n] << endl;
            if(consecAdd(deck[i % n], deck[(i + 1) % n]))
            {
                cout << "LENDI" << endl;
                deck.erase(deck.begin() + (i % n));
                n--;
                deck.erase(deck.begin() + (i) % n);
                n --;
                if(n < i)
                    i = i - 2;
                else if(i > 0)
                    i--;
            }
            else
                i++;
        }
        return deck.size();
    }

};

int main()
{
    CircleGame ob;
    cout << ob.cardsLeft("J92J43KT5T879QA2QK3");
}
