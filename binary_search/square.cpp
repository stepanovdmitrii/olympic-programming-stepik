#include <iostream>

int main() {
    uint32_t a = 0;
    std::cin >> a;
    uint32_t left = 1;
    uint32_t right = a;
    uint32_t value = left;
    while (left + 1 < right)
    {
        value = left + (right - left) / 2;
        if(value * value > a) {
            right = value;
        } else {
            left = value;
        }
    }
    std::cout << left;
    return 0;
}