#include <iostream>
#include "Time.h"
#include <queue>
#include "Vector.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Vector<Time>v(3); 
	Time k;
	v.Print();
	v.Add();
	v.Print();
	cout << "Введите ключ для удаления: ";
	cin >> k;
	v.Del(k);
	v.Print();
	v.Sum();
	v.Print();
}