#include "Complex.h"
#include <math.h>

Complex Complex::operator+(const Complex &c) {
    return Complex(re + c.re, im + c.im);
}

Complex Complex::operator*(const Complex &c) {
    return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
}

double Complex::abs() {
    return sqrt(re*re + im*im);
}