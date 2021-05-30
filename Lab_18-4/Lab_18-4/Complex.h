#pragma once
#include "Pair.h"
class Complex :
    public Pair
{
public:
    Complex(void); //конструктор без параметров
    ~Complex(void); //деструктор
    Complex(int, int); //конструктор с параметрами
    Complex(const Complex&); //конструктор копирования
    Complex& operator=(const Complex&); //операция присваивания
    friend istream& operator>>(istream& in, Complex& l); //операция ввода 
    friend ostream& operator<<(ostream&out,const Complex&l); //операция вывода
    friend Complex operator* (const Complex& c1, const Complex& c2);
    friend Complex operator- (const Complex& c1, const Complex& c2);
};

