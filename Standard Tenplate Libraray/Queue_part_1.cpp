// queue
// LILO  last in last out 
// FIFO first in first out 
// push == insertion in end and pop ==  deletion in first  
// front means see the first value
// it is used in graphs 
// enqueue and dequeue
// it is used in graph


#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue <string> q;
    q.push("aditya");
    q.push("tamanna");
    q.push("shambhavi");
    q.push("neelanjana");
    q.push("nakshatra");

    
    while(!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    
    return 0;
}