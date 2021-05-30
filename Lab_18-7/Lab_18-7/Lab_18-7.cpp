#include <iostream>
#include "Vector.h"
#include "Time.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	/*//инициализация, ввод и вывод значений вектора 
	Vector<int>A(5,0); cin>>A;
	cout << A << endl;
	//инициализация и вывод значений вектора 
	Vector <int>B(10,1); cout<<B<<endl; 
	//операция присваивания 
	B=A;
	cout << B << endl; 
	//доступ по индексу 
	cout <<A[2]<<endl; 
	//получение длины вектора 
	cout<<"size="<<A()<<endl; 
	//операция умножения на константу 
	B=A*10;
	cout << B << endl;
	*/
	cout << "Введите t" << endl;
	Time t; 
	cin >> t; 
	cout << "t: " << endl;
	cout << t << endl;
	Vector<Time>A(5, t); 
	cout << "Введите вектор А" << endl;
	cin >> A;
	cout << "Вектор А" << endl;
	cout << A << endl;
	Vector <Time>B(10, t); 
	cout << "Вектор B" << endl;
	cout << B << endl;
	B = A;
	cout << "Вектор B после присваивания" << endl;
	cout << B << endl; 
	cout << "Второй элемент вектора А" << endl;
	cout << A[2] << endl; 
	cout << "Размер А=" << A() << endl;
	B = A * t;
	cout << "Вектор B после умножения вектора А на t" << endl;
	cout << A*t << endl;
}
