#include <cstring>
#include <iostream>
#ifndef STOCK_H
#define STOCK_H

class Stock
{
private:
    char* name;
public:
    Stock(const char* str);
    ~Stock();
    friend std::ostream& operator<<(std::ostream &os, const Stock &s);
};

Stock::Stock(const char* str)
{
    if (str)
    {
        name = new char[strlen(str)+1];
        strcpy(name, str);
    }else
    {
        name = new char[1];
        *name = '\0';
    }
}

Stock::~Stock()
{
    delete[] name;
}

std::ostream& operator<<(std::ostream &os, const Stock &s){
    os<<s.name;
    return os;
}

#endif