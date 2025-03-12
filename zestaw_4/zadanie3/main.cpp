#include <iostream>
#include "TArr.h"
#include <string>

/*
 * Napisać kod dla klasy TArr (jak niżej) realizujący idiom Copy-On-Write (bardzo podobny przykład jest
na slajdach „wykładowych”). Proszę zaimplementować konstruktory: zwykły, kopiujący, przenoszący,
operatory= kopiujący i przenoszący, destruktor oraz dowolną metodę, która właśnie „coś zmienia”
w zasobie, czyli tablicy do wskaźnika buf i powodującą wykonanie „głębokiej kopii”. Proszę nie
zapomnieć o kilku liniach testowego kodu, również metodzie, dzięki której można sprawdzić ile
obiektów współdzieli zasób w danym momencie.
class TArr {
 private:
 struct InnerArray {
 std::size_t len{0};
 std::size_t ref{0};
 int *buf{nullptr};
 } *ptr{nullptr};
};
 */
int main() {
    std::string str1 = "123";
    const char str[] = "Hello, World!";
    TArr a(str);//construktor
    std::cout<<"a: ";
    a.print_class();

    TArr b(a); //copy constructor
    std::cout<<"kopiujemy a do b: ";
    b.print_class();
    TArr c(str1);
    std::cout<<"nowe c: ";
    c.print_class();
    TArr d("Ala ma kota");
    std::cout<<"d: ";
    d.print_class();
    c=(std::move(d)); //move constructor
    std::cout<<"c po move(d): ";
    c.print_class();
    TArr e = a; //copy operator
    std::cout<<"operator kopiujacy e = a : ";
    e.print_class();
    std::cout<<"operator przenoszacy f = std::move(e): ";
    TArr f = std::move(e); //move operator
    f.print_class();
    std::cout<<"ptr e po przeniesieniu: ";
    e.get_ptr();
    std::cout<<"c po destruktorze: ";  //destruktor
    c.TArr::~TArr();
    c.get_ref();
    std::cout<<"funkcja zmieniajaca b: ";
    b.change();
    b.print_class();
    return 0;
}
