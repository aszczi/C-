#include <iostream>
#include <vector>
#include <numeric>

int main(){
    std::vector<int> vec(15,0);
    std::iota( vec.begin(), vec.end(), 7);
    auto makeLambda = [=](std::string a, int b){
        a.append("-");
        a.append(std::to_string(b));
        return a;
    };

    auto s = std::accumulate(vec.begin()+1, vec.end(), std::to_string(vec.at(0)), makeLambda);
    std::cout << s<< std::endl;
    return 0;
}