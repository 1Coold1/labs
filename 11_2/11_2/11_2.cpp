#include <iostream>
using namespace std;

struct List {
	char data;
	List* next;
	List* prev;
};

List* make(int size) {

	List* first, * p;

	first = NULL;
	p = new List;
	cout << "Введите 1 элемент ";
	p = new List;
	cin >> p->data;
	first = p;
	p->next = NULL;
	p->prev = NULL;
	for (int i = 2; i <= size; i++) {
		List* h = new List;
		List* q = p;
		p->next = h;
		p = p->next;
		cout << "Введите " << i  << " элемент ";
		cin >> p->data;
		p->next = NULL;
		p->prev = q;
	}
	return first;
}

void print(List* first) {
	if (first == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		List* p = first;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void add(List*& top, int pos, int x)
{
	int j = 1;
	int i; List* pnew, * p = top;
	pnew = new List; pnew->data = x;
	if (pos <= 1 || top == NULL)
	{
		pnew->next = top; top = pnew;
	}
	else
	{
		for (i = 1; i < pos - 1; i++)
			if (p->next != NULL)
			{
				p = p->next;
				j++;
			}
		if (pos <= j + 1)
		{
			pnew->next = p->next; p->next = pnew;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	int size,pos;
	char x;
	do {
		cout << "Размер списка: ";
		cin >> size;
	} while (size <= 0);

	List* list = make(size);
	cout << "Ваш список " << endl;
	print(list);
	do {
		cout << "Введите номер позиции для вставки: ";
		cin >> pos;
	} while ((pos < 1) || (pos > size + 1));
	cout << "Введиде значение элемента для вставки: ";
	cin >> x;
	add(list, pos, x);
	print(list);
}