#include "Pair.h"
//конструктор без параметров 
Pair::Pair(void) {
first = 0; 
second = 0;
}
//деструктор 
Pair::~Pair(void) { } 
//конструктор с параметрами 
Pair::Pair(int F,int S) {
	first= F; 
	second = S;
}
//конструктор копирования 
Pair::Pair(const Pair& pair) {
first = pair.first; 
second = pair.second;
}
//модификаторы 
void Pair::Set_first(int F) {
	first = F; 
}

void Pair::Set_second(int S) {
	second = S;
}
//перегрузка операции присваивания 
Pair& Pair::operator=(const Pair&p) {
if (&p == this) return *this; 
first = p.first; 
second = p.second; 
return *this;
}
//глобальная функция сложения
Pair operator+(const Pair& p1, const Pair& p2) {
	Pair temp;
	temp.first = p1.first + p2.first;
	temp.second = p1.second + p2.second;
	return temp;
}
//глобальная функция для ввода 
istream& operator>>(istream&in, Pair&p)
{
cout << "\nПервое число:"; 
in >> p.first; 
cout << "\nВторое число:"; 
in >> p.second; 
return in;
}
//глобальная функция для вывода 
ostream& operator<<(ostream&out,const Pair&p) {
out << "\nПервое число : " << p.first; 
out << "\nВторое число : " << p.second; 
out << "\n"; 
return out;
}