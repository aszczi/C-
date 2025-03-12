#include <iostream>

/*. Napisz klasę TSmartPtr, w której przeładujesz operatory -> oraz *, zaprezentuj w programie. Przykład
takiego kodu jest pokazany na slajdach „wykładowych” */

class A { public: void funA(); };

class TSmartPtr {
    A *fp { nullptr };
    A* fTable[5] { nullptr };
    int fUse { 0 };
public:
    TSmartPtr(A *prt = nullptr) : fp(prt) { }
    A* operator->();
    A& operator*();
};

A* TSmartPtr::operator->()  { fTable[fUse] = fp; fUse = (++fUse) % 5; return fp; }
A& TSmartPtr::operator*() { return *(operator->()); }

void A::funA() {std::cout<<"hue hue hue" << std::endl;}

int main(){
    A a;
    TSmartPtr wsk = &a;
    wsk->funA();
    (*wsk).funA();
}
