#include <iostream>
#include "Time.h"
#include <deque>
#include <queue>
using namespace std;
typedef queue<Time>q;
typedef deque<Time>d;
Time s;

q make_queue(int n)
{
	Time a;
	q que;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		que.push(a);
	}
	return que;
}

d copy_queue_to_deque(q que) 
{
	d deq;
	while (!que.empty())//пока стек не пустой 
	{
		//добавить в вектор элемент из вершиы стека 
		deq.push_back(que.front());
		que.pop();
	}
	return deq; //вернуть вектор как результат функции
}

void copy_deque_to_queue(d& deq, q& que)
{
	for (int i = 0; i < deq.size(); i++)
	{
		que.push(deq[i]);
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

struct Equal_s {
	bool operator()(Time t) {
		return t == s;
	}
};

Time srednee(d deq) {
	Time s = deq[0];
	//перебор вектора 
	for (int i = 1; i < deq.size(); i++) s = s + deq[i];
	int n = deq.size();//количество элементов в векторе 
	return s / n;
}

void sum(Time& t)
{
	t = t + s;
}

int main()
{
	setlocale(LC_ALL, "rus");
	d::iterator i;
	q que;
	d deq;
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	que = make_queue(n);
	print_queue(que);
	deq = copy_queue_to_deque(que);
	i = max_element(deq.begin(), deq.end());
	s = *i;
	cout << "Максимальный элемент: " << s << endl;
	deq.push_back(s);
	while (!que.empty())//пока стек не пустой 
	{
		que.pop();//удалить элемент 
	}
	copy_deque_to_queue(deq, que);
	print_queue(que);
	cout << "Введите ключ для удаления: ";
	cin >> s;
	while (!deq.empty())//пока стек не пустой 
	{
		deq.pop_back();//удалить элемент 
	}
	deq = copy_queue_to_deque(que);
	i = remove_if(deq.begin(), deq.end(), Equal_s());
	deq.erase(i, deq.end());
	while (!que.empty())//пока стек не пустой 
	{
		que.pop();//удалить элемент 
	}
	copy_deque_to_queue(deq, que);
	print_queue(que);
	while (!deq.empty())//пока стек не пустой 
	{
		deq.pop_back();//удалить элемент 
	}
	deq = copy_queue_to_deque(que);
	s = srednee(deq);
	cout << "Среднее арифметическое: " << s << endl;
	for_each(deq.begin(), deq.end(), sum);
	while (!que.empty())//пока стек не пустой 
	{
		que.pop();//удалить элемент 
	}
	copy_deque_to_queue(deq, que);
	print_queue(que);
}