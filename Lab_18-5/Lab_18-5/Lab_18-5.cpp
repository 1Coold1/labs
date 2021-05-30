#include <iostream>
#include "Object.h"
#include "Pair.h"
#include "Complex.h"
#include "Vector.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    /*Pair a; 
    cin >> a; 
    cout << a << endl;//вывод с помощью перегруженной операции 
    Object *p=&a;
    p->Show();//вывод с помощью метода Show() и указателя
    Complex b; 
    cin >> b; 
    cout << b << endl;//вывод с помощью перегруженной операции 
    p=&b;
    p->Show();//вывод с помощью метода Show() и указателя */

    Vector v(10);//вектор из 5 элементов 
    Pair a;//объект класса Pair 
    cin>>a; 
    Complex b;// объект класса Complex 
    cin>>b; 
    Complex c;// объект класса Complex 
    cin >> c;
    Complex d;// объект класса Complex 
    Complex e;// объект класса Complex 
    Object *p=&a;//ставим указатель на объект класса Pair 
    v.Add(p);//добавляем объект в вектор 
    p=&b;//ставим указатель на объект класса Complex 
    v.Add(p); //добавляем объект в вектор
    p = &c;//ставим указатель на объект класса Complex 
    v.Add(p); //добавляем объект в вектор
    d = b - c;
    p = &d;
    v.Add(p);
    e = b * c;
    p = &e;
    v.Add(p);
    cout << v;//вывод вектора 
}