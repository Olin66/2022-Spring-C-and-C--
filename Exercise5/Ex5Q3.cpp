#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int vn = 5;
const char vowel[vn] = {'a', 'e', 'i', 'o', 'u'};

int main(){
    cout<<"Enter word (q to quit): "<<endl;
    int nVowel = 0;
    int nConsonat = 0;
    int nOther = 0;
    char word[30];

    while (cin>>word)
    {
        if (isalpha(word[0]))
        {
            if (strlen(word) == 1 && word[0] == 'q')
            {
                break;
            }
            char x = tolower(word[0]);
            bool flag = true;
            for (int i = 0; i < vn; i++)
            {
                if (x == vowel[i])
                {
                    nVowel++;
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                nConsonat++;
            }
        }
        else
        {
            nOther++;
        }
    }
    cout<<nVowel<<" words beginning with vowels"<<endl
    <<nConsonat<<" words begining with consonats"<<endl
    <<nOther<<" others"<<endl;
    
    return 0;
    
}