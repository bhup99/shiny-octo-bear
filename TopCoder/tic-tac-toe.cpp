#include<iostream>
#include<cstdio>
using namespace std;

typedef struct
{
    int count;
    char symbol;
}candidatIn;

class layout
{
    int i, j, temp;
    public:

    char *board[3] = {calloc(3, sizeof(char) * 3), calloc(3, sizeof(char) * 3), calloc(3, sizeof(char) * 3)};
    candidatIn *row = calloc(2, sizeof(row) * 3);
    candidatIn *col = calloc(2, sizeof(col) * 3);
    candidatIn *dig = calloc(2, sizeof(dig)*2);

    void GraphicalLayout()
    {
        for(i = 0; i < 2; i++)
        {
            if(board[i][0] == '\0')
                cout << "_";
            else
            {
                temp = &board[i][0] - &board[0][0];
                temp = temp / 4;
                cout << temp;
            }
            for(j = 1; j < 3; j++)
            {
                cout <<"|";
                if( board[i][j] == 0)
                    cout << "_";
                else
                {
                    temp = &board[i][j] - &board[0][0];
                    temp = temp / 4;
                    cout << temp;
                }
            }
            cout << endl;
        }
        if(board[2][0]!=0)
            cout << board[2][0];
        else
            cout << " ";
        for(i = 1; i < 3; i++)
        {
            cout << "|";
            if(board[2][i] != 0)
                cout << board[2][i];
            else
                cout << " ";
        }
    }
};

class checkOut:: public layout
{
    int iter1;
    public:

    int i, j;
    bool d;
    void update(char symbol)
    {
        if(row[i].symbol == 'C')
            return;
        else if(row[i].symbol == symbol)
            row[i].count ++;
        else if(row[i].symbol != symbol)
            row[i].symbol = 'C';
        else
            row[i].symbbol = symbol;

        if(col[j].symbol == 'C')
            return;
        else if(col[j].symbol == symbol)
            col[j].count ++;
        else if(col[j].symbol != symbol)
            col[j].symbol = 'C';
        else
            col[j].symbol = symbol;

        if(abs(i-j) != 1)
        {
            d = i != j;
            if(dig[d].symbol == 'C')
                return;
            else if(dig[d].symbol == symbol)
                dig[d].count ++;
            else if(dig[d].symbol != symbol)
                dig[d].symbol = 'C';
            else
                dig[d].symbol = symbol;
        }
    }
    int hasWin()
    {
        for( iter1 = 0; iter1 < 3; iter1 ++)
        {
            if(row[iter1].count == 2)
            {
                cout << row[iter1].symbol << "has won" << endl;
                return 1;
            }
            else if(col[iter1].count == 2)
            {
                cout << col[iter1].symbol << "has won" << endl;
                return 2;
            }
            else if(dig[iter1 % 2].count == 2)
            {
                cout << dig[d].symbol << "has won" << endl;
                return 3;
            }
        }
    }
}

class tictactoe :: private checkOut
{
    int choice;
    int isGameOver;
    public:

    void UserInput(char symbol)
    {
        GraphicalLayout(board);
        cout << "Choose the number of box counting horizontally from the start :- ";
        cin >> choice ;
        i = choice / 3;
        j = choice % 3;

        update( symbol) ;
        isGameOver = hasWin();
        if(isGameOver == 1)
            return;
        board[i][j] = symbol;
    }
}

int main()
{
    int
}
