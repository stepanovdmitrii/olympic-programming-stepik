#include <iostream>

int main()
{
    uint64_t m, n;
    std::cin >> m >> n;
    while (m > 0 && n > 0)
    {
        if (m > n)
        {
            m = m % n;
        }
        else
        {
            n = n % m;
        }
    }
    uint64_t max = m > n ? m : n;
    for (int i = 0; i < max; i++)
    {
        std::cout << 1;
    }
    return 0;
}