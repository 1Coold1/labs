#include "Time.h"
Time::Time(void)
{
	min = sec = 0;
}
Time::Time(int M, int S)
{
	min = M;
	sec = S;
}
Time::Time(const Time& t)
{
	min = t.min;
	sec = t.sec;
}
Time& Time::operator =(const Time& t)
{
	min = t.min;
	sec = t.sec;
	return*this;
}
ostream& operator<<(ostream& out, const Time& t)
{
	out << t.min << ":" << t.sec;
	return out;
}
istream& operator>>(istream& in, Time& t)
{
	cout << "\n¬ведите минуты: "; in >> t.min;
	do {
		cout << "\n¬ведите секунды: "; in >> t.sec;
	} while ((t.sec < 0) || (t.sec >= 60));
	return in;
}
Time Time::operator*(Time k)
{
	int t = min * k.min * 60;
	int kt = sec * k.sec;
	t += kt;
	Time temp(t / 60, t % 60);
	return temp;
}
Time& Time::operator=(int t)
{
	min = t;
	sec = t;
	return *this;
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
Time Time::operator/(const Time& t) {
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