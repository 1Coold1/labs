#pragma once
#include "Time.h"
#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 
int make_file(const char* f_name) {
	fstream stream(f_name, ios::out | ios::trunc);//открыть для записи 
	if (!stream)return -1;//ошибка открытия файла 
	int n;
	Time t;
	cout << "Введите количество атрибутов: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//ввод атрибутов объекта из стандартного потока 
		stream << t << "\n";//запись объекта в файловый поток
	}
	stream.close();//закрыть поток 
	return n;//вернуть количество записанных объектов
}
int print_file(const char* f_name) 
{
	fstream stream(f_name, ios::in);//открыть для чтения 
	if(!stream)return -1;//ошибка открытия файла 
	Time t; 
	int i=0; 
	while(stream>>t)
	{
		cout << t << "\n"; 
		i++;
	}
	stream.close(); 
	return i;
}

int del_file(const char* f_name, Time a, Time b) {
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if(!stream)return -1;//ошибка открытия файла 
	int i=0;
	Time t; 
	while (stream >> t)//пока нет конца файла выполняем чтение объекта 
	{
		//если прочитан признак конца файла,то выход из цикла 
		if (stream.eof())break; i++;
		//если номер объекта не равен k, то записываем его во вспомогательый файл 
		if ((t > b) || (t < a)) temp << t <<"\n";
	}
	//закрыть файлы
	stream.close(); 
	temp.close(); 
	remove(f_name);//удалить старый файл 
	rename("temp", f_name);// переименоватьtemp 
	return i;//количество прочитанных
}

int change_file(const char* f_name, Time key) 
{
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name,ios::in);//открыть для чтения 
	if(!stream)return -1;//ошибка открытия файла 
	Time t,a; 
	a=Time(1, 30);
	int i=0, 
		l=0; 
	char x; 
	while(stream>>t) 
	{
	if (stream.eof())break; 
	i++; 
	if (t == key)
	{
		cout << t << " - is changing... Continue[y/n]?\n";
		cin >> x;
		if (x == 'n' || x == 'N')break;
		temp << t + a << "\n";
		l++;
	}
	else temp << t << "\n";
	}
	stream.close(); 
	temp.close(); 
	remove(f_name); 
	rename("temp", f_name); 
	return l;//количество измененных элементов
}

int add_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name,ios::in);//открыть для чтения 
	if(!stream)return -1;//ошибка открытия файла 
	Time t,addt; 
	int i=0, 
		l=0; 
	while (i < k)
	{
		cout << "Введите значение нового элемента: ";
		cin >> addt;
		temp << addt << "\n";//записать в temp новую запись 
		i++;
		l++;
	}
	while(stream>>t) 
	{
		if (stream.eof())break; 
		temp << t<<"\n";
	}
	stream.close(); 
	temp.close(); 
	remove(f_name); 
	rename("temp", f_name); 
	return l;//количество добавленных
}