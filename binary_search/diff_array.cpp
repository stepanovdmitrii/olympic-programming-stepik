#include <iostream>
#include <vector>

int main() {
    size_t N;
    uint64_t D;
    std::cin >> N >> D;
    std::vector<uint64_t> data (N, 0);
    for(size_t i = 0; i < N; ++i) {
        std::cin >> data[i];
    }
    uint64_t counter = 0;
    for(size_t left = 0, right = 0; left < data.size() && right < data.size(); ) {
        if(data[right] - data[left] >= D) {
            counter = counter + data.size() - right;
            ++left;
        } else {
            ++right;
        }
    }
    std::cout << counter;
    return 0;
}