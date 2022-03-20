#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int count = 0;
    bool flag = true;
    cout<<"Enter words (to stop, type the word done):\n";
    do{
        getline(cin, s);
        int len = s.length();
        for (int i = 0, k = 0; i < len; i++){
            if (s[i] == ' ' || i == len-1){
                string sub = s.substr(k, i-k);
                if (s.substr(k, i-k) == "done"){
                    flag = false;
                    break;
                }
                count++;
                k = i+1;
            }
        }
    }while(flag);
    cout<<"You entered a total of "<<count<<" words."<<endl;
}