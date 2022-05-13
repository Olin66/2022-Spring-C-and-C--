#include <iostream>
#include "stack.h"
using namespace std;

int main(){
    Stack st(3);
    cout<<st.push(3)<<endl;
    cout<<st.push(2)<<endl;
    cout<<st.push(5)<<endl;
    cout<<st.push(9)<<endl;
    Item i;
    cout<<st.pop(i)<<endl;
    cout<<i<<endl;
}