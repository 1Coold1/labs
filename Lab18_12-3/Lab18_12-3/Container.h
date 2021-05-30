#pragma once 
#include <iostream> 
#include <map> //словарь 
using namespace std; 
//параметризированный класс 
template<class T> class Container 
{
map<int, T> v; //контейнер словарь 
int len; //длина словаря
public:
	Container(void); //конструктор без параметров 
	Container(int n); //конструктор с параметрами 
	void Print(); //печать
	int Max();
	T Srednee();
	void Sum();
	void Add(int);
	void Del(int);
	~Container(void); //деструктор
};
//реализация методов //конструктор без параметров 
template <class T>
Container<T>::Container()
{
	len = 0;
}
//деструктор 
template <class T> Container<T>::~Container(void) { }
//конструктор c параметрами 
template <class T> Container<T>::Container(int n) 
{
	T a; 
	for (int i = 0; i < n; i++) 
	{
	cin >> a; v[i] = a;//записать а в словарь
	} 
	len = v.size(); 
}
//вывод контейнера 
template <class T> void Container<T>::Print() 
{
	for (int i = 0; i < v.size(); i++) cout << i << " - " << v[i] << " " << endl;
	cout << "------------------------------------------" << endl;
}

template<class T> int Container<T>:: Max()
{
	typename map<int, T>::iterator i = v.begin();//итератор поставили на первый элемент
	int nom = 0,//номер максимального 
		k = 0;//счетчик элементов 
	T m = (*i).second;//значение первого элемента 
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//итератор 
		k++;//счетчик элементов
	}
	return nom;//номер max
}

template<class T> void Container<T>::Add(int n)
{
	int max = Max();
	v.insert(make_pair(n, v[max]));//формируем пару и добавляем ее в словарь
}

template<class T> void Container<T>::Del(int max) {
	cout << "Элемент=" << v[max] << " Номер=" << max << endl; 
	v.erase(max);
}

template<class T> T Container<T>::Srednee()
{
	T s = v[0];
	//перебор словаря 
	for (int i = 1; i < v.size(); i++) s = s + v[i];
	int n = v.size();//количество элементов в словаре 
	return s / n;
}

template<class T> void Container<T>::Sum()
{
	T sr = Srednee();
	cout << "Среднее арифметическое: " << sr << endl;
	for (int i = 0; i < v.size(); i++) v[i] = v[i] + sr;
}