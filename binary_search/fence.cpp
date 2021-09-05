#include <iostream>
#include <vector>

bool is_possible(const std::vector<uint64_t>& fence, int64_t available, uint64_t target){
    for(size_t i = 0; i < fence.size(); ++i){
        if(fence[i] < target) {
            available = available - (target - fence[i]);
            if (available < 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    size_t count = 0;
    std::cin >> count;
    std::vector<uint64_t> fence(count, 0);
    uint64_t left = UINT64_MAX;
    uint64_t right = 0;
    for(size_t i = 0; i < count; ++i){
        std::cin >> fence[i];
        if(fence[i] < left) {
            left = fence[i];
        }
        if (fence[i] > right) {
            right = fence[i];
        }
    }
    int64_t m;
    std::cin >> m;
    right = right + m;
    while (left + 1 < right)
    {
        uint64_t target = left + (right - left) / 2;
        if(is_possible(fence, m, target)){
            left = target;
        } else {
            right = target;
        }
    }
    std::cout << left;

    return 0;
}