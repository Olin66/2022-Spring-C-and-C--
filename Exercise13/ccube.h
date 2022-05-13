#ifndef CCUBE_H
#define CCUBE_H
#include "cstereoshape.h"

class CCube: public CStereoShape
{
private:
    double length;
    double width;
    double height;
public:
    CCube():CStereoShape(),length(1),width(1),height(1){};
    CCube(double l, double w, double h): CStereoShape(), length(l), width(w), height(h){};
    double getArea(){
        return (length*height+length*width+height*width)*2;
    }
    double getVolume(){
        return length*width*height;
    }
    void show(){
        Formatting f = setFormat();
        std::cout<<"length: "<<length<<"\twidth: "<<width
        <<"\theight: "<<height<<"\tarea: "<<getArea()
        <<"\tvolume: "<<getVolume()<<std::endl;
        restore(f);
    }
};

#endif