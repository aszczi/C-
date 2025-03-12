#include <iostream>
#include <vector>
#include <algorithm>
#include <map>



int main() {
    std::map<int, std::string> mis{{1, "jeden"}, {2, "dwa"}, {3, "trzy"}, {4, "cztery"}, {5, "piec"}, {6, "szesc"}, {7, "siedem"}, {8, "osiem"}, {9, "dziewiec"}};
    std::vector<int> vec{2, 3, 4, 5};
    std::vector<std::string> vecStr;
    std::transform(vec.begin(), vec.end(), std::back_inserter(vecStr), [&mis](int vec) {
        return mis[vec];
    });
    for (const auto& i : vecStr) {
        std::cout << i << " ";
    }
    return 0;
}
