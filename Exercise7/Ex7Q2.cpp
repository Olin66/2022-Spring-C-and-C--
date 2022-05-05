#include <iostream>
using namespace std;

template <typename T>
T max5(T arr[], int len){
    T max = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main(){
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.1, 2.0, 3.0, 4.0, 5.5};
    cout<<"Max int  = "<<max5(intArr, 5)<<endl;
    cout<<"Max double = "<<max5(doubleArr, 5)<<endl;
}