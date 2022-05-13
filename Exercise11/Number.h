#include <iostream>
#ifndef NUMBER_H
#define NUMBER_H
class Number
{
private:
    int val;
public:
    Number():val(0){};
    Number(int n):val(n){};
    Number operator++(){
        this->val++;
        return *this;
    }
    Number operator++(int){
        Number temp = *this;
        this->val++;
        return temp;
    }
    Number operator--(){
        this->val--;
        return *this;
    }
    Number operator--(int){
        Number temp = *this;
        this->val--;
        return temp;
    }
    friend std::ostream& operator<<(std::ostream &os, const Number &n){
        os<<n.val;
        return os;
    }
};
#endif