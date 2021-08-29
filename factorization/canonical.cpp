#include <iostream>
#include <map>

int main()
{
    uint64_t n;
    std::cin >> n;
    std::map<uint64_t, uint64_t> dict;
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

    for(auto it = dict.begin(); it != dict.end(); ++it){
        std::cout << it->first << " " << it->second << '\n';
    }

    return 0;
}