#include <iostream>
#include "Book.h"
#include "Object.h"
#include "Print.h"
#include "Vector.h"
#include "Event.h"
#include <windows.h>
#include "Dialog.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*Print* a = new Print;//создаем объект класса Print
	a->Input();
	Book *b=new Book; //создаем объект класса Lorry
	b->Input();
	Vector v(10);//Создаем вектор
	Object* p = a;//ставим указатель на объект класса Print
	v.Add(p);//добавляем объект в вектор
	p=b;//ставим указатель на объект класса Lorry
	v.Add(p); //добавляем объект в вектор
	v.Show();//вывод вектора
	v.Del();//удаление элемента
	cout << "\nРазмер вектора=" << v();*/
	Dialog D;
	D.Execute();
}