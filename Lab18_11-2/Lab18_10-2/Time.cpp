#include "Time.h" 
#include <iostream> 
using namespace std;
//���������� �������� ������������ 
Time& Time::operator=(const Time& t) {
    //�������� �� ���������������� 
    if (&t == this) return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}
Time& Time::operator=(int t) 
{
    min = t;
    sec = t;
    return *this;
}
//���������� ���������� �������-�������� ����� 
istream& operator>>(istream& in, Time& t) {
    cout << "������� ������ - ";
    in >> t.min;
    do {
        cout << "������� ������� - ";
        in >> t.sec;
    } while ((t.sec < 0) || (t.sec >= 60));
    return in;
}
//���������� ���������� �������-�������� ������ 
ostream& operator<<(ostream& out, const Time& t) {
    return (out << t.min << ":" << t.sec);
}

bool Time::operator <(const Time& t) {
    if (min < t.min)return true; 
    if (min == t.min && sec < t.sec)
        return true; 
    return false;
}
bool Time::operator >(const Time& t) {
    if (min > t.min)return true; 
    if (min == t.min && sec > t.sec)
        return true; 
    return false;
} 
bool Time::operator ==(const Time& t) {
    if (min == t.min && sec == t.sec)
        return true;
    return false;
}
Time Time::operator+(const Time& t) {
    int temp1 = min * 60 + sec; 
    int temp2 = t.min * 60 + t.sec; 
    Time p;
    p.min = (temp1 + temp2) / 60; 
    p.sec = (temp1 + temp2) % 60; 
    return p;
}
//���������� �������� �������� ������� 
Time Time::operator/(const Time&t) {
    int temp1 = min * 60 + sec; 
    int temp2 = t.min * 60 + t.sec; 
    Time p;
    p.min = (temp1 / temp2) / 60; 
    p.sec = (temp1 / temp2) % 60; 
    return p;
}
Time Time::operator/(const int& t) {
    int temp1 = min * 60 + sec; 
    Time p;
    p.min = (temp1 / t) / 60; 
    p.sec = (temp1 / t) % 60; 
    return p;
}