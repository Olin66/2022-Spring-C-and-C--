#include <stdio.h>
#include <cstring>



int main(){
    char * first = new char[20]();
    char * last = new char[20]();
    char letter;
    int age;
    printf("What is your first name?");
    fgets(first, 20, stdin);
    char* find;
    find = strchr(first, '\n');
    if(find)    
        *find = '\0';  
    printf("What is your last name?");
    fgets(last, 20, stdin);

    // for (int i = 0; i < 20; i++)
    // {
    //     printf("%c (%d)\n", first[i], +first[i]);
    // }
    
    printf("What letter grade do you deserve?");
    scanf("%c", &letter);
    printf("What is your age?");
    scanf("%d", &age);
    printf("The information you entered is:\n");
    printf("Name: %s, %s", first, last);
    printf("Grade: %c\n", letter);
    printf("Age: %d\n", age);
}