#include <iostream>
using namespace std;

struct List
{
    char data;
    List* next;
};

List* make_list(int n, List*& first, List*& last) {
    if (n == 0) return NULL;
    List* p = new List;
    char a;
    cin >> a;
    p->data = a;
    p->next = NULL;
    first = p;
    last = p;
    for (int i = 2; i <= n; i++) {
        List* h = new List;
        cin >> a;
        h->data = a;
        h->next = p;
        last = h;
        p = last;
    }
    return first;
}

void addToPos(const int value, int Pos, List*& last)             //добавление в указанную
{                                                   //позицию
    List* tmp = last;
    List* cur = NULL;
    List* Ptr = new List;
    Ptr->data = value;

    if (Pos == 1) {
        Ptr->data = value;
        Ptr->next = last;
        last = Ptr;
    }
    else
    {
        int Kol_el = 1;
        while (tmp != NULL && Kol_el != Pos)
        {
            cur = tmp;
            tmp = tmp->next;
            ++Kol_el;
        }

        cur->next = Ptr;
        Ptr->next = tmp;
    }
}


    void print_list(List* last)
    {
        List* p = last;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
    }

    int main() {
        setlocale(LC_ALL, "rus");
        int n,l;
        char a;
        List* first, * last;
        do {
            cout << "Введите количество элементов: ";
            cin >> n;
        } while (n <= 0);
        cout << "Введите элементы: ";
        make_list(n, first, last);
        print_list(last);
        do {
            cout << endl << "Введите номер добавляемого элемента: ";
            cin >> l;
        } while ((l < 1) || (l>n+1));
        cout << "Введите добавляемый элемент: ";
        cin >> a;
        addToPos(a, l, last);
        print_list(last);
    }