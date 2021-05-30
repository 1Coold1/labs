#pragma once 
#include <vector> 
#include <queue>
#include <iostream> 
using namespace std;
//шаблон класса 
template<class T> class Vector
{
	queue <T> q;//последовательный контейнер для хранения элементов вектора 
	int len;
public:
	Vector(void);//конструктор без параметра 
	Vector(int n);//конструктор с параметром 
	Vector(const Vector<T>&);//конструктор копирования
	void Print();//печать
	~Vector(void);//деструктор
	T Max();
	void Add();
	void Del(T);
	T Srednee();
	void Sum();
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
		cin >> a; 
		q.push(a);
	}
	len = q.size();
}
//конструктор копирования 
template <class T> Vector<T>::Vector(const Vector<T> &v) 
{
	len = v.len; 
	//копируем значения стека Vec.q в вектор v vector 
	v=copy_queue_to_vector(v.q); 
	//копируем вектор v в стек s 
	q=copy_vector_to_queue(v);
}
//печать 
template <class T> void Vector<T>::Print()
{
	//копируем стек в вектор 
	vector<T> v=copy_queue_to_vector(q); 
	while(!q.empty())//пока стек не пустой
	{
	cout << q.front() << "\t";//вывод элемента в вершине стека 
	q.pop();//удаляем элемент из вершины
	}
	cout << endl;
	//копируем вектор в стек
	q = copy_vector_to_queue(v);
}

template <class T> vector<T> copy_queue_to_vector(queue<T> q) {
	vector<T> v;
	while (!q.empty()) 
	{
		v.push_back(q.front()); q.pop();
	} return v;
}
//копирование вектора в стек 
template <class T> queue<T> copy_vector_to_queue(vector<T> v) 
{
	queue<T> q; 
	for (int i = 0; i < v.size(); i++) 
	{
		q.push(v[i]);
	} 
	return q;
}
template <class T> T Vector<T>::Max() 
{
	T m = q.front();//m присвоить значение из вершины стека 
				  //в вектор скопировать элементы стека 
	vector<T> v=copy_queue_to_vector(q);
	while(!q.empty())//пока стек не пустой 
	{
	//сравниваем m и элемент в вершине стека
		if(q.front()>m) m=q.front(); 
		q.pop();//удаляем элемент из вершины стека
	}
	q = copy_vector_to_queue(v);//копируем вектор в стек 
	return m;
}

template <class T> void Vector<T>::Add()
{
	vector<T> v = copy_queue_to_vector(q);
	T m = Max();
	v.push_back(m);
	q = copy_vector_to_queue(v);//копируем вектор в стек 
}

template <class T> void Vector<T>::Del(T k) 
{
	vector<T> v;
	T t; 
	while(!q.empty())//пока стек не пустой 
	{
		t = q.front();//получить элемент из вершины стека 
				//если t не равен максимальному, то добавить его в вектор 
		if(t!=k) v.push_back(t); 
		q.pop();//удалить элемент из стека
	}
	//копируем вектор в стек
	q = copy_vector_to_queue(v);
}

//среднее арифметическое 
template <class T> T Vector<T>::Srednee() {
//копируем стек в вектор
	vector<T> v = copy_queue_to_vector(q); 
	int n = 1;//количество элементов в стеке 
	T sum=q.front();//начальное значение для суммы 
	q.pop();//удаляем элемент из вершины стека
	while (!q.empty())//пока стек не пустой 
	{
		sum = sum + q.front();//добавляем в сумму элемент из вершины стека 
		q.pop();//удаляем элемент из вершины стека 
		n++;//увеличиваем количество элементов
	}
	//копируем вектор в стек 
	q=copy_vector_to_queue(v); 
	return sum/n;
}

template <class T> void Vector<T>::Sum() {
	T m = Srednee(); 
	cout << "Среднее арифметическое: " << m << endl;
	vector<T> v; 
	T t;
	while (!q.empty()) 
	{
		t = q.front();
		v.push_back(t+m); q.pop();
	}
	q = copy_vector_to_queue(v);
}