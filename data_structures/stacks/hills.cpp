#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main()
{
    std::size_t count;
    std::cin >> count;
    std::size_t result = count - 1; //соседние всегда видны
    std::vector<size_t> hills(count, 0);
    std::stack<size_t> stack;

    for (size_t idx = 0; idx < count; ++idx)
    {
        std::cin >> hills[idx];
    }

    for (size_t idx = 0; idx < hills.size(); ++idx)
    {
        while (false == stack.empty() && hills[idx] > stack.top())
        {
            result++;
            stack.pop();
        }
        stack.push(hills[idx]);
    }
    std::cout << result;
    return 0;
}