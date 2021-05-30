#include "Time.h" 
#include <iostream> 
using namespace std;
//���������� �������� ������������ 
Time&Time::operator=(const Time&t) {
//�������� �� ���������������� 
if(&t==this) return *this; 
min=t.min; 
sec=t.sec; 
return *this;
}
//���������� ���������� �������� ��������� 
Time&Time::operator++() {
int temp = min * 60 + sec; 
temp++;
min = temp / 60; 
sec = temp % 60; 
return *this;
}
//���������� ����������� �������� ��������� 
Time Time::operator ++(int) {
int temp = min * 60 + sec; 
temp++;
Time t(min, sec); 
min = temp / 60; 
sec = temp % 60; 
return t;
}
//���������� ���������� �������-�������� ����� 
istream&operator>>(istream&in, Time&t) {
cout << "������� ������ - "; 
in >> t.min; 
do {
    cout << "������� ������� - ";
    in >> t.sec;
} while ((t.sec < 0) || (t.sec >= 60));
return in;
}
//���������� ���������� �������-�������� ������ 
ostream&operator<<(ostream&out, const Time&t) {
return (out << t.min << ":" << t.sec);
}
//���������� ������� ���������
bool operator==(const Time& t1, const Time& t2) {
    if (t1.min == t2.min && t1.sec == t2.sec)
        return true;
    else return false;
}
//���������� ������� �����������
bool operator!=(const Time& t1, const Time& t2) {
    if (t1.min != t2.min && t1.sec != t2.sec)
        return true;
    else return false;
}