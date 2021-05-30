#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Time
{
public: 	
	Time() { min = 0; sec = 0; };
	Time(int m, int s) { min = m; sec = s; }
	Time(const Time& t) { min = t.min; sec = t.sec; }
    ~Time() {};
	Time& operator=(const Time&);
	Time& operator+(int);
	Time operator+(const Time&);
	friend bool operator==(const Time& t1, const Time& t2);
	friend bool operator!=(const Time& t1, const Time& t2);
	friend istream& operator>>(istream& in, Time& t);
	friend ostream& operator<<(ostream& out, const Time& t);
	friend fstream& operator>>(fstream& fin, Time& t); 
	friend fstream& operator <<(fstream& fout, const Time& t);
	bool operator >(const Time&);
	bool operator <(const Time&);
	bool operator >=(const Time&);
	bool operator <=(const Time&);
	bool operator ==(const Time&);
	bool operator !=(const Time&);
private:
	int min; 
	int sec;
};