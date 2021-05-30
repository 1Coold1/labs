#pragma once
#include <iostream>
#include <string>
using namespace std;

class Number 
{
	float mantissa;
	int poryadok;
	string stroka;
public:
	Number();
	Number(float, int, string);
	Number(const Number&);
	~Number();
	float get_mantissa();
	void set_mantissa(float);
	int get_poryadok();
	void set_poryadok(int);
	string get_stroka();
	void set_stroka(string);
	void show();
};