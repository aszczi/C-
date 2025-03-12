#include <iostream>
#include "KlasaA.h"
/* Dla prostej klasy (choćby takiej jak klasa A ze składnikiem int i; na slajdach „wykładowych”) napisz
   przeciążone operatory ++, -- (pre- i post-), jednoargumentowe + i - oraz dwuargumentowe + i -.
   Następnie wykonaj dyskusję (prezentację) ile maksymalnie znaków + (-) można postawić przed lub
   za obiektem typu A, żeby kod był nadal ważny i działający. Jest to zależne od implementacji
   operatorów (w szczególności tego, czy zwracany typ jest z const czy bez – wobec operacji
   przenoszenia rekomenduje się nieużywanie const).*/

int main() {
    KlasaA obj(1);
    KlasaA obj2(2);
    KlasaA obj5(0);

    KlasaA obj3 = obj + obj2; //2+1 = 3
    std::cout<<obj3<<std::endl;
    KlasaA obj4 = obj - obj2; //1-2 = -1
    std::cout<<obj4<<std::endl;
    std::cout<<--obj<<std::endl; //--1 = 0 (predekrementacja)
    std::cout<<obj--<<std::endl; //0-- wyswietla 0 a potem zmniejsza o 1 (postdekrementacja)
    std::cout<<obj<<std::endl; //0-1 = -1
    std::cout<<obj2<<std::endl; //2
    std::cout<<obj2++<<std::endl; //2++ wyswietla 2 a potem zwieksza o 1 (postinkrementacja)
    std::cout<<obj2<<std::endl; //2+1 = 3
    std::cout<<++obj2<<std::endl; //3+1 = 4 (preinkrementacja)
    std::cout<<-------------------------------------------------obj5<<std::endl; //-24
    obj5= 0;
    std::cout<<++++++++++++++++++++++++++++++++++++++++++++++++-obj5<<std::endl; //24
    obj5= 7;
    std::cout<<-obj5<<std::endl; //-7
    std::cout<<+obj5<<std::endl; //7
    obj5++++++++++++++++++++++++++++++++++++++++++;
    std::cout<<obj5<<std::endl;
    obj5 = 0;
    std::cout<<obj5------------------------------------<<std::endl;
    std::cout<<obj5<<std::endl;

    //tu bylby blad std::cout<<obj5+<<std::endl; //ten operator jak i -(pojedyncze) mozemy stosowac jedynie przed
    //program przyjmuje z przodu dowolnie wiele plusow lub minusow
    //natomiast z tylu dziala dla jednej pary ++ lub -- a przyjmuje dowolna parzysta ilosc

    return 0;
}
