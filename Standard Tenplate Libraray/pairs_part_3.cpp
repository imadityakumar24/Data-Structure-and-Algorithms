
#include <vector>
#include <iostream>
#include <algorithm> // for std::any_of

int main() {
    // Vector of pairs
    std::vector<std::pair<int, int>> vec = {{0, 0}, {1, 0}, {0, 2}, {3, 4}};

    // Check if any pair has both first and second non-zero
    bool hasNonZeroPair = std::any_of(vec.begin(), vec.end(), [](const std::pair<int, int>& p) {
        return p.first != 0 && p.second != 0;
    });

    // Output the result
    if (hasNonZeroPair) {
        std::cout << "At least one pair has non-zero values at both positions.\n";
    } else {
        std::cout << "No pair has non-zero values at both positions.\n";
    }

    return 0;
}
