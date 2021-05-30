#include "Print.h"
//конструктор без параметров
Print::Print(void) {
	name = "";
	author = "";
}
//деструктор 
Print::~Print(void) { }
//констрктор с параметрами 
Print::Print(string N,string A) {
	name = N;
	author = A;
}
//конструктор копирования 
Print::Print(const Print& print) {
	name = print.name;
	author = print.author;
}
//селекторы 
void Print::Set_name(string N) {
	name = N; 
}
void Print::Set_author(string A) {
	author = A;
}
//оператор присваивания 
Print& Print::operator=(const Print&p) {
	if (&p == this) return *this; 
	name = p.name; 
	author = p.name;
	return *this;
}
//метод для просмотра атрибутов 
void Print::Show()
{
	cout << "\nНазвание : " << name; 
	cout << "\nАвтор : " << author; 
	cout << "\n";
}
//метод для ввода значений атрибутов 
void Print::Input()
{ 
	cout << "\nНазвание:"; 
	cin >> name;
	cout << "\nАвтор:"; 
	cin >> author; 
}

void Print::HandleEvent(const TEvent& e) {
	if (e.what == evMessage)//событие-сообщение 
	{
		switch (e.command) 
		{
		case cmGet:cout << "Название: " << Get_name() << endl; 
			break;
		}
}
}