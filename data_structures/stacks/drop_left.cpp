#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int main() {
    size_t count;
    std::cin >> count;
    
    std::stack<size_t> stack;
    
    size_t s = 0;
    size_t deleted = 0;
    for(size_t k = 0; k < count; ++k){
        std::cin >> s;
        stack.push(s);
    }
    size_t result = 0;
    while (stack.size() > 0){
        size_t to_drop = stack.top();
        stack.pop();
        ++result;
        while (to_drop > 0 && stack.size() > 0)
        {
            --to_drop;
            if(stack.top() > to_drop) {
                to_drop = stack.top();
            } 
            stack.pop();
        }
    }

    std::cout << result;
}