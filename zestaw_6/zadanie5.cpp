#include<iostream>
#include<algorithm>
#include<list>
#include<set>

int main(){
    std::list<char> lista{'a', 'c', 'b', 'd', 'f', 'e', 'h', 'g'};
    auto sort =[&](const auto& a, const auto& b){
        auto A = std::find(lista.begin(), lista.end(), a);
        auto B = std::find(lista.begin(), lista.end(), b);
        return std::distance(lista.begin(), A) < std::distance(lista.begin(), B);
    };

    std::set<char, decltype(sort)>
            mySet({'a', 'a' , 'a', 'g', 'c', 'b', 'f', 'h', 'c', 'e', 'd', 'e'}, sort);
    for(const auto& c : mySet){
        std::cout << c;
    }
    return 0;
}