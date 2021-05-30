#include "Complex.h"

Complex::Complex(void) :Pair() {};
Complex::~Complex(void) {};
Complex::Complex(int F, int S) :Pair(F, S) {};
Complex::Complex(const Complex &C) {
	first = C.first;
	second = C.second;
}
Complex& Complex::operator=(const Complex& c) 
{
	if (&c == this) return *this; 
	first = c.first;
	second = c.second;
	return *this;
}
Complex operator* (const Complex& c1, const Complex& c2) {
	Complex temp;
	temp.first = (c1.first * c2.first) - (c1.second * c2.second);
	temp.second = (c1.first * c2.second) + (c1.second * c2.first);
	return temp;
}
Complex operator-(const Complex& c1, const Complex& c2)
{
	Complex temp;
	temp.first = c1.first-c2.first;
	temp.second = c1.second-c2.second;
	return temp;
}
istream& operator>>(istream& in, Complex& c)
{
	cout << "\n������ �����:";
	in >> c.first;
	cout << "\n������ �����:";
	in >> c.second;
	return in;
}
ostream& operator<<(ostream& out, const Complex& c) {
	out << "\n����������� ����� : " << c.first << " + " << c.second << "i";
	out << "\n";
	return out;
}