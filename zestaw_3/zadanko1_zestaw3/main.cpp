#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <chrono>
#include "tstring.h"

int main() {
    TString wyraz1{"Ala"};
    TString wyraz2{"ma"};
    TString wyraz3{"kota"};


    std::vector<TString> wektor{wyraz1, wyraz2, wyraz3, wyraz1, wyraz2, wyraz3};
    TString wyraz4{"Ala ma kota"};

    auto startA = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        wektor.push_back(wyraz4);
    }
    auto koniecA = std::chrono::high_resolution_clock::now();
    auto startB = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        wektor.insert(wektor.begin(), wyraz4);
    }
    auto koniecB = std::chrono::high_resolution_clock::now();
    auto startC = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        wektor.insert(wektor.begin() + 2, wyraz4);
    }
    auto koniecC = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> czasA = koniecA - startA;
    std::chrono::duration<float> czasB = koniecB - startB;
    std::chrono::duration<float> czasC = koniecC - startC;
    std::cout << "Wektor:  calkowity czas wstawianaia na: Koniec: " << czasA.count() <<
              " Poczatek: " << czasB.count() << " Srodek: " << czasC.count() << std::endl;

//usuwanie wektora:
    startA = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        wektor.pop_back();
    }
    koniecA = std::chrono::high_resolution_clock::now();
    startB = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        wektor.erase(wektor.begin());
    }
    koniecB = std::chrono::high_resolution_clock::now();
    startC = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        wektor.erase(wektor.begin() + 2);
    }
    koniecC = std::chrono::high_resolution_clock::now();

    czasA = koniecA - startA;
    czasB = koniecB - startB;
    czasC = koniecC - startC;
    std::cout << "Wektor:  calkowity czas usuwania na: Koniec: " << czasA.count() <<
              " Poczatek: " << czasB.count() << " Srodek: " << czasC.count() << std::endl;


    std::deque<TString> kolejka{wyraz1, wyraz2, wyraz3, wyraz1, wyraz2, wyraz3};
    //dodawanie w kolejce
    startA = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        kolejka.push_back(wyraz4);
    }
    koniecA = std::chrono::high_resolution_clock::now();
    startB = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        kolejka.push_front(wyraz4);
    }
    koniecB = std::chrono::high_resolution_clock::now();
    startC = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        kolejka.insert(kolejka.begin() + 2, wyraz4);
    }
    koniecC = std::chrono::high_resolution_clock::now();

    czasA = koniecA - startA;
    czasB = koniecB - startB;
    czasC = koniecC - startC;
    std::cout << "Kolejka: calkowity czas wstawiania na: Koniec: " << czasA.count() <<
              " Poczatek: " << czasB.count() << " Srodek: " << czasC.count() << std::endl;


    //usuwanie w kolejce
    startA = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        kolejka.pop_back();
    }
    koniecA = std::chrono::high_resolution_clock::now();
    startB = std::chrono::high_resolution_clock::now();
     for(int i= 0; i< 10000; i++){
        kolejka.pop_front();
    }
    koniecB = std::chrono::high_resolution_clock::now();
    startC = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        kolejka.erase(kolejka.begin() + 2);
    }
    koniecC = std::chrono::high_resolution_clock::now();

    czasA = koniecA - startA;
    czasB = koniecB - startB;
    czasC = koniecC - startC;
    std::cout << "Kolejka: calkowity czas usuwania na: Koniec: " << czasA.count() <<
              " Poczatek: " << czasB.count() << " Srodek: " << czasC.count() << std::endl;

    std::list<TString> lista{wyraz1, wyraz2, wyraz3, wyraz1, wyraz2, wyraz3};
    //dodawanie do listy
    startA = std::chrono::high_resolution_clock::now();
     for(int i= 0; i< 10000; i++){
        lista.push_back(wyraz4);
    }
    koniecA = std::chrono::high_resolution_clock::now();
    startB = std::chrono::high_resolution_clock::now();
     for(int i= 0; i< 10000; i++){
        lista.push_front(wyraz4);
    }
    koniecB = std::chrono::high_resolution_clock::now();
    startC = std::chrono::high_resolution_clock::now();

    for(int i= 0; i< 10000; i++){
        auto it = lista.begin();
        std::advance(it, 2);
        lista.insert(it, wyraz4);
    }
    koniecC = std::chrono::high_resolution_clock::now();

    czasA = koniecA - startA;
    czasB = koniecB - startB;
    czasC = koniecC - startC;
    std::cout << "Lista:   calkowity czas wstawiania na: Koniec: " << czasA.count() <<
              " Poczatek: " << czasB.count() << " Srodek: " << czasC.count() << std::endl;

    //usuwanie z listy
    startA = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        lista.pop_back();
    }
    koniecA = std::chrono::high_resolution_clock::now();
    startB = std::chrono::high_resolution_clock::now();
    for(int i= 0; i< 10000; i++){
        lista.pop_front();
    }
    koniecB = std::chrono::high_resolution_clock::now();
    startC = std::chrono::high_resolution_clock::now();
    for(int i= 0; i<10000; i++){
        auto it = lista.begin();
        lista.erase(it);
    }
    koniecC = std::chrono::high_resolution_clock::now();

    czasA = koniecA - startA;
    czasB = koniecB - startB;
    czasC = koniecC - startC;
    std::cout << "Lista:   calkowity czas usuwania na: Koniec: " << czasA.count() <<
              " Poczatek: " << czasB.count() << " Srodek: " << czasC.count() << std::endl;


    return 0;
}