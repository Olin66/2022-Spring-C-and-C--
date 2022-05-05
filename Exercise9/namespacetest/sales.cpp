#include <iostream>
#include "sales.h"

void SALES::setSales(Sales& s, const double ar[], int n){
    std::cout<<"Non-interactive version of setSales() to provide values"<<std::endl;
    for (int i = 0; i < n; i++){
        double x = ar[i];
        double sum = 0;
        s.sales[i] = x;
        if (i == 0)
        {
            s.max = x;
            s.min = x;
            s.average = x;
        }
        sum += x;
        s.average = sum / (i+1);
        if (x > s.max)
            s.max = x;
        if (x < s.min)
            s.min = x;
    }
}

void SALES::setSales(Sales& s){
    std::cout<<"Interactive version of setSales() to provide values"<<std::endl;
    std::cout<<"Enter sales for 4 quarters: "<<std::endl;
    double sum = 0;
    for (int i = 0; i < 4; i++)
    {
        double x;
        std::cin>>x;
        s.sales[i] = x;
        if (i == 0)
        {
            s.max = x;
            s.min = x;
            s.average = x;
        }
        sum += x;
        s.average = sum / (i+1);
        if (x > s.max)
            s.max = x;
        if (x < s.min)
            s.min = x;
    }
}

void SALES::showSales(const Sales& s){
    std::cout<<"Sales: ";
    for (int i = 0; i < 4; i++)
    {
        if (s.sales[i] > 1e-200) std::cout<<s.sales[i]<<" ";
        else break;
    }
    std::cout<<std::endl;
    std::cout<<"Average:"<<s.average<<std::endl;
    std::cout<<"Max:"<<s.max<<std::endl;
    std::cout<<"Min:"<<s.min<<std::endl;
}