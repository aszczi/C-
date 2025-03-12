#include "TKlasa.h"

/*
TKlasa::TKlasa(const char* c) {
    this->str = c;
}*/


TKlasa::TKlasa(const char* c) : str(c) {}

//TKlasa::TKlasa(const std::string& s) : str(s) {}

std::string TKlasa::getStr() const { return str; }

/*
TKlasa::operator const char*() const {
    return static_cast<const char*>(str.c_str());
}
 */



TKlasa::operator std::string_view(){
    return std::string_view(str);

}
void TKlasa::print_comparison(TKlasa klasa, TKlasa klasa1)
 {
    std::cout << klasa.str
              << (klasa.str < klasa1.str ? " <  " : klasa.str > klasa1.str ? " >  " : " == ") // compares p and q
              << klasa1.str << '\n';
}


