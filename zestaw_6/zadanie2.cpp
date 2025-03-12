#include <iostream>

int main() {
    auto fibo =[](int a) {
        auto inner_fibo = [](int b, const auto& impl) {
            if(b == 1 || b == 0) return b;
            return impl(b-1,impl)+impl(b-2, impl);

        };
        return inner_fibo(a, inner_fibo);
    };
    for (int i = 0; i < 10; i++) {
        std::cout << fibo(i) << " ";
    }
    return 0;
}
