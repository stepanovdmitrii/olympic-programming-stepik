#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

struct index_value {
    size_t index;
    size_t value;
};

int main() {
    size_t count;
    std::cin >> count;

    std::vector<size_t> data(count, 0);
    std::vector<size_t> left(count, 0);
    std::vector<size_t> right(count, count - 1);
    for(size_t idx = 0; idx < count; ++idx){
        std::cin >> data[idx];
    }

    std::stack<size_t> stack;
    for(size_t idx = 0; idx < count; ++idx) {
        while (false == stack.empty() && data[stack.top()] > data[idx])
        {
            right[stack.top()] = idx - 1;
            stack.pop();
        }
        stack.push(idx);
    }

    while(false == stack.empty()) {
        stack.pop();
    }

    for(size_t idx = 0; idx < count; ++idx) {
        size_t i = count - idx - 1;
        while (false == stack.empty() && data[stack.top()] > data[i])
        {
            left[stack.top()] = i + 1;
            stack.pop();
        }
        stack.push(i);
    }

    size_t result = 0;
    size_t area = 0;
    for(size_t idx = 0; idx < count; ++idx) {
        area = (right[idx] - left[idx] + 1) * data[idx];
        if(area > result) {
            result = area;
        }
    }
    std::cout << result;
    return 0;
}