#include <iostream>
#include "cstereoshape.h"
#include "ccube.h"
#include "csphere.h"

using namespace std;

int main(){
    CCube a_cube(4.0,5.0,6.0);
    CSphere c_sphere(7.9);
    CStereoShape* p;
    p = &a_cube;
    p->show();
    p = &c_sphere;
    p->show();
    cout<<p->getNumberOfObject()<<endl;
}