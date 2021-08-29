#include <iostream>

int main() {
    uint_fast16_t w, t, T;
    std::cin >> w >> t >> T;
    std::cout << ((T + (t - 1)) / t) * w;
    return 0;
}