#include <iostream>
#include <vector>

int main()
{
    size_t l, r;
    std::cin >> l >> r;
    std::vector<bool> is_prime(r + 1, true);
    std::vector<size_t> primes;
    for (size_t idx = 2; idx * idx <= r; ++idx)
    {
        if (is_prime[idx])
        {
            for (size_t idx2 = idx * idx; idx2 < r + 1; idx2 = idx2 + idx)
            {
                is_prime[idx2] = false;
            }
        }
    }
    for (size_t i = 2; i < r + 1; ++i)
    {
        if (is_prime[i] && i >= l && i + 2 < r + 1 && is_prime[i + 2])
        {
            primes.push_back(i);
            primes.push_back(i + 2);
        }
    }

    if (primes.size() == 0)
    {
        std::cout << "empty";
    }
    else
    {
        for (size_t i = 0; i < primes.size(); i = i + 2)
        {
            std::cout << primes[i] << " " << primes[i + 1] << "\n";
        }
    }
    return 0;
}