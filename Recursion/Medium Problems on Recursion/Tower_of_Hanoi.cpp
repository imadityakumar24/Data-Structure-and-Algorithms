/*

Tower Of Hanoi

Difficulty: MediumAccuracy: 35.23%Submissions: 179K+Points: 4
You are given n disks placed on a starting rod (from), with the smallest disk on top and the largest at the bottom. There are three rods: the starting rod(from), the target rod (to), and an auxiliary rod (aux).
You have to calculate the minimum number of moves required to transfer all n disks from the starting rod to the target rod, following these rules:
      1. Only one disk can be moved at a time.
      2. A disk can only be placed on top of a larger disk or on an empty rod.
Return the minimum number of moves needed to complete the task.

Examples:

Input: n = 2
Output: 3
Explanation: For n = 2, total 3 steps will be taken. Steps are as follows -
move disk 1 from rod 1 to rod 2
move disk 2 from rod 1 to rod 3
move disk 1 from rod 2 to rod 3


Input: n = 3
Output: 7
Explanation: For n = 3, total 7 steps will be taken.Steps are as follows -
move disk 1 from rod 1 to rod 3
move disk 2 from rod 1 to rod 2
move disk 1 from rod 3 to rod 2
move disk 3 from rod 1 to rod 3
move disk 1 from rod 2 to rod 1
move disk 2 from rod 2 to rod 3
move disk 1 from rod 1 to rod 3
Input: n = 0
Output: 0
Explanation: Total 0 steps will be taken.
Constraints:
  0 ≤ n ≤ 20

Expected Complexities
Company Tags
FlipkartMicrosoft
Topic Tags
RecursionAlgorithms

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int count = 0;

    void solve(int n, int from, int to, int aux) {
        if (n == 0) return;

        // Step 1: Move n-1 disks from 'from' to 'aux'
        solve(n - 1, from, aux, to);

        // Step 2: Move the nth disk from 'from' to 'to'
        cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
        count++;

        // Step 3: Move n-1 disks from 'aux' to 'to'
        solve(n - 1, aux, to, from);
    }

public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        count = 0; // reset counter
        solve(n, from, to, aux);
        return count;
    }
};

int main() {
    cout << "\n\n";

    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << endl;

    Solution obj;
    int totalMoves = obj.towerOfHanoi(n, 1, 3, 2);

    cout << "\nTotal moves required: " << totalMoves << endl;
    cout << "Formula check (2^n - 1): " << (int)pow(2, n) - 1 << endl;

    cout << "\n\n";
    return 0;
}


/*

=======  OUTPUT  ======

Enter number of disks: 3
Move disk 1 from rod 1 to rod 3
Move disk 2 from rod 1 to rod 2
Move disk 1 from rod 3 to rod 2
Move disk 3 from rod 1 to rod 3
Move disk 1 from rod 2 to rod 1
Move disk 2 from rod 2 to rod 3
Move disk 1 from rod 1 to rod 3

Total moves required: 7
Formula check (2^n - 1): 7


*/