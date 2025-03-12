#ifndef ZESTAW4_ZADANKO2_TCOMPLEX_H
#define ZESTAW4_ZADANKO2_TCOMPLEX_H
#include <iostream>
#include <cmath>

class TComplex {
public:
    TComplex(double re, double im);
    TComplex operator+(TComplex A);
    TComplex operator-(TComplex A);
    TComplex operator*(TComplex A);
    TComplex operator/(TComplex A);
    TComplex conj();
    double abs();
    friend std::ostream& operator<<(std::ostream& os, const TComplex A);
private:
    double re{}, im{};

};

TComplex obiekt(int i, int j);
#endif //ZESTAW4_ZADANKO2_TCOMPLEX_H
