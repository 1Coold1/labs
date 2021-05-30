#include "Number.h"
#include <iostream>
#include <string>
using namespace std;
Number::Number()
{
	mantissa = 0;
	poryadok = 0;
	stroka = "";
	cout << "����������� ��� ���������� ��� ������� " << this << endl;
}

Number::Number(float M, int P, string S)
{
	mantissa = M;
	poryadok = P;
	stroka = S;
	cout << "����������� � ����������� ��� ������� " << this << endl;
}

Number::Number(const Number &n)
{
	mantissa = n.mantissa;
	poryadok = n.poryadok;
	stroka = n.stroka;
	cout << "����������� ����������� ��� ������� " << this << endl;
}

Number::~Number()
{
	cout << "���������� ��� ������� " << this << endl;
}

float Number::get_mantissa()
{
	return mantissa;
}

int Number::get_poryadok()
{
	return poryadok;
}

string Number::get_stroka()
{
	return stroka;
}

void Number::set_mantissa(float M)
{
	mantissa = M;
}

void Number::set_poryadok(int P)
{
	poryadok = P;
}

void Number::set_stroka(string S)
{
	stroka = S;
}

void Number::show()
{
	cout << "��������: " << mantissa << endl;
	cout << "�������: " << poryadok << endl;
	cout << "������: " << stroka << endl;
}