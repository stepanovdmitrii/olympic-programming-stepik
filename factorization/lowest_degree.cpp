#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

int main()
{
    uint64_t n;
    std::cin >> n;
    std::unordered_map<uint64_t, uint64_t> dict;
    while (n % 2 == 0)
    {
        dict[2]++;
        n = n / 2;
    }
    uint64_t d = 3;
    while (d * d <= n)
    {
        if (n % d == 0)
        {
            dict[d]++;
            n = n / d;
        }
        else
        {
            ++d;
        }
    }
    if (n > 1)
    {
        dict[n]++;
    }

    uint64_t min_value = UINT64_MAX;
    uint64_t min_degree = UINT64_MAX;
    for(auto it = dict.begin(); it != dict.end(); ++it){
        if(it->first < min_value) {
            min_value = it->first;
            min_degree = it->second;
        }
    }

    std::cout << min_degree;

    return 0;
}