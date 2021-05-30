#include <iostream>
using namespace std;
int a;
bool f=true;

struct Stack {
    int data;
    Stack* prev;
};

Stack* x;

Stack* make_stack(int n) {
    if (n == 0) return NULL;
    Stack* top, * p;
    top = NULL;
    p = new Stack;
    cin >> a;
    p->data = a;
    if ((p->data % 2 == 0) && f) {
        x = p;
        f = false;
    }
    p->prev = NULL;
    top = p;
    for (int i = 2; i <= n; i++) {
        Stack* h = new Stack;
        cin >> a;
        h->data = a;
        if ((h->data % 2 == 0) && f) {
            x = h;
            f = false;
        }
        h->prev = top;
        top = h;
    }
    return top;
}

void print_stack(Stack* top) {
    if (top == NULL) {
        cout << "Стек пуст" << endl;
    }
    else {
        Stack* p = top;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }
}

void delete_stack(Stack*& top) {
    Stack* p = top; 
    if (p == x) {
        p = p->prev;
        delete top;
        top = p;
    }
    else {
        while ((p != NULL)) {
            if (p->prev == x) {
                Stack* q = p->prev;
                p->prev = p->prev->prev;
                delete q;
            }
            else p = p->prev;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n;
    do {
        cout << "Введите количество элементов: ";
        cin >> n;
    } while (n <= 0);
    cout << "Введите элементы: ";
    Stack* st = make_stack(n);
    cout << "Стек: ";
    print_stack(st);
    delete_stack(st);
    cout << "Стек: ";
    print_stack(st);
}
