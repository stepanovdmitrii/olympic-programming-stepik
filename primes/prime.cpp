#include <iostream>
#include <vector>

bool is_prime(const uint_fast32_t &n)
{
    uint_fast32_t d = 2;
    while (n % d != 0 && d * d <= n)
    {
        ++d;
    }
    return d * d > n;
}

int main()
{
    std::vector<uint_fast32_t> divisors;
    uint_fast32_t n;
    std::cin >> n;
    for (uint_fast32_t i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (is_prime(i))
            {
                std::cout << i << " ";
            }
            if (i * i != n)
            {
                divisors.push_back(n / i);
            }
        }
    }
    for (std::vector<uint_fast32_t>::reverse_iterator it = divisors.rbegin(); it != divisors.rend(); ++it)
    {
        if (is_prime(*it))
        {
            std::cout << *it << " ";
        }
    }
    if (is_prime(n))
    {
        std::cout << n << " ";
    }
    return 0;
}