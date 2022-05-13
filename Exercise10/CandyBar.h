#include "string.h"

#ifndef CANDYBAR_H
#define CANDYBAR_H
class CandyBar
{
private:
    static const int SIZE = 10;
    char name[SIZE];
    double weight;
    int calorie;
public:
    CandyBar();
    CandyBar(const char* n, double w, int c);
    ~CandyBar();
    void setName(const char* n);
    void setWeight(double w);
    void setCalorie(int c);
    char* getName();
    double getWeight();
    int getCalorie();
};

void setCandyBar(CandyBar& cb);
void showCandyBar(const CandyBar cb);
#endif