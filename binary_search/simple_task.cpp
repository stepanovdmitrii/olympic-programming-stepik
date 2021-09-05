#include <iostream>

int main() {
    uint32_t N, x, y;
    std::cin >> N >> x >> y;
    uint32_t fast = x > y ? y : x;
    uint32_t slow = x > y ? x : y;

    uint32_t left = 0;
    uint32_t right = (N - 1) * fast;

    while (left + 1 < right)
    {
        uint32_t t = left + (right - left) / 2;
        uint32_t count = (t / x) + (t / y);
        if(count < N - 1) {
            left = t;
        } else {
            right = t;
        }
    }
    std::cout << right + fast;
    return 0;
}