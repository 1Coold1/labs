#include <iostream>
using namespace std;

int board[10][10];

void resetQ(int i, int j)
{
    for (int x = 0; x < 10; ++x)
    {
        --board[x][j];
        --board[i][x];
        int k;
        k = j - i + x;
        if (k >= 0 && k < 10)
            --board[x][k];
        k = j + i - x;
        if (k >= 0 && k < 10)
            --board[x][k];
    }
    board[i][j] = 0;
}

void setQ(int i, int j)
{
    for (int x = 0; x < 10; ++x)
    {
        ++board[x][j];
        ++board[i][x];
        int k;
        k = j - i + x;
        if (k >= 0 && k < 10)
            ++board[x][k];
        k = j + i - x;
        if (k >= 0 && k < 10)
            ++board[x][k];
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (board[i][j] == -1)
                cout << "[]";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
    board[i][j] = -1;
}

bool tryQ(int i)
{
    bool result = false;
    for (int j = 0; j < 10; ++j)
    {
        if (board[i][j] == 0)
        {
            setQ(i, j);
            if (i == 9)
                result = true;
            else
            {
                if (!(result = tryQ(i + 1)))
                    resetQ(i, j);
            }
        }
        if (result)
            break;
    }
    return result;
}
int main()
{
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            board[i][j] = 0;
    tryQ(0);
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (board[i][j] == -1)
                cout << "[]";
            else
                cout << ". ";
        }
        cout << endl;
    }
}