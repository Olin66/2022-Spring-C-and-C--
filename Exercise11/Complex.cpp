#include "Complex.h"

Complex::Complex(double re, double im){
    this->real = re;
    this->imag = im;
}

double Complex::getReal(){
    return this->real;
}

double Complex::getImag(){
    return this->imag;
}

void Complex::setReal(double re){
    this->real = re;
}

void Complex::setImag(double im){
    this->imag = im;
}

Complex Complex::operator+(const Complex &rhs) const{
    Complex res;
    res.real = this->real + rhs.real;
    res.imag = this->imag + rhs.imag;
    return res;
}

Complex Complex::operator+(double n) const{
    double re = n + this->real;
    double im = this->imag;
    return Complex(re, im);
}

Complex operator+(double n, Complex &rhs){
    return rhs + n;
}

Complex Complex::operator-(const Complex &rhs) const{
    Complex res;
    res.real = this->real - rhs.real;
    res.imag = this->imag - rhs.imag;
    return res;
}

Complex Complex::operator-(double n) const{
    double re = n - this->real;
    double im = this->imag;
    return Complex(re, im);
}

Complex operator-(double n, Complex &rhs){
    double re = n - rhs.real;
    double im = - rhs.imag;
    return Complex(re, im);
}

Complex Complex::operator*(const Complex &rhs) const{
    Complex res;
    res.real = this->real * rhs.real - this->imag * rhs.imag;
    res.imag = this->real * rhs.imag + this->imag * rhs.real;
    return res;
}

Complex Complex::operator*(double n) const{
    double re = this->real * n;
    double im = this->imag * n;
    return Complex(re, im);
}

Complex operator*(double n, Complex &rhs){
    return rhs * n;
}

Complex operator~(Complex &rhs){
    return Complex(rhs.real, -rhs.imag);
}

bool Complex::operator==(Complex &rhs) const{
    return (bool)((this->real == rhs.real) && (this->imag == rhs.imag));
}

bool Complex::operator!=(Complex &rhs) const{
    return (bool)!(*this == rhs);
}

void operator>>(std::istream &is, Complex &c){
    double re, im;
    std::cout<<"real:";
    is>>re;
    std::cout<<"imaginary:";
    is>>im;
    c.setReal(re);
    c.setImag(im);
}

std::ostream& operator<<(std::ostream &os, const Complex &c){
    os<<c.real<<(c.imag>=0?"+":"")<<c.imag<<"i";
    return os;
}