#include <iostream>

uint64_t gcd(uint64_t l, uint64_t r)
{
    uint64_t d = 0;
    while (r != 0)
    {
        d = l % r;
        l = r;
        r = d;
    }
    return l;
}

int main()
{
    int64_t x1, y1;
    int64_t x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    uint64_t dx = x2 > x1 ? x2 - x1 : x1 - x2;
    uint64_t dy = y2 > y1 ? y2 - y1 : y1 - y2;
    std::cout << gcd(dx, dy) + 1;
    return 0;
}