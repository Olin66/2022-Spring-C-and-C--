#ifndef CSTEREOSHAPE_H
#define CSTEREOSHAPE_H
#include <iostream>

struct Formatting
{
    std::ios_base::fmtflags flag;
    std::streamsize pr;
};

class CStereoShape
{

private:
    static int numberOfObject;

public:
    CStereoShape(){numberOfObject++;};

    virtual ~CStereoShape(){};

    virtual double getArea(){
        return 0.0;
    }

    virtual double getVolume(){
        return 0.0;
    }

    virtual void show(){
        std::cout<<"Show of CStereoShape is invoked"<<std::endl;
    }

    Formatting setFormat() const{
        Formatting f;
        f.flag = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        f.pr = std::cout.precision(2);
        return f;
    }

    void restore(Formatting &f) const{
        std::cout.setf(f.flag, std::ios_base::floatfield);
        std::cout.precision(3);
    }

    int getNumberOfObject(){
        return numberOfObject;
    }
};

int CStereoShape::numberOfObject = 0;

#endif