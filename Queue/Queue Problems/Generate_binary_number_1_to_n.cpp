/*

Problem: Generate Binary Numbers from 1 to N using Queue

Given a number N, generate all binary numbers from 1 to N in order.

Example:
Input: N = 5
Output: 1 10 11 100 101

🔹 Explanation

We can use a queue to generate binary numbers:

Start by enqueue "1".

For each step:

Dequeue the front element.

Print it.

Enqueue front + "0" and front + "1".

Repeat until N numbers are generated.

This uses the queue in a Breadth-First Search (BFS) style.

*/




#include <iostream>
#include <queue>
using namespace std;

// Function to generate binary numbers from 1 to N
void generateBinary(int N) {
    queue<string> q;
    q.push("1");  // first binary number

    for (int i = 1; i <= N; i++) {
        string curr = q.front();
        q.pop();

        cout << curr << " ";

        // Generate next two numbers
        q.push(curr + "0");
        q.push(curr + "1");
    }
    cout << endl;
}

int main() {
    int N = 10;
    cout << "Binary numbers from 1 to " << N << ":\n";
    generateBinary(N);

    return 0;
}

/*

========== OUTPUT ==========

Binary numbers from 1 to 10:
1 10 11 100 101 110 111 1000 1001 1010

*/
