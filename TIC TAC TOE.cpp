#include <iostream>
using namespace std;
struct boardValues
{
    char arr[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
};
void printBoard(struct boardValues bV)
{
    cout << " " << bV.arr[0] << " | " << bV.arr[1] << " | " << bV.arr[2] << endl;
    cout << "_" << "_" << "_|_" << "_" << "_|_" << "__" << endl;
    cout << " " << bV.arr[3] << " | " << bV.arr[4] << " | " << bV.arr[5] << endl;
    cout << "_" << "_" << "_|_" << "_" << "_|_" << "__" << endl;
    cout << " " << bV.arr[6] << " | " << bV.arr[7] << " | " << bV.arr[8] << endl;
    cout << endl;
}
void updateBoard(struct boardValues* bV, char input, int pos)
{
    if (bV->arr[pos] == ' ')
    {
        bV->arr[pos] = input;
    }
    else
    {
        cout << "This location is already choosen, You lost this chance" << endl;

    }

}
char checkPossibleWinner(struct boardValues bV)
{
    for (int i = 0; i < 9; i += 3)
    {
        if ((bV.arr[i] == 'X' && bV.arr[i + 1] == 'X' && bV.arr[i + 2] == 'X') || (bV.arr[i] == 'O' && bV.arr[i + 1] == 'O' && bV.arr[i + 2] == 'O'))
        {
            return(bV.arr[i]);
        }
    }
    for (int i = 0; i < 3; i += 1)
    {
        if ((bV.arr[i] == 'X' && bV.arr[i + 3] == 'X' && bV.arr[i + 6] == 'X') || (bV.arr[i] == 'O' && bV.arr[i + 3] == 'O' && bV.arr[i + 6] == 'O'))
        {
            return(bV.arr[i]);
        }
    }
    if ((bV.arr[0] == 'X' && bV.arr[4] == 'X' && bV.arr[8] == 'X') || (bV.arr[0] == 'O' && bV.arr[4] == 'O' && bV.arr[8] == 'O'))
    {
        return(bV.arr[0]);
    }
    if ((bV.arr[2] == 'X' && bV.arr[4] == 'X' && bV.arr[6] == 'X') || (bV.arr[2] == 'O' && bV.arr[4] == 'O' && bV.arr[6] == 'O'))
    {
        return(bV.arr[2]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (bV.arr[i] == ' ')
        {
            return('N');
        }

    }
    return('T');


}
bool findWinner(char c)
{
    if (c == 'X')
    {
        cout << "Player 1 is the WINNER !!!";
        return(true);
    }
    else if (c == 'O')
    {
        cout << "Player 2 is the WINNER !!!";
        return(true);
    }
    else if (c == 'T')
    {
        cout << "Match Tied";
        return(true);
    }
    else
    {
        return(false);
    }
}



int main()
{
    struct boardValues bV;
    int PosP1, PosP2;
    char result;
    printBoard(bV);
    while (true)
    {
        cout << "Player 1 Enter the position : ";
        cin >> PosP1;
        updateBoard(&bV, 'X', PosP1 - 1);
        printBoard(bV);
        result = checkPossibleWinner(bV);
        if (findWinner(result))
        {
            break;
        }

        cout << "Player 2 Enter the position : ";
        cin >> PosP2;
        updateBoard(&bV, 'O', PosP2 - 1);
        printBoard(bV);
        result = checkPossibleWinner(bV);
        if (findWinner(result))
        {
            break;
        }

    }

    return(0);
}