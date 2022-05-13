#include <iostream>
using namespace std;

int main(){
    int n;
    int sum = 0;
    do{
        cout<<"Enter an integer: ";
        cin>>n;
        sum += n;
        cout<<"The cumulative sum of the entries to date is: "<<sum<<endl;
    }while(n != 0);
}