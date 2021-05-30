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
	Vector(int);//конструктор с параметрами
    ~Vector(void);//деструктор 
	void Add();//добавление элемента в вектор 
	void Del(); 
	void Show(); 
	int operator()();//размер вектора
protected:
	Object** beg;//указатель на первый элемент вектора 
	int size;//размер 
	int cur;//текущая позиция
	void HandleEvent(const TEvent& e);
};