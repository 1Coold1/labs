#pragma once
#include <iostream>
using namespace std;
class Iterator {
	friend class Vector;//дружественный класс 
public:
	Iterator() { elem = 0; }//конструктор без параметров 
	Iterator(const Iterator&it){elem=it.elem;}//конструктор копирования
    //перегруженные операции сравнения 
	bool operator==(const Iterator& it) { return elem == it.elem; };
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	//перегруженная операция
	Iterator operator -(const int n) { elem -= n; return *this; };
	//перегруженная операция инкремент
	Iterator operator++(int) 
	{
		elem++;
		return *this;
	};
	Iterator operator--(int)
	{
		elem--;
		return *this;
	};
	//перегруженная операция разыменования 
	int& operator *() const{ return*elem;}
private: 
	int* elem;//указатель на элемент типа int
};

class Vector {
public:
	//конструктор с параметрами: выделяет память под s элементов и заполняет их значением k 
	Vector(int s, int k = 0);
	//конструктор с параметрами 
	Vector(const Vector& a);
	//деструктор 
	~Vector();
	//оператор присваивания 
	Vector& operator=(const Vector& a);
	//операция доступа по индексу 
	int& operator[](int index);
	//операция для добавление константы 
	Vector operator*(const int k);
	//операция, возвращающая длину вектора 
	int operator()();
	//перегруженные операции ввода-вывода 
	friend ostream& operator<<(ostream& out, const Vector& a);
	friend istream& operator>>(istream& in, Vector& a);
	Iterator first() { return beg; }//возвращает указатель на первый элемент 
	Iterator last(){return end;}//возвращает указатель на элемент следующий за последним
private:
	int size;//размер вектора 
	int*data;//укзатель на динамический массив значений вектора
	Iterator beg;//указатель на первый элемент вектора 
	Iterator end;//указатель на элемент следующий за последним
};

