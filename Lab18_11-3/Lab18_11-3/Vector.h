#pragma once 
#include <vector> 
#include <iostream> 
using namespace std; 
//шаблон класса 
template<class T> class Vector 
{
vector <T> v;//последовательный контейнер для хранения элементов вектора 
int len; 
public:
Vector(void);//конструктор без параметра 
Vector(int n);//конструктор с параметром 
void Print();//печать
~Vector(void);//деструктор
void Add(T el);//добавление элемента el на позицию pos
void Del(T k);//удалить элемент из позиции pos
T Srednee();//вычисление среднего арифметического
void Sum(T k);//удалить элемент из позиции pos
};
//конструктор без параметра 
template <class T> Vector<T>::Vector() 
{
len = 0; 
}
//деструктор 
template <class T>
Vector<T>::~Vector(void) { }
//конструктор с параметром 
template <class T> Vector<T>::Vector(int n) 
{
	T a; 
	for (int i = 0; i < n; i++) 
	{
	cin >> a; v.push_back(a);
	} 
	len = v.size(); 
}
//печать 
template <class T> void Vector<T>::Print() 
{
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

template<class T> void Vector<T>::Add(T el)
{
	for (int i = 0; i < v.size(); i++) 
	{
		if (v[i] > el) el = v[i];
	}
	v.push_back(el);
}

template<class T> void Vector<T>::Del(T k) 
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == k)
		{
			v.erase(v.begin()+i);
		}
	}
}

template<class T> T Vector<T>::Srednee() 
{
	T s = v[0]; 
	for (int i = 1; i < v.size(); i++) s = s + v[i];
	int n = v.size(); 
	return s / n;
}

template<class T> void Vector<T>::Sum(T k)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i]+k;
	}
}