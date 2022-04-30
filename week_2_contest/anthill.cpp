#include <iostream>
#include <vector>
#include <algorithm>

struct ant
{
    size_t time;
    size_t weight;
};


int main() {
    size_t ant_count, weight_limit;
    std::cin >> ant_count >> weight_limit;
    
    size_t min_time = 0;
    size_t max_time = 1;
    size_t time = 0;
    std::vector<ant> ants(ant_count);
    for(size_t i = 0; i < ant_count; ++i){
        std::cin >> ants[i].time >> ants[i].weight;
        time = (weight_limit / ants[i].weight) * ants[i].time + ants[i].time;
        if(time > max_time) {
            max_time = time;
        }
    }

    size_t weight = 0;
    while (min_time < max_time)
    {
        time = min_time + (max_time - min_time) / 2;
        weight = 0;
        for(const ant& a : ants) {
            weight += (time / a.time) * a.weight;
        }

        if(weight < weight_limit){
            min_time = time + 1;
        } else {
            max_time = time;
        }
    }

    weight = 0;
    for(const ant& a : ants) {
        weight += (max_time / a.time) * a.weight;
        if(max_time % a.time > 0) {
            weight += a.weight;
        }
    }
    
    std::cout << weight;
}