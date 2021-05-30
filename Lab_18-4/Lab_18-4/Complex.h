#pragma once
#include "Pair.h"
class Complex :
    public Pair
{
public:
    Complex(void); //����������� ��� ����������
    ~Complex(void); //����������
    Complex(int, int); //����������� � �����������
    Complex(const Complex&); //����������� �����������
    Complex& operator=(const Complex&); //�������� ������������
    friend istream& operator>>(istream& in, Complex& l); //�������� ����� 
    friend ostream& operator<<(ostream&out,const Complex&l); //�������� ������
    friend Complex operator* (const Complex& c1, const Complex& c2);
    friend Complex operator- (const Complex& c1, const Complex& c2);
};

