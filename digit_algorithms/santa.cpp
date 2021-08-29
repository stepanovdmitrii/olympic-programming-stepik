#include <iostream>

int main()
{
    uint_fast16_t n, k;
    std::cin >> n >> k;
    if (k % n == 0)
    {
        std::cout << 0;
    }
    else
    {
        std::cout << (n - k % n);
    }
    return 0;
}