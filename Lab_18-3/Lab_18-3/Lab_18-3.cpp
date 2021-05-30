#include "Time.h" 
#include <iostream> 
using namespace std;
void main() {
	setlocale(LC_ALL, "Rus");
	Time a;//конструктор без параметров 
	Time b; //конструктор без параметров 
	cout << "a: "<<endl;
	cin>>a;//ввод переменной 
	cout << "b: "<<endl;
	cin>>b;//ввод переменной 
	if (a == b) cout << "Временные промежутки равны" << endl;
	if (a != b) cout << "Временные промежутки неравны" << endl;
	cout << "Префиксный инкримент:" << endl;
	++a;//префиксная операция инкремент 
	cout << "a: " << a << endl;//вывод переменной 
	cout << "Постфиксный инкримент:" << endl;
	b++;//сложение и постфиксная операция инкремент 
	cout << "b: " << b << endl;
	if (a == b) cout << "Временные промежутки равны" << endl;
	if (a != b) cout << "Временные промежутки неравны" << endl;
}