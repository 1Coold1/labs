#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

struct Person {
    string name;
    string surname;
    string midlename;
    string adress;
    string passport;
};

int BMura(string st, string ct)
{
    int stl, ctl;
    stl = st.size();    
    ctl = ct.size();    
    if (stl != 0 && ctl != 0 && stl >= ctl)   
    {
        int i, p;
        int b[256];     
        for (i = 0; i < 256; i++)
        {
            b[i] = ctl;    
        }
        for (i = ctl - 2; i >= 0; i--) 
        {
            if (b[int(unsigned char(ct[i]))] == ctl) 
            {
                b[int(unsigned char(ct[i]))] = ctl - i - 1;
            }
        }
        p = ctl - 1;
        while (p < stl)
        {
            if (ct[ctl - 1] != st[p])
            {
                p += b[int((unsigned char)st[p])];
            }
            else   
            {
                for (i = ctl - 1; i >= 0; i--) 
                {
                    if (ct[i] != st[p - ctl + i + 1])   
                    {
                        p += b[int((unsigned char)st[p])];   
                        break;
                    }
                    else if (i == 0)
                    {
                        return p - ctl + 1; 
                    }
                }
            }
        }
    }
    return -1;
}

void set_studentsrandom(Person chel[], int start, int scale) {
    int j, k;
    for (int i = start; i < scale; i++) {
        k = 0;
        ifstream name1("C:\\Users\\super\\Desktop\\name.txt");
        ifstream surname1("C:\\Users\\super\\Desktop\\surname.txt");
        ifstream midlename1("C:\\Users\\super\\Desktop\\midlename.txt");
        string group, temp, surname, surnameme, temp1, temp2;
        int count = -1;
        int rnd = rand() % 99;
        while (count != rnd)
        {
            getline(name1, temp);
            getline(surname1, temp1);
            getline(midlename1, temp2);
            count++;
        }
        chel[i].name = temp;
        chel[i].surname = temp1;
        chel[i].midlename = temp2;
        name1.close();
        surname1.close();
        midlename1.close();

        ifstream adress("C:\\Users\\super\\Desktop\\adress.txt");
        rnd = rand() % 11;
        count = -1;
        while (count != rnd)
        {
            getline(adress, temp);
            count++;
        }
        chel[i].adress = temp;
        adress.close();
        ifstream passport("C:\\Users\\super\\Desktop\\passport.txt");
        rnd = rand() % 100;
        count = -1;
        while (count != rnd)
        {
            getline(passport, temp);
            count++;
        }
        chel[i].passport = temp;
        passport.close();
    }
}


void show_students(Person chel[], int start, int scale) {
    for (int i = start; i < scale; i++) {
        cout << "\nФИО: " << chel[i].surname << " " << chel[i].name << " " << chel[i].midlename;
        cout << "\nАдрес: " << chel[i].adress;
        cout << "\nПаспорт: " << chel[i].passport << "\n";
    }
}

void KMP_Search(Person* chel, string x, string row, int size)
{
    int* arr_pos = new int[size];
    string pst=x;
    int pos=0;
    int dl_st = row.length();
    int dl_pst = pst.length();
    int* array = new int[dl_pst];
    array[0] = 0;
    int i = 1;
    int j = 0;
    for (int v = 0; v < dl_pst; v++)
    {
        if (pst[i] == pst[j]) { array[i] = j + 1; i++; j++; }
        else if (j == 0)
        {
            array[i] = 0; i++;
        }
        else { j = array[j - 1]; }
    }
    int index_str = 0;
    int index_pod = 0;
    int slovo = 0;
    int o = 0;
    while (index_str < dl_st)
    {
        if (row[index_str] == pst[index_pod])
        {
            index_str++;
            index_pod++;
            if (index_pod == dl_pst) 
            {
                arr_pos[o] = slovo;
                o++;
            }
        }

        if (row[index_str] != pst[index_pod])
        {
            if (index_pod == 0) { index_str++; }
            else { index_pod = array[index_pod - 1]; }
        }
        if (row[index_str] == ' ') slovo++;
    }
    cout << endl << "Совпадений: " << o << endl;
    for (i = 0; i < o; i++)
    {
        cout << "\nФИО: " << chel[arr_pos[i]].surname << " " << chel[arr_pos[i]].name << " " << chel[arr_pos[i]].midlename;
        cout << "\nАдрес: " << chel[arr_pos[i]].adress;
        cout << "\nПаспорт: " << chel[arr_pos[i]].passport << "\n";
    }
}



int main()
{
    system("chcp 1251>nul");
    srand(time(NULL));
    int size;
    string passport;
    int i;
    do {
        cout << "Введите количество людей:";
        cin >> size;
    } while (size <= 0);
    cout << endl;
    string row;
    Person* chel = new Person[size];
    set_studentsrandom(chel, 0, size);
    for (i = 0; i < size; i++)
    {
        row += chel[i].passport + " ";
    }
    show_students(chel, 0, size);
    cout << endl;
    cout << "Поиск Кнутта-Морриса-Пратта " << endl;
    cout << "\nПаспорт для поиска: ";
    cin >> passport;
    KMP_Search(chel, passport, row, size);
    cout << endl;
    cout << "Поиск Бойра-Мюра " << endl;
    cout << "\nПаспорт для поиска: ";
    cin >> passport;
    int pos;
    int k = 0;
    string row_dop;
    while (BMura(row, passport) != -1)
    {
        pos = BMura(row, passport);
        for (i = 0; i < pos; i++)
        {
            if (row[i] == ' ') k++;
        }
        cout << "\nФИО: " << chel[k].surname << " " << chel[k].name << " " << chel[k].midlename;
        cout << "\nАдрес: " << chel[k].adress;
        cout << "\nПаспорт: " << chel[k].passport << "\n";
        for (i = 0; i < pos; i++)
        {
             row[i]=0;
        }
        while (row[i] != ' ')
        {
            pos++;
            row[i] = 0;
            i++;
        }
    }
    delete[] chel;

    return 0;
    system("pause");
};