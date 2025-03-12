#include <iostream>
#include <vector>


//Zmodyfikuj program z poprzedniego zadania tak, żeby korzystał z wyliczonych wcześniej wartości (nie
//powtarzał ich wyliczania) do wyznaczenia następnych. Na przykład, żeby pytał, który element ciągu
//ma wyliczyć i jeśli program już wcześniej wyliczył niższe wartości, to miał je zapamiętane i wykorzystał.
//Można użyć prostą tablicę lub jeśli ktoś potrafi (chce) to jakiś kontener np. std::vector.

unsigned long long fib(unsigned long long n, std::vector<unsigned long long>& fibonacci) {
    if (n == 0) {
        if (fibonacci.empty()) {
            fibonacci.push_back(1);
        }
        return 1;
    }

    if (n == 1) {
        if (fibonacci.size() < 2) {
            fibonacci.push_back(1);
        }
        return 1;
    }

    if (n <= fibonacci.size()) {
        return fibonacci[n - 1];
    } else {
        unsigned long long result = fib(n - 1, fibonacci) + fib(n - 2, fibonacci);
        fibonacci.push_back(result);
        return result;
    }
}

unsigned long long fib2(unsigned long long n, std::vector<unsigned long long>& fibonacci) {
    unsigned long long a = 0, b = 1, c;
    if (n == 0) return a;
    if(n-1 < fibonacci.size()) {
        if(n = fibonacci.size()){
            fibonacci.push_back(fibonacci[n-1] + fibonacci[n-2]);
        }
        return fibonacci[n-1] + fibonacci[n-2];
    }

    for (unsigned long long i=1; i<n; ++i) {
        c = a + b;
        a = b;
        b = c;
        if(i > fibonacci.size()) {
            fibonacci.push_back(b);
        }
    }
    return b;
}


int main() {
    std::vector<unsigned long long> fibonacci;
    std::vector<unsigned long long> fibonacci2;
    unsigned long long k = 80;
    for (unsigned long long i = 1; i <= k; ++i) {
        std::cout << fib(i, fibonacci) << std::endl;
    }

    for (unsigned long long i = 1; i <= k; ++i) {
        std::cout << fib2(i, fibonacci2) << std::endl;
    }

    return 0;
}