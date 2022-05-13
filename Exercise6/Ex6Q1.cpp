#include <iostream>
using namespace std;

void display_menu();

int add(int, int);

int subtract(int, int);

int multiply(int, int);

int divide(int, int);

int modulo(int, int);

int main(){
    display_menu();
    int choice;
    int a, b;
    char confirm;
    do{
        cout<<"Enter your choice(1~5):";
        cin>>choice;
        cout<<"Enter your integer number:";
        cin>>a>>b;
        cout<<"\n";
        int result = 0;
        switch (choice)
        {
        case 1:
            result = add(a, b);
            break;
        case 2:
            result = subtract(a, b);
            break;
        case 3:
            result = multiply(a, b);
            break;
        case 4:
            result = divide(a, b);
            break;
        case 5:
            result = modulo(a, b);
            break;
        default:
            result = INT32_MAX;
            break;
        }
        if (result != INT32_MAX)
        {
            cout<<result<<endl;
            cout<<"Press y or Y to continue:"<<endl;
            cin>>confirm;
        }
    }while(confirm == 'y' || confirm == 'Y');
}

int add(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

int multiply(int a, int b){
    return a * b;
}

int divide(int a, int b){
    return a / b;
}

int modulo(int a, int b){
    return a % b;
}

void display_menu(){
    cout<<"=================="<<endl;
    cout<<"        Menu      "<<endl;
    cout<<"=================="<<endl;
    cout<<"     1.Add"<<endl;
    cout<<"     2.Subtract"<<endl;
    cout<<"     3.Multiply"<<endl;
    cout<<"     4.Divide"<<endl;
    cout<<"     5.Modulus"<<endl;
}