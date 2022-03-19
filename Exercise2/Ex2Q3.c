#include <stdio.h>

int main(){
    char c;
    int i;
    float f;
    printf("Please Enter a Character:");
    scanf("%c", &c);
    printf("Please Enter an Integer Value:");
    scanf("%d", &i);
    printf("Please Enter Float Value:");
    scanf("%f", &f);
    printf("The variables you entered were:\n");
    printf("The Character Value that you Entered is : %c\n", c);
    printf("The Integer Value that you Entered is : %d\n", i);
    printf("The Float Value that you Entered is : %.3f\n", f);
}