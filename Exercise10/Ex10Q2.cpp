#include <cstdio>
#include "Rectangle.h"

void display(Rectangle r){
    printf("%-12s %g\n", "Width:", r.getWidth());
    printf("%-12s %g\n", "Height:", r.getHeight());
    printf("%-12s %g\n", "Area:", r.getArea());
    printf("%-12s %g\n", "Perimeter:", r.getPerimeter());
}

int main(){
    Rectangle r1(4, 40);
    Rectangle r2(3.5, 35.9);
    printf("Rectangle 1\n");
    printf("-------------\n");
    display(r1);
    printf("Rectangle 2\n");
    printf("-------------\n");
    display(r2);
}