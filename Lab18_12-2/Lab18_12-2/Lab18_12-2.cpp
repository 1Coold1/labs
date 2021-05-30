#include <iostream> 
#include <map> 
#include "Time.h"
using namespace std;
typedef map<int, Time>TMap;//определяем тип для работы со словарем 
typedef TMap::iterator it;//итератор
//функция для формирования словаря 
TMap make_map(int n)
{
	TMap m;//пустой словарь 
	Time a;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент: "; cin >> a;
		//создаем пару и добавляем ее в словарь 
		m.insert(make_pair(i, a));
	}
	return m;//возвращаем словарь как результат работы функции 
}
//функция для печати словаря 
void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++) cout << i << " : " << m[i] << " " << endl;
	cout << "------------------------------------------" << endl;
}

//поиск максимального элемента 
int Max(TMap v)
{
	it i = v.begin();
	int nom = 0,//номер максимального 
		k = 0;//счетчик элементов 
	Time m = (*i).second;//значение первого элемента 
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;//итератор 
		k++;//счетчик элементов
	}
	return nom;//номер max
}

Time srednee(TMap v) {
	Time s=v[0];
	//перебор словаря 
	for (int i = 1; i < v.size(); i++) s = s + v[i];
	int n = v.size();//количество элементов в словаре 
	return s/n;
}

void sum(TMap& v) {
	Time sr = srednee(v);
	cout << "Среднее арифметическое: " << sr << endl;
	for (int i = 0; i < v.size(); i++) v[i] = v[i] + sr;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, k;
	cout << "Введите количество элементов: ";
	cin >> n;//количество элементов 
	it i;
	TMap m = make_map(n);//создать словарь
	int max = Max(m);
	print_map(m);//напечатать словарь
	m.insert(make_pair(n, m[max]));
	print_map(m);//напечатать словарь
	cout << "Введите ключ для удаления: ";
	cin >> k;
	m.erase(k);
	print_map(m);//напечатать словарь
	sum(m);
	print_map(m);//напечатать словарь
}