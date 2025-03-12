#include "KlasaA.h"

std::ostream& operator<<(std::ostream& os, const KlasaA A){
    os << A.a;
    return os;
}
KlasaA KlasaA::operator++(){
    return ++a;
}
KlasaA KlasaA::operator--(){
    return --a;
}
KlasaA KlasaA::operator+(KlasaA A){
    return KlasaA(this->a + A.a);
}
KlasaA KlasaA::operator-(KlasaA A){
    return KlasaA(this->a - A.a);
}
KlasaA KlasaA::operator++(int){
    KlasaA temp = *this;
    this->a+=1;
    return temp;
}
KlasaA KlasaA::operator--(int) {
    KlasaA temp = *this;
    this->a-=1;
    return temp;
}

KlasaA KlasaA::operator+() const{
    return KlasaA(a);
}

KlasaA KlasaA::operator-() const{
    return KlasaA(-a);
}