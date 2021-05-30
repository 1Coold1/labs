#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Print : public Object
{
public: public:
	Print(void);//����������� ��� ����������
	virtual ~Print(void);//���������� 
	void Show();//������� ��� ��������� ��������� ������ � ������� ��������� 
	void Input();//������� ��� ����� �������� ��������� 
	Print(string,string);//����������� � ����������� 
	Print(const Print&);//����������� �����������
	//���������
	string Get_name() { return name; } 
	string Get_author() { return author; }
	//������������ 
	void Set_name(string); 
	void Set_author(string); 
	Print& operator=(const Print&);//���������� �������� ������������
	void HandleEvent(const TEvent& e);
protected:
	string name;
	string author;
};