#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

template<typename T>
void useMatrixTemplate(Matrix<T> &m, T arr1[][MAXCOLS], T arr2[][MAXCOLS]);

int main(){
    string str1[MAXROWS][MAXCOLS] = {{"congra","y","ar"},{"alm","don","la"}};
    string str2[MAXROWS][MAXCOLS] = {{"tulations","ou","e"},{"ost","e the","b!"}};

    int num1[MAXROWS][MAXCOLS] = {{1,2,3},{4,5,6}};
    int num2[MAXROWS][MAXCOLS] = {{6,5,4},{3,2,1}};

    Matrix<string> stringMatrix(2,3);
    Matrix<int> intMatrix(2,3);

    cout<<"Demonstrating with string matrix: "<<endl;
    useMatrixTemplate(stringMatrix, str1, str2);

    cout<<"\nDemonstraing with int matrix"<<endl;
    useMatrixTemplate(intMatrix, num1, num2);
}

template<typename T>
void useMatrixTemplate(Matrix<T> &m, T arr1[][MAXCOLS], T arr2[][MAXCOLS]){
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            m.arr[i][j] = arr1[i][j];
        }
    }
    cout<<"\nMatrix set first array"<<endl;
    m.display();

    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            m.arr[i][j] = m.arr[i][j] + arr2[i][j];
        }
    }
    cout<<"\nMatrix incremented by second array"<<endl;
    m.display();
}
