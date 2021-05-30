#include "Time.h" 
#include "file_work.h"
#include <iostream> 
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");

	Time t,a,b,key; 
	int k, c; 
	char file_name[30]; 
	do {
		//Меню
		cout << "\n1. Создать файл";//создание файла 
		cout << "\n2. Печать файла";//печать файла
		cout << "\n3. Удаление элементов";
		cout << "\n4. Изменение элементов";
		cout << "\n5. Добавление элементов";
		cout<<"\n0. Выход\n"; 
		cin>>c; 
		switch (c)
		{
		case 1:
			cout << "Введите имя файла: ";
			cin >> file_name;//задаем имя файла 
			k = make_file(file_name);//вызов функции для записи в файл 
			if (k < 0)cout << "Не удается создать файл";//вывод сообщения об ошибке 
			break;
		case 2:
			cout << "Введите имя файла: ";
			cin >> file_name;//задаем имя файла 
			k = print_file(file_name);//вызов функции для печати файла 
			if (k == 0)cout << "Пустой файл\n";//если файл пустой 
			if (k < 0)cout << "Не удается открыть файл\n";//если файл нельзя открыть
			break;

		case 3:
			cout << "Введите имя файла: ";
			cin >> file_name;//задаем имя файла 
			cout << "Введите левую границу: ";
			cin >> a;
			do {
				cout << "Введите правую границу: ";
				cin >> b;
			} while (b <= a);
			k = del_file(file_name, a, b);
			if (k == 0)cout << "Пустой файл\n";//если файл пустой 
			if (k < 0)cout << "Не удается открыть файл\n";//если файл нельзя открыть
			break;
		case 4:
			cout << "Введите имя файла: ";
			cin >> file_name;//задаем имя файла 
			cout << "Введите ключ для изменения элементов: ";
			cin >> key;
			k = change_file(file_name, key);
			if (k == 0)cout << "Нет элементов с таким ключом\n";//если файл пустой 
			if (k < 0)cout << "Не удается открыть файл\n";//если файл нельзя открыть
			break;
		case 5:
			cout << "Введите имя файла: ";
			cin >> file_name;//задаем имя файла 
			cout << "Введите количество добавляемых элементов: ";
			cin >> k;
			k = add_file(file_name, k);
			if (k == 0)cout << "Пустой файл\n";//если файл пустой 
			if (k < 0)cout << "Не удается открыть файл\n";//если файл нельзя открыть
			break;
		}

	}
	while (c != 0);
}