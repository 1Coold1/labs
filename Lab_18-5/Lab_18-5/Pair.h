#pragma once
#include "Object.h"
#include <iostream> 
using namespace std;
class Pair: 
	public Object 
{
public:
	//����������� ��� ���������� public:
	Pair();
	//���������� virtual 
	~Pair(void);
	//������� ��� ��������� ��������� ������ � ������� ���������
	void Show();
	//���������� � ����������� 
	Pair(int, int);
	//����������� �����������
	Pair(const Pair&);
	//��������� 
	int Get_first() { return first; }
	int Get_second() { return second; }
	//������������ 
	void Set_first(int);
	void Set_second(int);
	//���������� �������� ������������ 
	Pair& operator=(const Pair&);
	//���������� ���������-������� �����-������ 
	friend Pair operator+(const Pair& p1, const Pair& p2);
	friend istream& operator>>(istream& in, Pair& c);
	friend ostream& operator<<(ostream& out, const Pair& c);
	//�������� 
protected:
	int first; 
	int second;
};