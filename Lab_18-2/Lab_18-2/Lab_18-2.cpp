#include "Number.h"
#include <iostream>
#include <string>
using namespace std;

Number make_number()
{
	float m;
	int p;
	string s;
	cout << "Введите мантиссу: ";
	cin >> m;
	cout << "Введите порядок: ";
	cin >> p;
	cout << "Введите строку: ";
	cin >> s;
	Number n(m, p, s);
	return n;
}

void print_number(Number n)
{
	n.show();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Number n1;
	n1.show();
	Number n2(0.118625, 3, "118.625");
	n2.show();
	Number n3 = n2;
	n3.set_mantissa(0.523674);
	n3.set_poryadok(1);
	n3.set_stroka("5.23674");
	print_number(n3);
	n1=make_number();
	n1.show();
	return 0;
	system("pause");
}
