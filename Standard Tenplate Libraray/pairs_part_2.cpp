#include <vector>
#include <iostream>
#include <algorithm> // for std::all_of

int main() {
    // Create a vector of 4 pairs with (0, 0)
    std::vector<std::pair<int, int>> vec(4, std::make_pair(0, 0));

    // Use std::all_of to check if all pairs have (0, 0)
    bool allZeroes = std::all_of(vec.begin(), vec.end(), [](const std::pair<int, int>& p) {
        return p.first == 0 && p.second == 0;
    });

    // Output the result
    if (allZeroes) {
        std::cout << "All pairs have (0, 0)\n";
    } else {
        std::cout << "Not all pairs have (0, 0)\n";
    }

    return 0;
}
