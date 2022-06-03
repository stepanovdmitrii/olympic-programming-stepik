#include <iostream>
#include <deque>
#include <unordered_set>

int main()
{
    std::size_t n;
    std::cin >> n;

    std::deque<size_t> d;
    d.push_back(1);
    std::cout << 1;

    std::unordered_set<size_t> printed;

    while(false == d.empty()) {
        size_t current = d.front();
        d.pop_front();

        if(2 * current <= n && printed.find(2 * current) == printed.end()) {
            std::cout << " " << 2 * current;
            d.push_back(2*current);
            printed.insert(2 * current);
        }

        if(3 * current <= n && printed.find(3 * current) == printed.end()) {
            std::cout << " " << 3 * current;
            d.push_back(3 * current);
            printed.insert(3 * current);
        }

        if(5 * current <= n && printed.find(5 * current) == printed.end()) {
            std::cout << " " <<  5* current;
            d.push_back(5 * current);
            printed.insert(5 * current);
        }
    }

    return 0;
}