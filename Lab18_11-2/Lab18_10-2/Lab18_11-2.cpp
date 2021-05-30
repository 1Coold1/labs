#include <iostream>
#include <deque>
#include "Time.h"
using namespace std;

typedef deque<Time>Deq;//определяем тип для работы с вектором 
//функция для формирования вектора 
Deq make_deque(int n) 
{ 
	Deq d;//пустой вектор 
	for(int i=0;i<n;i++) 
	{
		Time a;
		cin >> a;
		d.push_back(a);//добавляем а в конец вектора
	} 
	return d;//возвращаем вектор как результа работы функции 
}
//функция для печати вектора 
void print_deque(Deq d) 
{
	for (int i = 0; i < d.size(); i++) cout << d[i] << "\t";
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	deque<Time> d;//вектор 
	deque<Time>::iterator vi=d.begin();//итератор 
	Time max,k,s,sa;
	max = 0;
	int n; 
	cout<<"N?"; 
	cin>>n;
	d=make_deque(n);//формирование вектора
	print_deque(d);//печать вектора
	for (int i = 0; i < d.size(); i++)
		if (d[i] > max) max = d[i];
	d.push_back(max);
	print_deque(d);

	cout << "Введите ключ: ";
	cin >> k;
	d.erase(remove(d.begin(), d.end(), k), d.end());
	print_deque(d);

	for (int i = 0; i < d.size(); i++)
		s = s + d[i];
	cout << s << endl;
	sa = s / d.size();
	cout << "Среднее арифметическое: " << sa;
	cout << endl;
	for (int i = 0; i < d.size(); i++)
	{
		d[i] = d[i] + sa;
		cout << d[i] << "\t";
	}
	cout << endl;
}