#ifndef ZESTAW4_ZADANKO1_TKLASA_H
#define ZESTAW4_ZADANKO1_TKLASA_H
#include<string>
#include <string_view>
#include <compare>
#include<set>
#include <utility>
#include <iostream>
#include <cstring>

class TKlasa {
    private:
        std::string str;

    public:
        TKlasa(const char* c);
        //TKlasa(const std::string& s);
        //std::strong_ordering operator<=>(const TKlasa& other) const = default; //albo auto

        std::string getStr() const;
       // operator const char*() const;
          explicit operator const char*() {
           char* c = new char[str.length() + 1];
           strcpy(c, str.c_str());
           c[str.length()] = '\0';
           return c;
       }

       operator std::string_view();

    friend std::strong_ordering operator<=>(TKlasa& lhs, TKlasa& rhs)
    {
        if (lhs.str < rhs.str )
            return std::strong_ordering::less;
        if (lhs.str > rhs.str or (lhs.str == rhs.str and lhs.str> rhs.str))
            return std::strong_ordering::greater;
        return std::strong_ordering::equivalent;
    }

    static void print_comparison(TKlasa klasa, TKlasa klasa1);
};


#endif //ZESTAW4_ZADANKO1_TKLASA_H
