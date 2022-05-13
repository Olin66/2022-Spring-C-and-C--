#include <stdio.h>


int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("Result:\n");
    printf("x value y value Expressions   Result\n");
    printf("%d %-4s %d %-5s %-13s | x=%d\n", x, "|", y, "|", "x=y+3", y+3);
    printf("%d %-4s %d %-5s %-13s | x=%d\n", x, "|", y, "|", "x=y-2", y-2);
    printf("%d %-4s %d %-5s %-13s | x=%d\n", x, "|", y, "|", "x=y*5", y*5);
    printf("%d %-4s %d %-5s %-13s | x=%d\n", x, "|", y, "|", "x=x/y", x/y);
    printf("%d %-4s %d %-5s %-13s | x=%d\n", x, "|", y, "|", "x=x%y", x%y);
}