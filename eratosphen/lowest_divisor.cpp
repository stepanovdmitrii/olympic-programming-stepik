#include <iostream>
#include <vector>

int main()
{
    int32_t l, r;
    std::cin >> l >> r;
    std::vector<int32_t> is_prime(r + 1, -1);
    for (size_t idx = 2; idx * idx <= r; ++idx)
    {
        if (is_prime[idx] == -1)
        {
            for (int32_t idx2 = idx * idx; idx2 < r + 1; idx2 = idx2 + idx)
            {
                if (is_prime[idx2] < 0)
                {
                    is_prime[idx2] = idx;
                }
            }
        }
    }

    for (int32_t i = l; i <= r; ++i)
    {
        if (is_prime[i] == -1)
        {
            std::cout << i << " ";
        }
        else
        {
            std::cout << is_prime[i] << " ";
        }
    }
    return 0;
}