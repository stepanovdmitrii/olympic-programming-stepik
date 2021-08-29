#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<uint_fast64_t> factorization(uint_fast64_t n)
{
    std::vector<uint_fast64_t> result;
    while (n % 2 == 0)
    {
        result.push_back(2);
        n = n / 2;
    }
    uint_fast64_t d = 3;
    while (d * d <= n)
    {
        if (n % d == 0)
        {
            result.push_back(d);
            n = n / d;
        }
        else
        {
            ++d;
        }
    }
    if (n > 1)
    {
        result.push_back(n);
    }
    return result;
}

int main()
{
    uint_fast64_t n;
    std::cin >> n;
    std::unordered_map<uint_fast64_t, uint_fast64_t> dict;
    while (n % 2 == 0)
    {
        dict[2]++;
        n = n / 2;
    }
    uint_fast64_t d = 3;
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

    uint_fast64_t max = 0;
    for(auto it = dict.begin(); it != dict.end(); ++it){
        if(it->second > max) {
            max = it->second;
        }
    }

    std::cout << max;

    return 0;
}