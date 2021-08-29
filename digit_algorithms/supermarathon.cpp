#include <iostream>

int main()
{
    const uint_fast16_t m = 13 * 17;
    uint_fast16_t n;
    std::cin >> n;
    std::cout << (n / 13 + n / 17 - n / m);
    return 0;
}