#include <iostream>

int main()
{
    uint16_t n, k;
    std::cin >> n >> k;
    std::cout << (n - k) * (n + k);
    return 0;
}