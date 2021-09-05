#include <iostream>

int main() {
    uint64_t N;
    std::cin >> N;
    uint64_t left = 0;
    uint64_t right = 1e18;
    while(left < right - 1) {
        uint64_t mid = left + (right - left) / 2;
        uint64_t valid = mid - (mid / 13) - (mid / 17) + (mid / 221);
        if (valid < N) {
            left = mid;
        } else {
            right = mid;
        }
    }
    std::cout << right;
    return 0;
}