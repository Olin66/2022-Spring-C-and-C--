#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class OutOfRangeException: public exception
{
private:
    int cnt;
    int val;
public:
    OutOfRangeException(int c, int v): cnt(c), val(v) {};

    virtual const char* what(){
        auto* s = new string ("The parameter " + to_string(cnt) + " is " + to_string(val) + " which out of range (0-100)");
        return s->c_str();
    }
};

double getAvg(double d1, double d2, double d3, double d4){
    double sum = 0;
    if (d1 >= 0 && d1 <= 100)sum += d1;
    else throw OutOfRangeException(1, d1);
    if (d2 >= 0 && d2 <= 100)sum += d2;
    else throw OutOfRangeException(2, d2);
    if (d3 >= 0 && d3 <= 100)sum += d3;
    else throw OutOfRangeException(3, d3);
    if (d4 >= 0 && d4 <= 100)sum += d4;
    else throw OutOfRangeException(4, d4);
    return sum/4;
}

int main(){
    char c = 'y';
    do
    {
        try{
            cout<<"Please enter marks for 4 courses: "<<endl;
            double num1, num2, num3, num4;
            cin>>num1>>num2>>num3>>num4;
            double avg = getAvg(num1, num2, num3, num4);
            cout<<"The average of the four courses is "<<avg<<endl;
        }catch(OutOfRangeException& e){
            cout<<e.what()<<endl;
        }
        cout<<"Would you want to enter another marks for 4 courses(y/n)?";
        cin>>c;
    } while (c != 'n' && c != 'N');
    cout<<"Bye, see you next time."<<endl;

}