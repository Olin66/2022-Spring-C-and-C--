#include <cstdio>
#include <cstring>
#include "candybar.h"

void setCandyBar(CandyBar &cb){
    printf("Call the set function of passing by reference\n");
    char* n = new char[20];
    double w;
    int c;
    printf("Enter the brand name of candy bar: ");
    fgets(n, 20, stdin);
    char* find = strchr(n, '\n');
    if(find) *find = '\0';
    printf("Enter the weight: ");
    scanf("%lf", &w);
    printf("Enter the calories: ");
    scanf("%d", &c);
    getchar();
    strcpy(cb.brand, n);
    cb.weight = w;
    cb.calorie = c;
}

void setCandyBar(CandyBar *cb){
    printf("Call the set function of passing by pointer\n");
    char* n = new char[20];
    double w;
    int c;
    printf("Enter the brand name of candy bar: ");
    fgets(n, 20, stdin);
    char* find = strchr(n, '\n');
    if(find) *find = '\0';
    printf("Enter the weight: ");
    scanf("%lf", &w);
    printf("Enter the calories: ");
    scanf("%d", &c);
    getchar();
    strcpy(cb->brand, n);
    cb->weight = w;
    cb->calorie = c;
}
void showCandyBar(const CandyBar &cb){
    printf("Call the show function of passing by reference\n");
    printf("Brand name: %s\n", cb.brand);
    printf("Weight: %.1lf\n", cb.weight);
    printf("Calories: %d\n", cb.calorie);
}
void showCandyBar(const CandyBar *cb){
    printf("Call show set function of passing by pointer\n");
    printf("Brand name: %s\n", cb->brand);
    printf("Weight: %.1lf\n", cb->weight);
    printf("Calories: %d\n", cb->calorie); 
}