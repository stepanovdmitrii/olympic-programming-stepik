#include <iostream>

bool is_prime(const uint_fast32_t &n)
{
    uint_fast32_t d = 2;
    while (n % d != 0 && d * d <= n)
    {
        ++d;
    }
    return d * d > n;
}

int main() {
    uint64_t n = 0;
    std::cin >> n;
    uint64_t result = 0;
    for (uint64_t i = 2; i * i * i <= n; ++i) {
        if (n % i == 0 && is_prime(i)){
            result = i;
        }
    }
    std::cout << result;
    return 0;
}