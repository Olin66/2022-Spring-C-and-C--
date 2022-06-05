#pragma once
#include <iostream>
#define MAXROWS 2 
#define MAXCOLS 3
using namespace std;

template<typename T>
class Matrix
{
public:
    int row, col;
    T arr[MAXROWS][MAXCOLS];
    Matrix(int r, int c): row(r), col(c) {};
    void display(){
        for (int i = 0;i < row;i++){
            for (int j = 0;j < col;j++)
                cout<<arr[i][j]<<"\t";
            cout<<endl;
        }
    }
};

