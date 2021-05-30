#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int count;

struct Person
{
    char surname[30], name[30], middlename[30];
    char address[100];
    int pasport;
};

struct dat
{
    string fio;
    string date;
    int pass;
    string pass1;
};

void form_file();
void read_file();
void work_file();
void line_search();
Person create();

int main()
{
    system("chcp 1251>null");

    int oper;

    do
    {
        cout << "1.Сформировать файл" << endl;
        cout << "2.Работа с файлом" << endl;
        cout << "3.Выход" << endl;

        cin >> oper;

        switch (oper)
        {
        case 1:
            form_file();
            break;
        case 2:
            work_file();
            break;
        default:
            break;
        }

    } while (oper != 3);
    return 0;
}

Person create()
{
    cout << "Фамилия: ";
    char surname[30];
    cin >> surname;

    cout << "Имя: ";
    char name[30];
    cin >> name;

    cout << "Отчество: ";
    char middlename[30];
    cin >> middlename;

    int pasport;
    do {
        cout << "Паспорт: ";
        cin >> pasport;
    } while (pasport < 0);
    
    cout << "Адрес: ";
    char address[100];
    cin.ignore();
    gets_s(address);


    Person p;
    strcpy(p.address, address);
    strcpy(p.middlename, middlename);
    strcpy(p.name, name);
    strcpy(p.surname, surname);
    p.pasport = pasport;

    return p;
}

void form_file()
{
    cout << "Кол-во людей = ";
    int count;
    cin >> count;

    FILE* file = fopen("file.dat", "wb");
    if (file == NULL)
        exit(1);

    for (int i = 0; i < count; i++)
    {
        Person p = create();

        fwrite(&p, sizeof(Person), 1, file);

        if (ferror(file))
            exit(2);
    }

    fclose(file);
}

void read_file()
{
    FILE* file = fopen("file.dat", "rb");
    Person p;
    cout << setw(15) << "ФИО" << setw(23) << "Паспорт" << setw(15) << "Адрес" << endl;

    while (fread(&p, sizeof(Person), 1, file))
    {
        char fio[30] = "";
        strcat(fio, p.surname);
        strcat(fio, " ");
        strcat(fio, p.name);
        strcat(fio, " ");
        strcat(fio, p.middlename);

        cout << setw(25) << fio << setw(10) << p.pasport << setw(20) << p.address << endl;
    }

    fclose(file);
}

void line_search()
{
    FILE* file = fopen("file.dat", "rb");
    Person p;
    int key, i = 1;
    bool f=false;
    cout << "Введите номер паспорта, который необходимо найти: ";
        cin >> key;
    while (fread(&p, sizeof(Person), 1, file))
    {
        if (p.pasport == key) {
            char fio[30] = "";
            strcat(fio, p.surname);
            strcat(fio, " ");
            strcat(fio, p.name);
            strcat(fio, " ");
            strcat(fio, p.middlename);

            cout << setw(25) << fio << setw(10) << p.pasport << setw(20) << p.address << endl;
            f = true;
        }
        if (f == false) i++;
    }
    if (f == true) {
        cout << "Находится на " << i << " месте." << endl;
    }
    else cout << "Такого номера нет" << endl;
    fclose(file);
}

void interpol()
{
    FILE* file = fopen("file.dat", "rb");
    Person p;
    int key, i = 1;
    bool f = false;
    cout << "Введите номер паспорта, который необходимо найти: ";
    cin >> key;
    while (fread(&p, sizeof(Person), 1, file))
    {
        if (p.pasport == key) {
            char fio[30] = "";
            strcat(fio, p.surname);
            strcat(fio, " ");
            strcat(fio, p.name);
            strcat(fio, " ");
            strcat(fio, p.middlename);

            cout << setw(25) << fio << setw(10) << p.pasport << setw(20) << p.address << endl;
            f = true;
        }
        if (f == false) i++;
    }
    if (f == true) {
        cout << "Находится на " << i << " месте." << endl;
    }
    else cout << "Такого номера нет" << endl;
    fclose(file);
}

void intersearch()

