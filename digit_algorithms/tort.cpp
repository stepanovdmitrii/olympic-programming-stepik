#include <iostream>

int main() {
    uint_fast16_t n;
    std::cin >> n;
    if (n == 0 || n == 1) {
        std::cout << 0;
    } else if (n % 2 == 0) {
        std::cout << n / 2;
    } else {
        std::cout << n;
    }
    return 0;
}