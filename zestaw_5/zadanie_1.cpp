#include <iostream>
using namespace std;
#define P(x) std::cout << x << std::endl

class A1 {
    int i { 5 };
public:
    A1(bool) { P("A1 c-tor"); }
    virtual ~A1() { P("A1 d-tor"); }
    int get() const { return i; }
};

class V1 : virtual public A1 {
public:
    V1(bool) : A1(true) { P("V1 c-tor"); }
    virtual ~V1() override { P("V1 d-tor"); }
};

class C1 : virtual public V1{
public:
    C1() : A1(true), V1(true) { P("C1 c-tor"); }
    virtual ~C1() override { P("C1 d-tor"); }

};
class B2{
public:
    B2() { P("B2 c-tor"); }
    virtual ~B2() { P("B2 d-tor"); }
};
class B3{
public:
    B3() { P("B3 c-tor"); }
    virtual ~B3() { P("B3 d-tor"); }
};
class V2 : virtual public A1, public B2{
public:
    V2() : A1(true) { P("V2 c-tor"); }
    virtual ~V2() override { P("V2 d-tor"); }
};
class C2 : virtual public V2, public B3{
public:
    C2() : A1(true), V2() { P("C2 c-tor"); }
    virtual ~C2() override { P("C2 d-tor"); }
};
class M1 {
public:
    M1() { P("M1 c-tor"); }
    ~M1() { P("M1 d-tor"); }
};
class M2{
public:
    M2() { P("M2 c-tor"); }
    ~M2() { P("M2 d-tor"); }
};
class X : public C1, public C2 {
    M1 m1;
    M2 m2;
public:
// zaimplementuj c-tor i d-tor
    X() : A1(true), V1(true), C1(), V2(), C2() { P("X c-tor"); }
    ~X() { P("X d-tor"); }
};

int main() {
    A1 *pa = new X;
    cout << pa->get() << endl; // zakomentować gdy public A1
    delete pa;
}

//a) co się stanie jeśli virtual ~V1(); (i inne, bez override) i ~A1(); (niewirtualne).
//   konstruktory wywołuja sie wszystkie, natomiast z destruktorow pojawia sie tylko A1 d-tor i konczy sie bledem "Process finished with exit code -1073740940 (0xC0000374)"

//b) co się stanie jeśli będzie dziedziczenie zwykłe public A1
/*
In constructor 'C1::C1()':
error: type 'A1' is not a direct or virtual base of 'C1'
    C1() : A1(true), V1(true) { P("C1 c-tor"); }
           ^~
In constructor 'C2::C2()':
error: type 'A1' is not a direct or virtual base of 'C2'
    C2() : A1(true), V2() { P("C2 c-tor"); }
           ^~
In constructor 'X::X()':
error: type 'A1' is not a direct or virtual base of 'X'
     X() : A1(true), V1(true), C1(), V2(), C2() { P("X c-tor"); }
           ^~
In function 'int main()':
error: 'A1' is an ambiguous base of 'X'
     A1 *pa = new X;
*/