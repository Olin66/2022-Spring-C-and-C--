#include <iostream>
#include <cstring>
using namespace std;

struct stringy
{
    char *str;
    int ct;
};

void set(stringy&, char*);
void show(const char[]);
void show(const char[], int);
void show(stringy);
void show(stringy, int);

void set(stringy& beany, char* testing){
    beany.str = testing;
    beany.ct = strlen(testing);
}

void show(const char testing[]){
    cout<<testing<<endl;
}

void show(const char testing[], int times){
    for (int i = 0; i < times; i++)
    {
        show(testing);
    }

}

void show(const stringy beany){
    for (int i = 0; i < beany.ct; i++)
    {
        cout<<beany.str[i];
    }
    cout<<endl;

}

void show(const stringy beany, int times){
    for (int i = 0; i < times; i++)
    {
        show(beany);
    }
}

int main(){
    stringy beany{};
    char testing[] = "Reality isn't what it used to be";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
}
