#include <iostream>
#include <vector>

int32_t binary_search(const std::vector<uint32_t>& source, uint32_t target) {
    int32_t left = 0;
    int32_t right = source.size() - 1;
    int32_t middle = -1;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (source[middle] == target) {
            return middle;
        }
        if (source[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

int main() {
    size_t count = 0;
    uint_fast32_t value = 0;

    std::cin >> count;
    std::vector<uint32_t> source(count, 0);
    for(size_t i = 0; i < count; ++i) {
        std::cin >> source[i];
    }

    std::cin >> count;
    std::vector<uint32_t> target(count, 0);
    for(size_t i = 0; i < count; ++i) {
        std::cin >> target[i];
    }

    for(auto it = target.begin(); it != target.end(); ++it){
        int32_t idx = binary_search(source, *it);
        if (idx == -1) {
            std::cout << 0 << " ";
        } else {
            std::cout << idx  + 1 << " ";
        }
    }

    return 0;
}