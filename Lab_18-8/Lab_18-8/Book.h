#pragma once
#include "Print.h"
class Book :
    public Print
{
public:
    Book(void);
    ~Book(void); 
    void Show(); 
    void Input(); 
    Book(string, string, int, string); 
    Book(const Book&); 
    int Get_page() { return page; } 
    void Set_page(int);
    string Get_izdat() { return izdat; }
    void Set_izdat(string);
    Book& operator=(const Book&);
protected:
    int page;
    string izdat;
};

