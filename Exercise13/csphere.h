#ifndef CSPHERE_H
#define CSPHERE_H
#include "cstereoshape.h"
#include <cmath>

class CSphere: public CStereoShape
{
private:
    double radius;
public:
    CSphere(): CStereoShape(),radius(1){};
    CSphere(double r): CStereoShape(),radius(r){};
    double getArea(){
        return 4*M_PI*radius*radius;
    }
    double getVolume(){
        return 4/3*M_PI*radius*radius*radius;
    }
    void show(){
        Formatting f = setFormat();
        std::cout<<"radius: "<<radius
        <<"\tarea: "<<getArea()
        <<"\tvolume: "<<getVolume()
        <<std::endl;
        restore(f);
    }
};

#endif