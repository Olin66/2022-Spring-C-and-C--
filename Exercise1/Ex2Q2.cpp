#include <stdio.h>

void print_smile(int times){
    for (int i = 0; i < times; i++)
    {
        printf("%s", "Smile!");
    }
    printf("\n");
    
}

int main(){
    for (int i = 3; i > 0; i--)
    {
        print_smile(i);
    }
    return 0;
    
}
