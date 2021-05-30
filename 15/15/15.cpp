#include <iostream>

#include <string>

#include <fstream>

#include <vector>

using namespace std;

struct Product

{

	string name;

	long int price = 0;

};

void Shell(vector<Product>& array, int size)

{

	int temp1, j;

	string temp2;

	for (int step = size / 2; step > 0; step /= 2)

	{

		for (int i = step; i < size; i++)

		{

			temp1 = array[i].price;

			temp2 = array[i].name;

			for (j = i; j >= step; j -= step)

			{

				if (temp1 < array[j - step].price)

				{

					array[j].price = array[j - step].price;

					array[j].name = array[j - step].name;

				}

				else break;

			}

			array[j].price = temp1;

			array[j].name = temp2;

		}

	}

}

void Hoare(vector <Product>& list, int left, int right)

{

	long int pivot = list[(left + right) / 2].price;

	int l = left;

	int j = right;

	do

	{

		while ((list[l].price < pivot) && (l < right))

		{

			l++;

		}

		while ((list[j].price > pivot) && (j > left))

		{

			j--;

		}

		if (l <= j)

		{

			swap(list[l], list[j]);

			l++;

			j--;

		}

	}

	while (l <= j);

	if (j > left)

	{

		Hoare(list, left, j);

	}

	if (l < right)

	{

		Hoare(list, l, right);

	}

}

int main()

{

	system("chcp 1251 > nul");

	setlocale(LC_ALL, "ru");

	int size = -1, left = 0;

	while (size < 1)

	{

		cout << "Введите количество товаров: ";

		cin >> size;

		cout << endl;

	}

	vector <Product> product(size);

	for (int i = 0; i < size; i++)

	{

		cout << "Товар: ";

		cin >> product[i].name;

		cout << "Цена: ";

		cin >> product[i].price;

	}

	cout << endl;

	int menu = -1;

	while (menu != 1 && menu != 2)

	{

		cout << "Выбери метод сортировки: \n 1. Хоара \n 2. Шелла \n Ввод: ";

		cin >> menu;

	}

	if (menu == 2)

		Shell(product, size);

	if (menu == 1)

		Hoare(product, left, size - 1);

	cout << "Результат:" << endl;

	for (int i = 0; i < size; i++)

	{

		cout << product[i].name << ": " << product[i].price << endl;

	}

}