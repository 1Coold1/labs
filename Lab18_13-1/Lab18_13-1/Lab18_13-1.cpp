#include <iostream>
#include <deque>
#include <algorithm>
#include "Time.h"
using namespace std;

typedef deque<Time> Tdeq;
Time s;

Tdeq make_deque(int n) 
{
	Time a; 
	Tdeq d; 
	for (int i = 0; i < n; i++) 
	{
		cin >> a; 
		d.push_back(a);
	} 
	return d;
}

void print_deque(Tdeq d) 
{
	for (int i = 0; i < d.size(); i++)
	cout << d[i] << endl; 
	cout << endl;
}

struct Equal_s {
	bool operator()(Time t) {
		return t == s;
	}
};

Time srednee(Tdeq v) {
	Time s = v[0];
	//перебор вектора 
	for(int i=1;i<v.size();i++) s=s+v[i];
	int n = v.size();//количество элементов в векторе 
	return s/n;
}

void sum(Time& t)
{
	t = t + s;
}

int main()
{
	setlocale(LC_ALL, "rus");
	Tdeq::iterator i;
	int n; 
	cout << "Введите количество элементов: "; 
	cin >> n; 
	Tdeq v;
	v = make_deque(n);
	print_deque(v);
	i = max_element(v.begin(), v.end());
	s = *i;
	cout << "Максимальный элемент: " << s << endl;
	v.push_back(s);
	print_deque(v);
	cout << "Введите ключ для удаления: ";
	cin >> s;
	i = remove_if(v.begin(), v.end(), Equal_s());
	v.erase(i, v.end());
	print_deque(v);
	s = srednee(v);
	cout << "Среднее арифметическое: " << s << endl;
	for_each(v.begin(), v.end(), sum);
	print_deque(v);
}