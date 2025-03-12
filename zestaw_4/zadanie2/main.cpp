#include "TComplex.h"
#include <iostream>

/*Mamy klasę:
class TComplex {
 public:
TComplex(double re, double im); // zamień na definicję z inicjalizacją

 private:
double re{}, im{};
};
Proszę dopisać do niej:
a) operator funkcyjny, żeby zapis obiekt(2,3) tworzył nowy obiekt (zwracany z niego przez wartość)
b) przeciążyć operatory + i –
c) napisać metody conj() zwracające sprzężenie zespolonego i abs() zwracającą wartość
d) przeciążyć operatory * i / (sprawdzić w źródłach jak to jest dla liczby zespolonej)
e) napisać operator<< żeby wypisywał na ekranie na przykład: (2,3)*/

int main() {

    //dodawanie
    auto z = obiekt(2, 3) + obiekt(3, 4);
    std::cout<<obiekt(2, 3)<<" + "<<obiekt(3, 4)<<" = "<<z<<std::endl;
    //odejmowanie
    std::cout<<obiekt(2, 3)<<" - "<<obiekt(3, 4)<<" = "<<obiekt(2, 3) - obiekt(3, 4)<<std::endl;
    //mnozenie
    std::cout<<obiekt(2, 1)<<" * "<<obiekt(2, 1)<<" = "<<obiekt(2, 1) * obiekt(2, 1)<<std::endl;
    //dzielenie
    std::cout<<obiekt(2, 3)<<" / "<<obiekt(1, 1)<<" = "<<obiekt(2, 3) / obiekt(1, 1)<<std::endl;
    //sprzezenie
    std::cout<<"sprzezenie "<<obiekt(2, 3)<<" = "<<obiekt(2, 3).conj()<<std::endl;
    //wartosc bezwzgledna
    std::cout<<"wartosc bezwzgledna "<<obiekt(4, 3)<<" = "<<obiekt(4, 3).abs()<<std::endl;

    return 0;
}



