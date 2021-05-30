#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int n,m,k,l;
    do {
    cout << "Введите количество элементов массива ";
    cin >> n;
    } while (n <= 0);
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100 + 1;
    cout << "array = ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
    do {
    cout << "Введите элемент, который нужно удалить ";
    cin >> m;
    } while ((m < 0) || (m > n));

    for (int i = m + 1; i < n; ++i) arr[i - 1] = arr[i];
    n--;
    cout << "array = ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
    do {
    cout << "Введите количество заполняемых элементов ";
    cin >> k;
    } while (k <= 0);
    do {
    cout << "С какого элемента нужно заполнить ";
    cin >> l;
    } while ((l < 0) || (l > n));
    // Создание временного массива для хранения новых елементов
    int* tmpAddArr = new int[k];
    // Ввод значений новых елементов
    cout << "Добавляемые элементы: ";
    for (int i = 0; i < k; i++) {
        tmpAddArr[i] = rand() % 100 + 1;
        cout << tmpAddArr[i] << "  ";
    }
    cout << endl;
    // Создание нового массива, который будет 
    // содержать елементы начального массива и 
    // новые елементы массива новых елементов
    int* newArr = new int[n + k];
    // Для прохода по массиву новых елементов
    int count = 0;
    for (int i = 0; i < n + k; i++) {
        // Вставляем элементы старого массива в новый
        if (i < l) {
            newArr[i] = arr[i];
        }
        // Вставляем новые элементы из массива новых элементов
        else if (i >= l && i < l + k) {
            newArr[i] = tmpAddArr[count];
            count++;
        }
        // Вставляем элементы старого массива в новый
        else {
            newArr[i] = arr[i - count];
        }
    }
    // Удаляем начальный массив
    delete[] arr;
    // Удаляем временный массив новых элементов
    delete[] tmpAddArr;
    cout << "array = ";
    for (int i = 0; i < n+k; i++)
        cout << newArr[i] << "  ";
    cout << endl;
    system("pause");
    return 0;
}
