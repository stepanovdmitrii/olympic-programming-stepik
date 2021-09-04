#include <iostream>

int main() {
    uint64_t n, k, a;
    std::cin >> n >> k >> a;
    uint64_t entrance = 1 +  ( (a - 1) / (n * k));
    uint64_t level = 1 + ((a - 1) % (n * k)) / k;
    std::cout << entrance << " " << level;
    return 0;
}