#include <iostream>
#include <vector>

int main() {
    size_t left, right;
    std::cin >> left >> right;
    std::vector<bool> is_prime(right + 1, true);
    std::vector<uint64_t> counts(right + 1, 0);
    for (size_t idx = 2; right / idx > 0; ++idx)
    {
        if (is_prime[idx])
        {
            for (size_t idx2 = idx; idx2 < right + 1; idx2 = idx2 + idx)
            {
                is_prime[idx2] = false;
                counts[idx2]++;
            }
        }
    }
    for (size_t idx = left; idx < counts.size(); ++idx){
        std::cout << counts[idx] << " ";
    }
    return 0;
}