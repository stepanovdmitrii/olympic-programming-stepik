#include <iostream>
#include <vector>
#include <algorithm>

std::vector<uint64_t>::iterator find_min_not_zero(std::vector<uint64_t> &values)
{
    auto min = values.end();
    for (auto it = values.begin(); it != values.end(); ++it)
    {
        if (*it != 0 && (min == values.end() || *it < *min))
        {
            min = it;
        }
    }
    return min;
}

bool contains_two_non_zero(std::vector<uint64_t> &values)
{
    uint8_t cnt = 0;
    for (auto it = values.begin(); it != values.end(); ++it)
    {
        if (*it != 0)
        {
            cnt++;
        }
        if (cnt > 1)
        {
            return true;
        }
    }
    return false;
}

uint64_t gcd(std::vector<uint64_t> &values)
{
    auto it = find_min_not_zero(values);
    while (contains_two_non_zero(values) && it != values.end())
    {
        for (auto i = values.begin(); i != values.end(); ++i)
        {
            if(*i != 0 && i != it) {
                *i = *i % *it;
            }
        }
        it = find_min_not_zero(values);
    }
    return *it;
}

uint64_t gcd(uint64_t a, uint64_t b) {
    uint64_t r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    size_t cnt;
    std::cin >> cnt;
    uint64_t result = 0;
    uint64_t value = 0;
    for (size_t i = 0; i < cnt; ++i)
    {
        std::cin >> value;
        result = gcd(result, value);
    }
    std::cout << result;
}