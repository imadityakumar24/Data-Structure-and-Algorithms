#include <vector>
#include <iostream>
#include <algorithm> // for std::fill

int main() {
    // Create a vector of 4 pairs
    std::vector<std::pair<int, int>> vec(4);

    // Use std::fill to fill all pairs with (0, 0)
    std::fill(vec.begin(), vec.end(), std::make_pair(0, 0));

    // Output the vector to check if values are set correctly
    for (const auto& p : vec) {
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
