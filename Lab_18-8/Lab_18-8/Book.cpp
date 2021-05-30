#include "Book.h"
Book::Book(void) :Print() 
{
	page = 0;
	izdat = "";
}
Book::~Book(void) {}
Book::Book(string N,string A, int P, string I ) : Print(N, A) 
{
	page = P;
	izdat = I;
}
Book::Book(const Book& B) 
{
	name = B.name; 
	author = B.author; 
	page = B.page; 
	izdat = B.izdat;
}
void Book::Set_page(int P) 
{
	page = P;
}
void Book::Set_izdat(string I)
{
	izdat = I;
}
Book& Book::operator=(const Book& b) 
{
	if (&b == this) return *this; 
	name = b.name; 
	author = b.author; 
	page = b.page; 
	izdat = b.page;
	return *this;
} 
void Book::Show() 
{
	cout << "\n�������� : " << name;
	cout << "\n����� : " << author;
	cout << "\n���������� ������� : " << page;
	cout << "\n������������ : " << izdat;
	cout << "\n";
}
void Book::Input() {
	cout << "\n��������:"; 
	cin >> name; 
	cout << "\n�����:"; 
	cin >> author; 
	cout << "\n���������� �������:"; 
	cin >> page; 
	cout << "\n������������: "; 
	cin >> izdat;
}