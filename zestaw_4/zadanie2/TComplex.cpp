#include "TComplex.h"

 TComplex TComplex::operator+(TComplex A){
    return TComplex(this->re + A.re, this->im + A.im);
}

TComplex TComplex::operator-(TComplex A){
    return TComplex(this->re - A.re, this->im - A.im);
}

TComplex::TComplex(double re, double im) : re(re), im(im) {}

TComplex TComplex::conj() {
    return TComplex(this->re, -this->im);
}

double TComplex::abs() {
    return sqrt(pow(this->re, 2) + pow(this->im, 2));
}

TComplex TComplex::operator*(TComplex A){
    return TComplex(this->re * A.re - this->im * A.im, this->re * A.im + this->im * A.re);

}

TComplex TComplex::operator/(TComplex A){

    TComplex sprzezenie = A.conj();
    TComplex mnozenie = *this * sprzezenie;
    double mianownik = pow(A.re, 2) + pow(A.im, 2);
    return TComplex(mnozenie.re / mianownik, mnozenie.im / mianownik);
}

std::ostream& operator<<(std::ostream& os, const TComplex A){
    os <<"("<<A.re << ", " << A.im << ")";
    return os;
}

TComplex obiekt(int i, int j) {
    return TComplex(i, j);
}
