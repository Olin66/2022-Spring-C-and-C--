#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

int main(){
    string input;
    string content1 = "";
    string content2 = "";
    cout<<"Please input a string: "<<endl;
    getline(cin, input);

    ofstream outfile1;
    outfile1.open("f1.txt");
    ofstream outfile2;
    outfile2.open("f2.txt");


    for (int i = 0; i < input.length(); i++)
    {
        if (isalpha(input[i]) || isspace(input[i]))
        {
            content1 = content1 + input[i];
            content2 = content2 + (char) toupper(input[i]);
        }
    }
    

    if (outfile1.is_open() && outfile2.is_open())
    {
        outfile1 << content1;
        outfile2 << content2;
        outfile1.close();
        outfile2.close();
    }
    else cout<< "Can not open the file.\n";
    
    string contents;
    ifstream infile1;
    infile1.open("f1.txt");
    ifstream infile2;
    infile2.open("f2.txt");

    if (infile1.is_open())
    {
        while (!infile1.eof())
        {
            getline(infile1, contents);
            cout<<contents<<endl;
        }
        infile1.close();
    }
    
    if (infile2.is_open())
    {
        while (!infile2.eof())
        {
            getline(infile2, contents);
            cout<<contents<<endl;
        }
        infile2.close();
    }

}