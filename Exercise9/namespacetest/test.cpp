#include <iostream>
#include "sales.h"

using namespace SALES;

int main(){
    Sales s1;
    double ar[] = {345.2, 621.8, 1073.5};
    setSales(s1, ar, 3);
    showSales(s1);
    Sales s2;
    setSales(s2);
    showSales(s2);
}