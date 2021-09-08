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
    if (data.size() < 2) {
        std::cout << data.size();
        return 0;
    }

    uint64_t counter = 0;
    size_t left = 0;
    size_t right = data.size() - 1;
    while (left <= right)
    {
        if(left == right) {
            ++counter;
            break;
        }
        if(data[left] + data[right] <= D){
            ++left;
            --right;
            counter = counter + 1;
        } else {
            counter = counter + 1;
            --right;
        }
    }
    
    std::cout << counter;
    return 0;
}