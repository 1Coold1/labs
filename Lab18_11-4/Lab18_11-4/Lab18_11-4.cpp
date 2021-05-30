#include <iostream>
#include "Time.h"
#include <queue>
#include <vector>

typedef queue<Time>q;
typedef vector<Time>v;

q make_queue(int n) {
	q que; 
	Time t; 
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		que.push(t);
	} 
	return que;
}

v copy_queue_to_vector(q que) {
	v vec; 
	while (!que.empty())//пока стек не пустой 
	{
	//добавить в вектор элемент из вершиы стека 
		vec.push_back(que.front()); 
		que.pop();
	} 
	return vec; //вернуть вектор как результат функции
}

void copy_vector_to_queue(v& vec,q& que) {
	for (int i = 0; i < vec.size(); i++) 
	{
		que.push(vec[i]);
		
	}
}

void print_queue(q que)
{
	while (!que.empty())
	{
		Time val = que.front();
		que.pop();
		cout << val << " ";
	}
	cout << endl;
}

Time Max(q que) {
	Time m = que.front(); 
	v vec = copy_queue_to_vector(que); 
	while (!que.empty()) {
		if (que.front() > m) m = que.front(); 
		que.pop();
	}
	copy_vector_to_queue(vec,que);
	return m;
}

void Delete_from_queue(q& que, Time k) {
	v vec; 
	Time t; 
	while(!que.empty())//пока стек не пустой 
	{
	t = que.front();//получаем элемент из вершины стека
	//если он не равен максимальному, заносим элемент в вектор 
	if(t!=k) vec.push_back(t); 
	que.pop();//удаляем элемент из стека
	}
	copy_vector_to_queue(vec,que);//копируем вектор в стек
}

Time Srednee(q que) 
{
	v vec = copy_queue_to_vector(que);//копируем стек в вектор 
	int n=1; 
	Time sum=que.front();//начальное значениедля суммы 
	que.pop();//удалить первый элемент из вектора 
	while(!que.empty())//пока стек не пустой 
	{
	sum = sum + que.front();//добавить в сумму элемент из вершины стека 
	que.pop();//удалить элемент 
	n++;
	} 
	copy_vector_to_queue(vec,que);//скопировать вектор в стек 
	return sum/n; //вернуть среднее арифметическое
}

void Sum(q& que) 
{
	Time m = Srednee(que);
	cout << "Среднее арифметическое: " << m << endl;
	v vec; Time t; 
	while(!que.empty())//пока стек не пустой 
	{
		t = que.front();//получаем элемент из вершины 
		vec.push_back(t+m);
		que.pop();//удаляем элемент из вершины
	} 
	copy_vector_to_queue(vec,que);//копируем вектор в стек
}

int main()
{
	setlocale(LC_ALL, "rus");
	Time t,k; 
	q que; 
	int n; 
	cout << "n?"; 
	cin >> n;
	que = make_queue(n);//создать стек
	print_queue(que);//печать стека
	que.push(Max(que));
	print_queue(que);//печать стека
	cout << "Введите ключ для удаления: ";
	cin >> k;
	Delete_from_queue(que, k);
	print_queue(que);//печать стека
	Sum(que);
	print_queue(que);//печать стека
}
