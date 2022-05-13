#include <iostream>

using namespace std;

struct CandyBar {
    char *name;
    float weight;
    int calorie;

    // CandyBar(char[] name, float weight, int calorie){
    //     name = name;
    //     weight = weight;
    //     calorie = calorie;
    // }
};


int main() {
    char name[20];
    float weight;
    int calorie;

    cout << "Enter brand name of a Candy Bar:";
    cin.get(name, 20);
    cin.get();
    cout << "Enter weight of the Candy Bar:";
    cin >> weight;
    cout << "Enter calories (an integer value) in the Candy Bar:";
    cin >> calorie;

    CandyBar cb = {name, weight, calorie};
    cout << "Brand: " << cb.name << endl;
    cout << "Wight: " << cb.weight << endl;
    cout << "Calories: " << cb.calorie << endl;
}