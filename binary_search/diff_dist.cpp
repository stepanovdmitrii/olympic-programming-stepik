#include <iostream>
#include <vector>

int main() {
    size_t N;
    uint64_t D;
    std::cin >> N >> D;
    std::vector<uint64_t> data (N, 0);
    data[0] = 0;
    for(size_t i = 0; i < N - 1; ++i) {
        std::cin >> data[i+1];
        data[i+1] = data[i+1] + data[i];
    }

    uint64_t counter = 0;
    size_t left = 0;
    size_t right = 1;
    while (left < data.size() && right < data.size())
    {
        if(data[right] - data[left] < D) {
            ++right;
        } else {
            counter = counter + data.size() - right;
            ++left;
            if(left == right) {
                ++right;
            }
        }
    }
    
    std::cout << counter;
    return 0;
}