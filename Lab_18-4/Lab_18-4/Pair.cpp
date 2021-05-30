#include "Pair.h"
//����������� ��� ���������� 
Pair::Pair(void) {
first = 0; 
second = 0;
}
//���������� 
Pair::~Pair(void) { } 
//����������� � ����������� 
Pair::Pair(int F,int S) {
	first= F; 
	second = S;
}
//����������� ����������� 
Pair::Pair(const Pair& pair) {
first = pair.first; 
second = pair.second;
}
//������������ 
void Pair::Set_first(int F) {
	first = F; 
}

void Pair::Set_second(int S) {
	second = S;
}
//���������� �������� ������������ 
Pair& Pair::operator=(const Pair&p) {
if (&p == this) return *this; 
first = p.first; 
second = p.second; 
return *this;
}
//���������� ������� ��������
Pair operator+(const Pair& p1, const Pair& p2) {
	Pair temp;
	temp.first = p1.first + p2.first;
	temp.second = p1.second + p2.second;
	return temp;
}
//���������� ������� ��� ����� 
istream& operator>>(istream&in, Pair&p)
{
cout << "\n������ �����:"; 
in >> p.first; 
cout << "\n������ �����:"; 
in >> p.second; 
return in;
}
//���������� ������� ��� ������ 
ostream& operator<<(ostream&out,const Pair&p) {
out << "\n������ ����� : " << p.first; 
out << "\n������ ����� : " << p.second; 
out << "\n"; 
return out;
}