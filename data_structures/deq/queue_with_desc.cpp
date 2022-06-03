#include <iostream>
#include <deque>
#include <unordered_map>

int main()
{
    std::size_t n;
    std::cin >> n;

    std::deque<size_t> d;
    d.push_back(1);

    std::unordered_map<size_t, size_t> desc;

    while(false == d.empty()) {
        size_t current = d.front();
        d.pop_front();

        size_t value = (2 * current) % n;
        if(desc.find(value) == desc.end()) {
            desc[value] = current;
            d.push_back(value);
        }

        value = (3 * current) % n;
        if(desc.find(value) == desc.end()) {
            desc[value] = current;
            d.push_back(value);
        }

        value = (5 * current) % n;
        if(desc.find(value) == desc.end()) {
            desc[value] = current;
            d.push_back(value);
        }
    }

    for(size_t v = 0; v < n; ++v){
        auto it = desc.find(v);
        if(v == 1 || it == desc.end()) {
            std::cout << -1 << " ";
        } else {
            std::cout << it->second << " ";
        }
    }

    return 0;
}