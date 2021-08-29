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

    uint64_t max_value = 0;
    uint64_t max_degree = 0;
    for(auto it = dict.begin(); it != dict.end(); ++it){
        if(it->first > max_value) {
            max_value = it->first;
            max_degree = it->second;
        }
    }

    std::cout << max_degree;

    return 0;
}