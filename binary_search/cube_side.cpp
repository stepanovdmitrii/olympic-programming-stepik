#include <iostream>

int main() {
    uint64_t N = 0;
    std::cin >> N;
    uint64_t left = 0;
    uint64_t right = 1e6 + 1;
    while (left + 1 < right)
    {
        uint64_t mid = left + (right - left) / 2;
        if (mid * mid * mid > N) {
            right = mid;
        } else {
            left = mid;
        }
    }
    std::cout << left;
    return 0;
}