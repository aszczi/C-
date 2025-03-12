#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>


std::vector<int> vec(100,0);

void printVec(std::vector<int> vec){
    for(auto i : vec){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
bool isACustomLower(int a, int b) {
    std::string strA = std::to_string(a);
    std::string strB = std::to_string(b);
    if(strA.length() == strB.length())
        return a < b;
    if(strA[0] != strB[0])
     return strA[0] < strB[0];
    return strA.length() < strB.length();
}

struct{
    bool operator()(int a, int b){
        return a > b;
    }
} customGreater;

int main(){
     std::iota( vec.begin(), vec.end(), 1 );
     std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(vec.begin(), vec.end(), g);
    std::cout<<"After Shuffle: \n";
    printVec(vec);
    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout<<"After greater sort: \n";
    printVec(vec);

    std::sort(vec.begin(), vec.end(), customGreater);
    std::cout<<"After custom greater sort: \n";
    printVec(vec);

    std::sort(vec.begin(), vec.end(), [](int a, int b){
        return isACustomLower(a,b);
    });
    std::cout<<"Lambda: \n";
    printVec(vec);

    return 0;
}