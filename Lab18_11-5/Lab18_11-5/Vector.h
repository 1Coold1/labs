#pragma once 
#include <vector> 
#include <queue>
#include <iostream> 
using namespace std;
//������ ������ 
template<class T> class Vector
{
	queue <T> q;//���������������� ��������� ��� �������� ��������� ������� 
	int len;
public:
	Vector(void);//����������� ��� ��������� 
	Vector(int n);//����������� � ���������� 
	Vector(const Vector<T>&);//����������� �����������
	void Print();//������
	~Vector(void);//����������
	T Max();
	void Add();
	void Del(T);
	T Srednee();
	void Sum();
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
		cin >> a; 
		q.push(a);
	}
	len = q.size();
}
//����������� ����������� 
template <class T> Vector<T>::Vector(const Vector<T> &v) 
{
	len = v.len; 
	//�������� �������� ����� Vec.q � ������ v vector 
	v=copy_queue_to_vector(v.q); 
	//�������� ������ v � ���� s 
	q=copy_vector_to_queue(v);
}
//������ 
template <class T> void Vector<T>::Print()
{
	//�������� ���� � ������ 
	vector<T> v=copy_queue_to_vector(q); 
	while(!q.empty())//���� ���� �� ������
	{
	cout << q.front() << "\t";//����� �������� � ������� ����� 
	q.pop();//������� ������� �� �������
	}
	cout << endl;
	//�������� ������ � ����
	q = copy_vector_to_queue(v);
}

template <class T> vector<T> copy_queue_to_vector(queue<T> q) {
	vector<T> v;
	while (!q.empty()) 
	{
		v.push_back(q.front()); q.pop();
	} return v;
}
//����������� ������� � ���� 
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
	T m = q.front();//m ��������� �������� �� ������� ����� 
				  //� ������ ����������� �������� ����� 
	vector<T> v=copy_queue_to_vector(q);
	while(!q.empty())//���� ���� �� ������ 
	{
	//���������� m � ������� � ������� �����
		if(q.front()>m) m=q.front(); 
		q.pop();//������� ������� �� ������� �����
	}
	q = copy_vector_to_queue(v);//�������� ������ � ���� 
	return m;
}

template <class T> void Vector<T>::Add()
{
	vector<T> v = copy_queue_to_vector(q);
	T m = Max();
	v.push_back(m);
	q = copy_vector_to_queue(v);//�������� ������ � ���� 
}

template <class T> void Vector<T>::Del(T k) 
{
	vector<T> v;
	T t; 
	while(!q.empty())//���� ���� �� ������ 
	{
		t = q.front();//�������� ������� �� ������� ����� 
				//���� t �� ����� �������������, �� �������� ��� � ������ 
		if(t!=k) v.push_back(t); 
		q.pop();//������� ������� �� �����
	}
	//�������� ������ � ����
	q = copy_vector_to_queue(v);
}

//������� �������������� 
template <class T> T Vector<T>::Srednee() {
//�������� ���� � ������
	vector<T> v = copy_queue_to_vector(q); 
	int n = 1;//���������� ��������� � ����� 
	T sum=q.front();//��������� �������� ��� ����� 
	q.pop();//������� ������� �� ������� �����
	while (!q.empty())//���� ���� �� ������ 
	{
		sum = sum + q.front();//��������� � ����� ������� �� ������� ����� 
		q.pop();//������� ������� �� ������� ����� 
		n++;//����������� ���������� ���������
	}
	//�������� ������ � ���� 
	q=copy_vector_to_queue(v); 
	return sum/n;
}

template <class T> void Vector<T>::Sum() {
	T m = Srednee(); 
	cout << "������� ��������������: " << m << endl;
	vector<T> v; 
	T t;
	while (!q.empty()) 
	{
		t = q.front();
		v.push_back(t+m); q.pop();
	}
	q = copy_vector_to_queue(v);
}