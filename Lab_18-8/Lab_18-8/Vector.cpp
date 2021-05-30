#include "Vector.h"
#include "Event.h"
Vector::Vector(void) {}
//деструктор 
Vector::~Vector(void) 
{
if (beg != 0) delete[] beg; 
beg = 0;
}
//конструктор с параметрами 
Vector::Vector(int n) 
{
beg = new Object * [n]; 
cur = 0; 
size = n;
}
//добавление объекта, на который указывает указатель p в вектор 
void Vector::Add()
{
	Object* p;
//выбор из объектов двух возможных классов 
cout<<"1.Print"<<endl; 
cout<<"2.Book"<<endl; 
int y; 
cin>>y; 
if(y==1)//добавление объекта класса Car 
{
Print* a = new (Print); 
a->Input();//ввод значений атрибутов 
p=a;
if (cur < size) 
{
	beg[cur] = p;//добавление в вектор 
	cur++;
} 
}
else
if (y == 2) //добавление объекта класса Lorry 
{
Book* b = new Book; 
b->Input(); 
p = b; 
if (cur < size)
{
	beg[cur] = p; 
	cur++;
} 
}
 else return; 
}
 //просмотр вектора
void Vector::Show() {
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//указатель на указатель типа Object 
	for(int i=0;i<cur;i++) 
	{
	(*p)->Show();//вызов метода Show() (позднее связывание) 
	p++;//передвигаем указатель на следующий объект
	} 
}
//операция, которая возвращает размер вектора 
int Vector::operator ()() { return cur; }
//удаление элемента из вектора, память не освобождается! 
void Vector::Del() 
{
if (cur == 0) return;//пустой 
cur--;
}

void Vector::HandleEvent(const TEvent& e) 
{
	if (e.what == evMessage) 
	{
		Object** p = beg; 
		for (int i = 0; i < cur; i++)
		{
			if (i==e.a-1) (*p)->HandleEvent(e);//вызов метода (позднее связывание) 
			p++;//передвигаем указатель на следующий объект
		}
	}
}