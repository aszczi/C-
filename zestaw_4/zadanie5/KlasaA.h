#ifndef ZESTAW4_ZADANKO5_KLASAA_H
#define ZESTAW4_ZADANKO5_KLASAA_H
#include<iostream>

class KlasaA {
 int a;
public:
    KlasaA(int k) : a(k) {}
    KlasaA operator++();
    KlasaA operator--();
    KlasaA operator+(KlasaA A);
    KlasaA operator-(KlasaA A);
    KlasaA operator+() const;
    KlasaA operator-() const;
    KlasaA operator++(int);
    KlasaA operator--(int);
    friend std::ostream& operator<<(std::ostream& os, const KlasaA A);
};

#endif //ZESTAW4_ZADANKO5_KLASAA_H
