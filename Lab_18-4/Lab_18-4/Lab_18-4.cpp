#include <iostream>
#include "Pair.h"
#include "Complex.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	Pair a(2, 141); 
	Complex c,d; 
	cout << "Пары чисел"<<endl;
	cout << "a: ";
	cout << a; 
	Pair b(4, 115); 
	cout << "b: ";
	cout << b; 
	cout << "a+b: ";
	cout << a+b;
	cout << "Комплексные числа" << endl;
	cout << "c: ";
	cin >> c;
	cout << "c: ";
	cout << c;
	cout << "d: ";
	cin >> d;
	cout << "d: ";
	cout << d;
	cout << "c-d: ";
	cout << c - d;
	cout << "c*d: ";
	cout << c * d;
}
