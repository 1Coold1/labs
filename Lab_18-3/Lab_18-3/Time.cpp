#include "Time.h" 
#include <iostream> 
using namespace std;
//перегрузка операции присваивани€ 
Time&Time::operator=(const Time&t) {
//проверка на самоприсваивание 
if(&t==this) return *this; 
min=t.min; 
sec=t.sec; 
return *this;
}
//перегрузка префиксной операции инкремент 
Time&Time::operator++() {
int temp = min * 60 + sec; 
temp++;
min = temp / 60; 
sec = temp % 60; 
return *this;
}
//перегрузка постфиксной операции инкремент 
Time Time::operator ++(int) {
int temp = min * 60 + sec; 
temp++;
Time t(min, sec); 
min = temp / 60; 
sec = temp % 60; 
return t;
}
//перегрузка глобальной функции-операции ввода 
istream&operator>>(istream&in, Time&t) {
cout << "¬ведите минуты - "; 
in >> t.min; 
do {
    cout << "¬ведите секунды - ";
    in >> t.sec;
} while ((t.sec < 0) || (t.sec >= 60));
return in;
}
//перегрузка глобальной функции-операции вывода 
ostream&operator<<(ostream&out, const Time&t) {
return (out << t.min << ":" << t.sec);
}
//перегрузка функции сравнени€
bool operator==(const Time& t1, const Time& t2) {
    if (t1.min == t2.min && t1.sec == t2.sec)
        return true;
    else return false;
}
//перегрузка функции неравенства
bool operator!=(const Time& t1, const Time& t2) {
    if (t1.min != t2.min && t1.sec != t2.sec)
        return true;
    else return false;
}