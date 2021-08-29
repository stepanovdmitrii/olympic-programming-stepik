#include <iostream>

int main()
{
    uint_fast64_t n;
    std::cin >> n;

    for(uint64_t d = 2; d <= 1e6; ++d){
        while (n % d == 0)
        {
            n = n / d;
        }
    }

    std::cout << n;

    return 0;
}