#ifndef ZESTAW4_ZADANKO3_TARR_H
#define ZESTAW4_ZADANKO3_TARR_H
#include <iostream>

class TArr {
private:
    struct InnerArray {
        std::size_t len{0};
        std::size_t ref{0};
        int *buf{nullptr};
    } *ptr{nullptr};
public:
    TArr(std::string string1);//constructor
    TArr(const TArr &other); //copy constructor
    TArr(TArr &&other) noexcept;//move constructor
    ~TArr();  // destructor
    TArr operator=(const TArr &other); //copy operator
    TArr operator=(TArr &&other);//move operator
    void print_class();
    void change(); //function changing object
    void get_ref();
    void get_ptr();

};

#endif //ZESTAW4_ZADANKO3_TARR_H
