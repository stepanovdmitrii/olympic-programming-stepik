#include <iostream>
#include <vector>
#include <algorithm>

struct ant
{
    size_t time;
    size_t weight;
};


int main() {
    size_t tree_count, distance;
    std::cin >> tree_count >> distance;
    
    std::vector<size_t> distances(tree_count, 0);
    size_t current_distance = 0;
    for(size_t i = 1; i < tree_count; ++i){
        std::cin >> current_distance;
        distances[i] = distances[i - 1] + current_distance;
    }

    auto right = std::lower_bound(distances.begin(), distances.end(), distance);
    if(right == distances.end()){
        std::cerr << "undefined";
        return -1;
    }
    auto left = distances.begin();

    while (left <= right && right != distances.end() && left != distances.end())
    {
        current_distance = *right - *left;
        if(current_distance == distance){
            break;
        }

        if(current_distance > distance) {
            ++left;
        } else {
            ++right;
        }
    }

    std::cout << std::distance(distances.begin(), left) + 1 << " " << std::distance(distances.begin(), right) + 1;   
}