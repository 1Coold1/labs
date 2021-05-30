#include <iostream>
#include "Container.h"
#include "Time.h"

int main()
{
	setlocale(LC_ALL, "rus");
	int n, k;
	cout << "Введите количество элементов: ";
	cin >> n;//количество элементов 
	Container <Time> v(n);//создать контенер 
	v.Print();//напечатать контейнер
	v.Add(n);
	v.Print();//напечатать контейнер
	cout << "Введите ключ для удаления: ";
	cin >> k;
	v.Del(k);
	v.Print();//напечатать контейнер
	v.Sum();
	v.Print();//напечатать контейнер
}