#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Print : public Object
{
public: public:
	Print(void);//конструктор без параметров
	virtual ~Print(void);//деструктор 
	void Show();//функция для просмотра атрибутов класса с помощью указателя 
	void Input();//функция для ввода значений атрибутов 
	Print(string,string);//конструктор с параметрами 
	Print(const Print&);//конструктор копирования
	//селекторы
	string Get_name() { return name; } 
	string Get_author() { return author; }
	//модификаторы 
	void Set_name(string); 
	void Set_author(string); 
	Print& operator=(const Print&);//перегрузка операции присваивания
	void HandleEvent(const TEvent& e);
protected:
	string name;
	string author;
};