//#ifndef ZADANKO1_ZESTAW3_TSTRING_H
//#define ZADANKO1_ZESTAW3_TSTRING_H
#ifndef TSTRING_H
#define TSTRING_H
#include <cstring>
#include <string_view>
#include <string>
#include <utility>
// w pliku nagłówkowym NIE
// otwieramy przestrzeni std
class TString {
public:
    TString(const char* s = nullptr);
    TString() = default;
    TString(std::string_view sv);
    TString(int i) : TString(std::to_string(i)) {};
    ~TString();
    TString(const TString& s);
    TString& operator= (const TString& s);
    TString(TString&& s);
    TString& operator= (TString&& s);
private:
    std::size_t len {};
    char* ptr {};
protected:

};
#endif

