#include <iostream>
using namespace std;

class Interval
{
	double first, second;
public:
	void set() {
		cout << "Введите левую границу: ";
		cin >> first;
		do {
			cout << "Введите правую границу: ";
			cin >> second;
		} while (second <= first);
	}

	void rangecheck(double x) {
		if ((x >= first) && (x <= second)) cout << "Число входит в промежуток"<<endl;
		else cout << "Число не входит в промежуток"<<endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	Interval a;
	double x;
	int t;
	a.set();
	cout << "Введите количество проверок: ";
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Введите число для проверки: ";
		cin >> x;
		a.rangecheck(x);
	};
	return 0;
}