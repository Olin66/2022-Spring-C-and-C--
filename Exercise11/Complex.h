#include <iostream>
#ifndef COMPLEX_H
#define COMPLEX_H
class Complex
{
private:
    double real;
    double imag;
public:
    Complex():real(1), imag(1){};
    Complex(double re, double im);
    double getReal();
    double getImag();
    void setReal(double re);
    void setImag(double im);
    Complex operator+(const Complex &rhs) const;
    Complex operator+(double n) const;
    friend Complex operator+(double n, Complex &rhs);
    Complex operator*(const Complex &rhs) const;
    Complex operator*(double n) const;
    friend Complex operator*(double n, Complex &rhs);
    Complex operator-(const Complex &rhs) const;
    Complex operator-(double n) const;
    friend Complex operator-(double n, Complex &rhs);
    friend Complex operator~(Complex &rhs);
    bool operator==(Complex &rhs) const;
    bool operator!=(Complex &rhs) const;
    friend void operator>>(std::istream &is, Complex &c);
    friend std::ostream& operator<<(std::ostream &os, const Complex &c);
};
#endif