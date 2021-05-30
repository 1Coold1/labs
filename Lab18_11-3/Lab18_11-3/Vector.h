#pragma once 
#include <vector> 
#include <iostream> 
using namespace std; 
//������ ������ 
template<class T> class Vector 
{
vector <T> v;//���������������� ��������� ��� �������� ��������� ������� 
int len; 
public:
Vector(void);//����������� ��� ��������� 
Vector(int n);//����������� � ���������� 
void Print();//������
~Vector(void);//����������
void Add(T el);//���������� �������� el �� ������� pos
void Del(T k);//������� ������� �� ������� pos
T Srednee();//���������� �������� ���������������
void Sum(T k);//������� ������� �� ������� pos
};
//����������� ��� ��������� 
template <class T> Vector<T>::Vector() 
{
len = 0; 
}
//���������� 
template <class T>
Vector<T>::~Vector(void) { }
//����������� � ���������� 
template <class T> Vector<T>::Vector(int n) 
{
	T a; 
	for (int i = 0; i < n; i++) 
	{
	cin >> a; v.push_back(a);
	} 
	len = v.size(); 
}
//������ 
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