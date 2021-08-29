#include <iostream>
#include <vector>

int main()
{
    std::vector<uint_fast32_t> divisors;
    uint_fast32_t n;
    std::cin >> n;
    for (uint_fast32_t i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            std::cout << i << " ";
            if (i * i != n)
            {
                divisors.push_back(n / i);
            }
        }
    }
    for (std::vector<uint_fast32_t>::reverse_iterator it = divisors.rbegin(); it != divisors.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    return 0;
}