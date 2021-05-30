#include <iostream>
#include <deque>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	deque<int> v = { 1, 2, 3, 4, 5 };
	int max=-99999999,k=0,s=0;
	float sa=0;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;
	for (int i = 0; i < v.size(); i++)
		if (v[i] > max) max = v[i];
	v.push_back(max);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;

	cout << "Введите ключ: ";
	cin >> k;
	v.erase(remove(v.begin(), v.end(), k), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\t";
	cout << endl;

	for (int i = 0; i < v.size(); i++)
		s += v[i];
	sa = float(s) / v.size();
	cout << "Среднее арифметическое: " << sa;
	cout << endl;
	sa = round(sa);
	cout << "Округленное среднее арифметическое: " << sa;
	cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		v[i] += sa;
		cout << v[i] << "\t";
	}
	cout << endl;
}
