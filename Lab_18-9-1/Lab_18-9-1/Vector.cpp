#include "Vector.h"
Vector::Vector(int s)
{
	//если текущий размер больше максимального, то генерируется исключение 
	if (s > MAX_SIZE) throw error("Ошибка! Текущий размер больше максимального!\n");
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}
Vector::Vector(const Vector& v)
{
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
}
Vector::~Vector()
{
	if (beg != 0) delete[]beg;
}
Vector::Vector(int s, int* mas)
{
	//если текущий размер больше максимального, то генерируется исключение 
	if (s > MAX_SIZE) throw error("Ошибка! Текущий размер больше максимального!\n");
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++) beg[i] = mas[i];
}
const Vector& Vector::operator =(const Vector& v)
{
	if (this == &v)return *this;
	if (beg != 0) delete[]beg;
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
	return*this;
}
ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty\n";
	else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}
istream& operator >>(istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}
int Vector::operator [](int i)
{
	if (i < 0)throw error("Ошибка! Индекс отрицательный!\n");//если индекс отрицательный, то генерируется исключение
	//если индекс больше размера вектора, то генерируется исключение
	if (i >= size) throw error("Ошибка! Индекс больше размера вектора!\n");
	return beg[i];
}

Vector& Vector::operator --()
{
	//если вектор пустой, то удалить элемент нельзи и генерируется исключение 
	if (size == 0) throw error("Ошибка! Вектор пустой!\n");
	if (size == 1)//если в вектор один элемент 
	{
		size = 0;
		delete[]beg;
		beg = 0;
		return *this;
	};
	Vector temp(size, beg);
	delete[]beg;
	size--;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = temp.beg[i + 1];
	return*this;
}

Vector Vector::operator--(int)
{
	if (size == 0) throw error("Ошибка! Вектор пустой!\n");
	if (size == 1)//если в вектор один элемент 
	{
		size = 0;
		delete[]beg;
		beg = 0;
		return *this;
	};
	size--;
	return*this;
}