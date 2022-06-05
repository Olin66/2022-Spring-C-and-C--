#include <iostream>
#include <string>
using namespace std;

template<typename T>
const T& Max(T &one, T &two);

int main(){
    int i1 = 3, i2 = 5;
    double d1 = 3.5, d2 = 10.3;
    string s1 = "Hello", s2 = "World";

    cout<<Max(i1, i2)<<endl;
    cout<<Max(d1, d2)<<endl;
    cout<<Max(s1, s2)<<endl;
}

template<typename T>
const T& Max(T &one, T &two){
    return one>two?one:two;
}