#include <iostream>
#include "Vector.h"
#include "Time.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    Vector<Time>vec(5);//создать вектор из 5 элементов 
    vec.Print();//печать вектора
    Time max,k;
    max = 0;
    vec.Add(max);
    vec.Print();//печать вектора
    cout << "Введите ключ: ";
    cin >> k;
    vec.Del(k);
    vec.Print();//печать вектора
    Time s = vec.Srednee();
    cout << "Среднее арифметическое: " << s << endl;
    vec.Sum(s);
    vec.Print();//печать вектора
}