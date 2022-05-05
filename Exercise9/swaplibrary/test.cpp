#include <iostream>
#include "functions.h"
using namespace std;

int main(){
    int a = 3, b = 4;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    swap(&a, &b);
    cout<<"After swap by pointer: ";
    cout<<"a = "<<a<<", b = "<<b<<endl;
    a = 5, b = 6;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    swap(a, b);
    cout<<"After swap by reference: ";
    cout<<"a = "<<a<<", b = "<<b<<endl;
}