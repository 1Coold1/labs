#include "Time.h" 
//���������� �������� ������������ 
Time& Time::operator=(const Time& t) {
    //�������� �� ���������������� 
    if (&t == this) return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}
//���������� �������� ���������� ������ 
Time& Time::operator+(int s) {
    int temp = min * 60 + sec+s;
    min = temp / 60;
    sec = temp % 60;
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
    return (out << t.min << " : " << t.sec);
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
//������������� ������� ��� ������ � ��������� �������� 
fstream& operator>>(fstream& fin, Time&t) {
    string buf;
    fin >> t.min; 
    fin >> buf;
    fin >> t.sec; 
    return fin;
}
fstream& operator<<(fstream& fout, const Time& t) {
    fout << t.min << " : " << t.sec; 
    return fout;
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
bool Time::operator <=(const Time& t) {
    if (min <= t.min)return true;
    if (min == t.min && sec <= t.sec)
        return true;
    return false;
}
bool Time::operator >=(const Time& t) {
    if (min >= t.min)return true;
    if (min == t.min && sec >= t.sec)
        return true;
    return false;
}
bool Time::operator ==(const Time& t) {
    if (min == t.min && sec == t.sec)
        return true;
    return false;
}
bool Time::operator !=(const Time& t) {
    if (min != t.min || sec != t.sec)
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