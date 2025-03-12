#include "TArr.h"


TArr::TArr(std::string string1){
    ptr = new InnerArray;
    ptr->len = string1.size();
    ptr->ref = 1;
    ptr->buf = new int[ptr->len + 1];
    for (int i = 0; i <= ptr->len; i++){
        ptr->buf[i] = string1[i];
    }
}

TArr::TArr(const TArr &other){
    ptr = other.ptr;
    ptr->ref++;
}

TArr::~TArr(){
    if(ptr == nullptr){
        return;
    }
    if (--ptr->ref == 0){
        delete[] ptr->buf;
        delete ptr;
    }
}

TArr::TArr(TArr &&other) noexcept {
    ptr = other.ptr;
    other.ptr = nullptr;
}

TArr TArr::operator=(const TArr &other){
    if(this != &other){
        ptr->ref--;
        if (ptr->ref == 0){
            delete[] ptr->buf;
            delete ptr;
        }
        ptr = other.ptr;
        ptr->ref++;
    }
    return *(this);
}

TArr TArr::operator=(TArr &&other){
    if(this != &other){

        if (ptr->ref == 0){
            delete[] ptr->buf;
            delete ptr;

        }
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *(this);
}

void TArr::change(){
    if (ptr->ref > 1){
        ptr->ref--;
        ptr = new InnerArray;
        ptr->len = 3;
        ptr->ref = 3;
        ptr->buf = new int[ptr->len + 1];
        ptr->buf[0] = 'o';
        ptr->buf[1] = 'k';
        ptr->buf[2] = 0;
    }
    else{
        ptr->buf[0] = 0;
    }
}

void TArr::print_class(){
    std::cout << ptr << " len: " << ptr->len << " ref: " << ptr->ref << " buf: " << ptr->buf << std::endl;
        for(int i = 0; i < ptr->len; i++){
        std::cout << (char)ptr->buf[i];
        }
        std::cout<< std::endl;
}

void TArr::get_ref(){
    std::cout << ptr << " len: " << ptr->len << " ref: " << ptr->ref << " buf: " << ptr->buf << std::endl;
}


void TArr::get_ptr(){
    std::cout << ptr<<std::endl;
}