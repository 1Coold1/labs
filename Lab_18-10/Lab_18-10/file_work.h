#pragma once
#include "Time.h"
#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 
int make_file(const char* f_name) {
	fstream stream(f_name, ios::out | ios::trunc);//������� ��� ������ 
	if (!stream)return -1;//������ �������� ����� 
	int n;
	Time t;
	cout << "������� ���������� ���������: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//���� ��������� ������� �� ������������ ������ 
		stream << t << "\n";//������ ������� � �������� �����
	}
	stream.close();//������� ����� 
	return n;//������� ���������� ���������� ��������
}
int print_file(const char* f_name) 
{
	fstream stream(f_name, ios::in);//������� ��� ������ 
	if(!stream)return -1;//������ �������� ����� 
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
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if(!stream)return -1;//������ �������� ����� 
	int i=0;
	Time t; 
	while (stream >> t)//���� ��� ����� ����� ��������� ������ ������� 
	{
		//���� �������� ������� ����� �����,�� ����� �� ����� 
		if (stream.eof())break; i++;
		//���� ����� ������� �� ����� k, �� ���������� ��� �� �������������� ���� 
		if ((t > b) || (t < a)) temp << t <<"\n";
	}
	//������� �����
	stream.close(); 
	temp.close(); 
	remove(f_name);//������� ������ ���� 
	rename("temp", f_name);// �������������temp 
	return i;//���������� �����������
}

int change_file(const char* f_name, Time key) 
{
	fstream temp("temp", ios::out);//������� ��� ������ 
	fstream stream(f_name,ios::in);//������� ��� ������ 
	if(!stream)return -1;//������ �������� ����� 
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
	return l;//���������� ���������� ���������
}

int add_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//������� ��� ������ 
	fstream stream(f_name,ios::in);//������� ��� ������ 
	if(!stream)return -1;//������ �������� ����� 
	Time t,addt; 
	int i=0, 
		l=0; 
	while (i < k)
	{
		cout << "������� �������� ������ ��������: ";
		cin >> addt;
		temp << addt << "\n";//�������� � temp ����� ������ 
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
	return l;//���������� �����������
}