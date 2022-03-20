#include <iostream>
using namespace std;

int main(){
    int* arr = new int[5];
    cout<<"Enter 5 integers: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i]; 
    }
    for (int i = 4; i >= 0; i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
    
}