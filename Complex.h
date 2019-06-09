//
// Created by prose on 29.04.2019.
//

#ifndef KURSOVAYA_COMPLEX_H
#define KURSOVAYA_COMPLEX_H


#include <ostream>

class Complex {
private:
    double re;
    double im;
public:
    Complex(double re, double im): re(re), im(im) {};
    Complex operator+(const Complex &c);
    Complex operator*(const Complex &c);
    double abs();

};


#endif //KURSOVAYA_COMPLEX_H
