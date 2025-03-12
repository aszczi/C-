#include <iostream>
#include <string>
#include <string_view>
#include <compare>
#include <vector>
#include <ranges>
#include <algorithm>
#include "TKlasa.h"

/*Mamy klasę:
class TKlasa {
public:
TKlasa(const char* c); // zmień to na definicję z inicjalizacją
private:
std::string str;
};
Proszę do niej dopisać:
a. operator<=>
b. operator konwersji do const char*
c. operator konwersji do std::string_view
W programie proszę zademonstrować przypadki użycia powyższych (a, b, c). Ponadto zdefiniować
wektor obiektów TKlasa, zainicjalizować (minimum 5 elementów) i posortować, korzystając
z std::ranges::sort w kolejności odwrotnej (wtedy drugim argumentem będzie std::greater<>{}).*/

int main() {
    std::string str1 = "Hello";
    std::string str2 = "World";
    std::string str3 = "550";
    std::string str4 = "550";

   //opertator  <=> dziala poprawnie ponieważ sortowanie przebiega pomyslnie
    std::vector<TKlasa> v = {TKlasa("Ala"), TKlasa("ma"),TKlasa("kota"), TKlasa("i"),  TKlasa("psa")};
    std::ranges::sort(v,  std::greater<>{});

    for (const auto& elem : v) {
        std::cout << elem.getStr() << std::endl;
    }

    TKlasa Tklasa1("test1");
    const char* a = "test3";
    std::string_view def = "test2";
    TKlasa Tklasa4("test4");

//konwersja string_view
    std::string_view abc = std::string_view(Tklasa1);
    std::cout<<abc<<std::endl;
    std::string_view(Tklasa2) = def;
    std::cout<<Tklasa2<<std::endl;

//konwersja const char*
    const char*(Tklasa3) = a;
    std::cout<<Tklasa3<<std::endl;
    const char* c = (const char*)Tklasa4;
    std::cout<<c<<std::endl;
//porównanie
    TKlasa::print_comparison(TKlasa(str1.c_str()), TKlasa(str2.c_str()));
    TKlasa::print_comparison(TKlasa(str2.c_str()), TKlasa(str1.c_str()));
    TKlasa::print_comparison(TKlasa(str3.c_str()), TKlasa(str4.c_str()));

    return 0;
}

