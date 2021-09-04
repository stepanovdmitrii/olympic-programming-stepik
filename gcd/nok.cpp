#include <iostream>
#include <vector>

uint64_t gcd(uint64_t a, uint64_t b)
{
    uint64_t r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    uint64_t a, b;
    std::cin >> a >> b;
    std::cout << (a / gcd(a, b)) * b;
}