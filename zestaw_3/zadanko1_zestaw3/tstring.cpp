#include "tstring.h"
#include <algorithm>
#include <string_view>
#include<iostream>

using namespace std;

TString::TString(const char* s) : len{0} , ptr{nullptr} {
    if (s != nullptr) {
        len = strlen(s);
        ptr = new char[len+1];
        strcpy(ptr, s); // albo: memcpy(ptr, s, len+1);
    }

#ifdef DEBUG
    cout << "TString c-tor " << len << " - " << (ptr ? ptr : "pusty") << endl;
#endif
}

TString::TString(string_view sv) : len{sv.size()}, ptr{len ? new char[len+1]{} : nullptr} {
    if (ptr) {
        copy(begin(sv), end(sv), ptr);
        ptr[len] = '\0'; // można pominąć, bo mamy '\0' w tablicy, ale oddaje intencję
    }
#ifdef DEBUG
    cout << "TString c-tor " << len << " - " << (ptr ? ptr : "pusty") << endl;
#endif
}

TString::~TString() {
#ifdef DEBUG
    cout << "TString d-tor " << len << " - " << ( ptr ? ptr : "pusty" ) << endl;
#endif
    delete [] ptr;
}

TString::TString(const TString& s) : len{s.len}, ptr{len ? new char[len+1]{} : nullptr} {
    if (ptr) {
        copy(s.ptr, s.ptr+len+1, ptr);
    }
#ifdef DEBUG
    cout << "TString cc-tor " << len << " - " << ( ptr ? ptr : "pusty" ) << endl;
#endif
}


TString& TString::operator= (const TString& s ) {
    if ( this != &s ) { // if ( *this != s ) {
        delete [] ptr; len = s.len; ptr = nullptr;
        ptr = len ? new char[len+1]{} : nullptr;
            if (ptr) {
            copy(s.ptr, s.ptr+len+1, ptr);
            }
    }
#ifdef DEBUG
cout << "TString copy operator= " << len << " - " << ( ptr ? ptr : "pusty" ) << endl;
#endif
return *this;
}

TString::TString(TString&& s) : ptr{s.ptr}, len{s.len} {
    s.ptr = nullptr;
    s.len = 0;
#ifdef DEBUG
    cout << "TString mvc-tor " << len << " - " << ( ptr ? ptr : "pusty" ) << endl;
#endif
}

TString& TString::operator= (TString&& s) {
    if (this != &s) {
        delete[] ptr; // usuń dotychczasowy zasób
        len = s.len; // typy proste się tylko (po prostu) kopiuje
        ptr = s.ptr; // tu zabieramy adres wskaźnika (przeniesienie praw własności)
        s.len = 0; // obiekt, któremu zabraliśmy, zerujemy
        s.ptr = nullptr; // wskaźnik również zerujemy
    }
#ifdef DEBUG
    cout << "TString move operator= " << len << " - " << ( ptr ? ptr : "pusty" ) << endl;
#endif
    return *this;
}