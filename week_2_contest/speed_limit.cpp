#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    size_t fine_table_size, cars_count, speed_limit;
    double distance;
    std::cin >> fine_table_size >> cars_count >> distance >> speed_limit;
    
    std::vector<double> limits(fine_table_size - 1);
    for(size_t i = 0; i < fine_table_size - 1; ++i) {
        std::cin >> limits[i];
    }
    
    std::vector<size_t> fines(fine_table_size);
    for(size_t i = 0; i < fine_table_size; ++i) {
        std::cin >> fines[i];
    }

    double time;
    double speed;
    size_t fine;
    for(size_t i = 0; i < cars_count; ++i) {
        std::cin >> time;
        speed = distance / time;

        if(speed <= speed_limit) {
            std::cout << 0 << " ";
            continue;
        }

        speed = speed - speed_limit;
        auto it = std::lower_bound(limits.begin(), limits.end(), speed);
        size_t fine_idx = std::distance(limits.begin(), it);
        std::cout << fines[fine_idx] << " ";
    }
}