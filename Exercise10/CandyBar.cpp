#include <cstdio>
#include "CandyBar.h"

CandyBar::CandyBar(){

}

CandyBar::CandyBar(const char*n, double w, int c)
{
    strcpy(name, n);
    weight = w;
    calorie = c;
}

void CandyBar::setName(const char* n){
    strcpy(this->name, n);
}

void CandyBar::setWeight(double w){
    this->weight = w;
}

void CandyBar::setCalorie(int c){
    this->calorie = c;
}

char* CandyBar::getName(){
    return this->name;
}

double CandyBar::getWeight(){
    return this->weight;
}

int CandyBar::getCalorie(){
    return this->calorie;
}

CandyBar::~CandyBar(){
    
}

void setCandyBar(CandyBar& cb){
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
    cb.setName(n);
    cb.setWeight(w);
    cb.setCalorie(c);
}

void showCandyBar(CandyBar cb){
    printf("Brand name: %s\n", cb.getName());
    printf("Weight: %.1lf\n", cb.getWeight());
    printf("Calories: %d\n", cb.getCalorie());
}