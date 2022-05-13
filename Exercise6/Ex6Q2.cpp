#include <iostream>
using namespace std;

struct Box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void display(Box box);

void modify(Box *box);

int main(){
    Box box = {"Jack Smith", 3.4, 4.5, 5.6, 0};
    cout<<"Before setting volume:"<<endl;
    display(box);
    modify(&box);
    cout<<"After setting volume:"<<endl;
    display(box);
}

void display(Box box){
    cout<<"Marker: "<<box.maker<<endl;
    cout<<"Height: "<<box.height<<endl;
    cout<<"Width: "<<box.width<<endl;
    cout<<"Length: "<<box.length<<endl;
    cout<<"Volume: "<<box.volume<<endl;
}

void modify(Box *box){
    box->volume = box->height * box->length * box->width;
}