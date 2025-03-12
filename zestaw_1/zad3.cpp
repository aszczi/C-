#include <iostream>

//Napisz funkcję wyliczającą kolejne wyrażenia ciągu Fibonacciego
//a. w wersji rekurencyjnej (czyli funkcja wywołuje samą siebie)
//b. w wersji z jedną pętlą for

unsigned long long fib_a(unsigned long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib_a(n-1) + fib_a(n-2);
}

unsigned long long fib_b(unsigned long long n) {
    unsigned long long a = 0, b = 1, c;
    if (n == 0) return a;
    for (unsigned long long i=1; i<n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {

    unsigned long long k = 80;
    //wersja z rekurencją
     for (unsigned long long i=1; i<=k; ++i) {
        std::cout << fib_a(i) << std::endl;
    }
    //wersja z pętlą for
    for (unsigned long long i=1; i<=k; ++i) {
        std::cout << fib_b(i) << std::endl;
    }


}