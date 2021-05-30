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
	int t = min * k.min*60; 
	int kt = sec * k.sec; 
	t += kt; 
	Time temp(t / 60, t % 60); 
	return temp;
}