{

    int key, num = -1, mid = -1, left = 0, right = 4, i, temp, item;
    ofstream F("F.txt");
    dat N1 = { "Иванов Иван Иванович", "04.10.2002", 507263, "507263" };
    dat N2 = { "Петров Петр Петрович", "18.02.2010", 263598, "263598" };
    dat N3 = { "Алексеев Алексей Алексеевич", "06.12.2000", 648531, "648531" };
    dat N4 = { "Александров Александр Александрович", "06.10.2002", 984563, "984563" };
    dat N5 = { "Максимов Максим Максимович", "30.10.1998", 651234, "651234" };
    dat a[5] = { N1, N2, N3, N4, N5 };
    for (i = 0; i < 5; i++)
        cout << " " << i + 1 << ") " << '\t' << a[i].fio << endl << '\t' << a[i].date << endl << '\t' << a[i].pass << endl << "\n";
    cout << "Введи ключ (номер паспорта), по которому будет осуществлен поиск: "; cin >> key;
    int a1[5]{ N1.pass, N2.pass, N3.pass, N4.pass, N5.pass };
    for (i = 1; i < 5; i++) //Сортируем
    {
        temp = a1[i];
        item = i - 1;
        while (item >= 0 && a1[item] > temp)
        {
            a1[item + 1] = a1[item];
            a1[item] = temp;
            item--;
        }
    }
    while (a1[left] <= key && a1[right] >= key && a1[mid] != key)
    {
        mid = left + ((key - a1[left]) * (right - left)) / (a1[right] - a1[left]);
        if (a1[mid] < key)
            left = mid + 1;
        else
            if (a1[mid] > key)
                right = mid - 1;
    }
    if (a1[mid] == key)
        F << "Искомый элемент найден";
    else F << "Искомый элемент не найден";
}

void pryamoy()
{
    FILE* file = fopen("file.dat", "rb");
    Person p;
    int key, i = 1;
    bool f = false;
    cout << "Введите номер паспорта, который необходимо найти: ";
    cin >> key;
    while (fread(&p, sizeof(Person), 1, file))
    {
        if (p.pasport == key) {
            char fio[30] = "";
            strcat(fio, p.surname);
            strcat(fio, " ");
            strcat(fio, p.name);
            strcat(fio, " ");
            strcat(fio, p.middlename);

            cout << setw(25) << fio << setw(10) << p.pasport << setw(20) << p.address << endl;
            f = true;
        }
        if (f == false) i++;
    }
    if (f == true) {
        cout << "Находится на " << i << " месте." << endl;
    }
    else cout << "Такого номера нет" << endl;
    fclose(file);
}

void add_person(Person t, int pos)
{
    if (pos < 1)
        cout << "Некорректный номер" << endl;
    else
    {
        FILE* file = fopen("file.dat", "rb");
        FILE* tempfile = fopen("temp.dat", "wb");
        Person p;
        int index = 0;

        while (fread(&p, sizeof(Person), 1, file))
        {
            fwrite(&p, sizeof(Person), 1, tempfile);
            index++;

            if (index == pos)
                fwrite(&t, sizeof(Person), 1, tempfile);
        }

        fclose(file);
        fclose(tempfile);

        remove("file.dat");
        rename("temp.dat", "file.dat");

        if (index < pos)
            cout << "Некорректный номер" << endl;
    }
}

void work_file()
{
    int oper;
    do
    {
        cout << "1.Чтение файла" << endl;
        cout << "2.Линейный поиск по паспорту" << endl;
        cout << "3.Интерполяционный поиск по паспорту" << endl;
        cout << "4.Прямой поиск" << endl;
        cout << "5.Добавление в файл" << endl;
        cout << "0.Назад" << endl;

        cin >> oper;

        switch (oper)
        {
        case 1:
            read_file();
            break;
        case 2:
        {
            line_search();
            break;
        }
        case 3:
        {
            pryamoy();
                break;
        }
        case 4:
        {
            interpol();
            break;
        }
        case 5:
            int pos;
            do {
            cout << "После какого элемента добавить? ";
            cin >> pos;
            } while (pos < 0);
            Person p = create();
            add_person(p, pos);
            break;
        }
    } while (oper != 0);
}