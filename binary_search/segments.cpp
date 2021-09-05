#include <iostream>
#include <vector>

uint32_t get_count(const std::vector<uint32_t>& segments, uint32_t length) {
    uint32_t result = 0;
    for(size_t idx = 0; idx < segments.size(); ++idx){
        result += segments[idx] / length;
    }
    return result;
}

uint32_t get_max(const std::vector<uint32_t>& segments, uint32_t length) {
    uint32_t result = 0;
    for(size_t idx = 0; idx < segments.size(); ++idx){
        result += segments[idx];
    }
    return (result / length) + 1;
}

int main() {
    size_t count = 0;
    uint32_t target = 0;
    std::cin >> count >> target;
    std::vector<uint32_t> segments(count, 0);
    for(size_t i = 0; i < count; ++i){
        std::cin >> segments[i];
    }

    uint32_t left = 0;
    uint32_t right = get_max(segments, target);
    uint32_t middle = 0;

    while (left + 1 < right)
    {
        middle = left + (right - left) / 2;
        if(get_count(segments, middle) >= target) {
            left = middle;
        } else {
            right = middle;
        }
    }
    std::cout << left;

    return 0;
}