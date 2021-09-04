#include <iostream>
//10 out of 14
int main()
{
    uint64_t n;
    std::cin >> n;

    uint64_t limit = n;
    uint64_t result = 1;
    uint64_t d = 2;
    uint64_t div = d * d;

    while (div <= n && result * d <= limit)
    {
        if (n % (div) == 0)
        {
            result = result * div;
            n = n / (div);
        }
        else if (n % d == 0){
            n = n / d;
        }
        else
        {
            ++d;
        }
        div = d * d;
    }

    std::cout << result;
    return 0;
}