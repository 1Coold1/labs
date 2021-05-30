#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int k = 0;
    char f3[255], f4[255];
    ifstream f1("F1.txt");
    ofstream f2("F2.txt");

    if (!f1)
    {
        cout << "Error!" << endl;
        system("pause");
        return 0;
    }

    while (f1.getline(f3, 255))
    {
        k++;
        if (k > 3)
        {
            f2 << f3 << '\n';
        }
    }

    f2.close();

    ifstream p2("F2.txt");
    if (p2)
    {
        while (true)
        {
            p2 >> f4;
            if (p2.peek() == '\n')
                p2.get();
            if (p2.peek() == EOF)
                break;
        }
        p2.close();
        cout <<"Last word have "<<strlen(f4) <<" symbols"<< endl;
    }
    else
    {
        cout << "Error!" << endl;
        system("pause");
    }

    system("pause");
    return 0;
}