#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int arr_size, collisions, M;

template <typename T>
void get_value(T& value)
{
    bool is_correct = false;
    do
    {
        cout << "Введите " << "элемент\n";
        cin >> value;
        if (cin.fail())
        {
            cout << "\nНекорректное значение" << endl << endl;
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
        {
            is_correct = true;
            cin.ignore(32767, '\n');
        }
    } while (!is_correct);
}

struct Data
{
    string fio = "";
    string date = "";
    long long int phn = 0;
    string pasp = "";
};

int Hash(string date)
{
    return (stoi(date.substr(0, 2)) + stoi(date.substr(3, 5)) + stoi(date.substr(6, 10))) % M;
}

void change_size(Data *&arr)
{
    Data* new_arr = new Data[arr_size + (arr_size / 2)];
    for (int i = 0; i < arr_size; i++)
    {
        new_arr[i] = arr[i];
    }
    arr_size += arr_size / 2;
    delete[] arr;
    arr = new_arr;
    
}

void add_elem(Data *&arr, Data elem)
{
    int hash_val = Hash(elem.date);
    if (arr[hash_val].fio.length() == 0)
    {
        arr[hash_val] = elem;
    }
    else
    {
        bool f = false;
        int last = arr_size;
        collisions++;
        for (int i = hash_val + 1; i < arr_size; i++)
        {
            if (arr[i].fio.length() == 0)
            {
                f = true;
                arr[i] = elem;
                i = arr_size;
            }
        }
        if (!f)
        {
            change_size(arr);
            arr[last] = elem;

        }
    }

}

void read_file(Data *&arr)
{
    ifstream file("F1.txt");
    if (file.is_open())
    {
        string currentLine;
        Data new_elem;
        while (!file.eof())
        {
            getline(file, currentLine);
            new_elem.fio = currentLine;

            getline(file, currentLine);
            new_elem.date = currentLine;

            getline(file, currentLine);
            new_elem.phn = stoull(currentLine);

            getline(file, currentLine);
            new_elem.pasp = currentLine;

            getline(file, currentLine);
            add_elem(arr, new_elem);
        }
        file.close();
    }
    else cout << "File not found\n";

    
}

void print_hash_table(Data arr[])
{
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i].fio.length() != 0) {
            cout << "\nНомер элемента " << i << endl;
            cout << "ФИО: " << arr[i].fio << endl;
            cout << "Дата: " << arr[i].date << endl;
            cout << "Номер телефона: " << arr[i].phn << endl;
            cout << "Паспорта: " << arr[i].pasp << endl;
            cout << "Значение хэша: " << Hash(arr[i].date) << endl << endl;
        }
        else
        {
            cout << "Элемент № " << i << " пуст" << endl;
        }
        
    }
}

bool is_date(string date)
{
    if (date.length() == 10)
    {
        return true;
    }
    else return false;
}

void find(Data arr[], string key) 
{
    if (is_date(key))
    {
        int hash_val = Hash(key);
        if (arr[hash_val].pasp == key)
        {
            cout << "Объект найден" << endl;
            cout << "ФИО: " << arr[hash_val].fio << endl;
            cout << "Дата: " << arr[hash_val].date << endl;
            cout << "Номер телефона: " << arr[hash_val].phn << endl;
            cout << "Паспорта: " << arr[hash_val].pasp << endl;
            cout << "Значение хэша: " << hash_val << endl << endl;
        }
        else
        {
            bool f = false;
            for (int i = hash_val + 1; i < arr_size; i++)
            {
                if (arr[i].pasp == key)
                {
                    f = true;
                    cout << "Объект найден" << endl;
                    cout << "ФИО: " << arr[hash_val].fio << endl;
                    cout << "Дата: " << arr[hash_val].date << endl;
                    cout << "Номер телефона: " << arr[hash_val].phn << endl;
                    cout << "Паспорта: " << arr[hash_val].pasp << endl;
                    cout << "Значение хэша: " << hash_val << endl << endl;
                }
            }
            if (!f)
            {
                cout << "Объект не найден\n";
            }
        }
    }
    else cout << "Некорректное значение\n";

    
}
int main()
{
    system("chcp 1251>null");
    do
    {
        get_value(arr_size);
    } while (arr_size < 2 || arr_size > 100);

    M = arr_size;
    
    Data* data_base = new Data[arr_size];
    
    read_file(data_base);
    print_hash_table(data_base);
    cout << "Колличество коллизий: " << collisions << endl;
    
    string key;
    while (key != "0")
    {
        cout << "\nВведите искомый номер поспорта: ";
        getline(cin, key);
        if (key != "0") find(data_base, key);
    }
    

}
