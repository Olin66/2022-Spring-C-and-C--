#include <iostream>
#include <cstring>
using namespace std;

int fill_array(double[], int);

void show_array(double*, int);

void reverse_array(double*, int);

int main(){
    int size;
    cout<<"Enter the size of an array:";
    cin>>size;
    double* arr = new double[size];
    int arr_size = fill_array(arr, size);
    show_array(arr, arr_size);
    reverse_array(arr, arr_size);
    show_array(arr, arr_size);
    reverse_array((arr+1), arr_size-2);
    show_array(arr, arr_size);
}

int fill_array(double arr[], int size){
    for (int i = 1; i <= size; i++)
    {
        cout<<"Enter value #"<<i<<":";
        char* in;
        cin >> in;
        if (strspn(in, "0123456789.")==strlen(in))
        {
            arr[i-1] = atof(in);
        }
        else return i-1;
    }
    return size;
}

void show_array(double* arr, int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void reverse_array(double* arr, int size){
    if(size > 1)
    {
        reverse_array(arr+1, size-2);	
        auto temp = arr[0];
        arr[0] = arr[size-1];		
        arr[size-1] = temp;
    }
}