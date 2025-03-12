#include <iostream>
#include <initializer_list>

/* wersja z auto jako argument funkcji, nie zwraca poprawnie liczb zmiennoprzecinkowych
auto fun(const auto& arg){
    size_t sum = 0;
    for(auto i = arg.begin(); i != arg.end(); ++i){
         sum += *i;
    }
    return sum;
}*/

template<typename T>
auto fun(const std::initializer_list<T>& arg){ //wersja z std::initializer_list<T> jako argument funkcji, zwraca poprawnie liczby zmiennoprzecinkowe
    T sum = 0;
    for(auto i = arg.begin(); i != arg.end(); ++i){
        sum += *i;
    }
    return sum;
}

int main() {

    auto arg = {1, 2, 3};
    std::initializer_list<int> integers = {1, 2, 3};
    std::initializer_list<float> floats = {1.9, 2.3, 3.4};

    // fun({1, 2, 3});//error
    std::cout << fun(arg) << '\n'<< fun(integers) << '\n' << fun(floats) << '\n';

    return 0;
}
