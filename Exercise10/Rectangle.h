#ifndef RETANGLE_H
#define RETANGLE_H
class Rectangle
{
private:
    double width;
    double height;
public:
    Rectangle():width(1),height(1){};
    Rectangle(double w, double h):width(w),height(h){};
    double getWidth(){
        return width;
    }
    double getHeight(){
        return height;
    }
    double getPerimeter(){
        return (int)(width+height)*2;
    }
    double getArea(){
        return width*height;
    }
};
void display(Rectangle r);
#endif