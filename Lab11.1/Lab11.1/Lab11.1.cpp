#include <iostream>
using namespace std;

struct List {
	int data;
	List* next;
};

List* make(int size) {

	List* first, * p;

	first = NULL;
	cout << "Введите 1 элемент ";
	p = new List;
	cin >> p->data;
	first = p;
	for (int i = 2; i <= size; i++) {
		List* h = new List;
		p->next = h;
		p = p->next;
		cout << "Введите " << i  << " элемент ";
		cin >> p->data;
		p->next = NULL;
	}
	return first;
}

void print(List* first) {
	if (first == NULL) {
		cout << "Список пуст" << endl;
	}
	else {
		List* p = first;
		do {
			cout << p->data << " ";
			p = p->next;
		} while (p != NULL);
		cout << endl;
	}
}

void del(List*& first) {
	List* p = first;
	List* q = new List;
	while (p != NULL) {
		if (p->data % 2 == 0) q = p;
		p = p->next;
	}
	p = first;
	if (p == q) {
		p = p->next;
		delete first;
		first = p;
	}
	else {
		while (p->next != NULL) {
			if (p->next == q) {
				List* x = p->next;
				p->next = p->next->next;
				delete x;
			}
			else p = p->next;
		}
	}
	p = first;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int size;
	do {
		cout << "Размер списка: ";
		cin >> size;
	} while (size <= 0);

	List* list = make(size);
	cout << "Ваш список " << endl;
	print(list);
	del(list);
	print(list);
	return 0;
}