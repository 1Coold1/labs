#include "Vector.h"
#include "Event.h"
Vector::Vector(void) {}
//���������� 
Vector::~Vector(void) 
{
if (beg != 0) delete[] beg; 
beg = 0;
}
//����������� � ����������� 
Vector::Vector(int n) 
{
beg = new Object * [n]; 
cur = 0; 
size = n;
}
//���������� �������, �� ������� ��������� ��������� p � ������ 
void Vector::Add()
{
	Object* p;
//����� �� �������� ���� ��������� ������� 
cout<<"1.Print"<<endl; 
cout<<"2.Book"<<endl; 
int y; 
cin>>y; 
if(y==1)//���������� ������� ������ Car 
{
Print* a = new (Print); 
a->Input();//���� �������� ��������� 
p=a;
if (cur < size) 
{
	beg[cur] = p;//���������� � ������ 
	cur++;
} 
}
else
if (y == 2) //���������� ������� ������ Lorry 
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
 //�������� �������
void Vector::Show() {
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//��������� �� ��������� ���� Object 
	for(int i=0;i<cur;i++) 
	{
	(*p)->Show();//����� ������ Show() (������� ����������) 
	p++;//����������� ��������� �� ��������� ������
	} 
}
//��������, ������� ���������� ������ ������� 
int Vector::operator ()() { return cur; }
//�������� �������� �� �������, ������ �� �������������! 
void Vector::Del() 
{
if (cur == 0) return;//������ 
cur--;
}

void Vector::HandleEvent(const TEvent& e) 
{
	if (e.what == evMessage) 
	{
		Object** p = beg; 
		for (int i = 0; i < cur; i++)
		{
			if (i==e.a-1) (*p)->HandleEvent(e);//����� ������ (������� ����������) 
			p++;//����������� ��������� �� ��������� ������
		}
	}
}