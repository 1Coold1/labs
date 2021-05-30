#pragma once
#include "Book.h"
#include "Object.h"
#include "Print.h"
#include <iostream>
using namespace std;
class Vector 
{
public:
	Vector(void);
	Vector(int);//����������� � �����������
    ~Vector(void);//���������� 
	void Add();//���������� �������� � ������ 
	void Del(); 
	void Show(); 
	int operator()();//������ �������
protected:
	Object** beg;//��������� �� ������ ������� ������� 
	int size;//������ 
	int cur;//������� �������
	void HandleEvent(const TEvent& e);
};