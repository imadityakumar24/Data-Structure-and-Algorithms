// stack
// LIFO  last in first out 
// FILO first in last out 
// push == insertion and pop ==  deletion  and see the top element
// recursion in implemented internalay using stack
// Time Complexity : O(1) 


#include <iostream>
#include <Stack>
using namespace std;

int main() {

    stack <int> s;
    s.push(3);
    s.push(8);
    s.push(6);  
    s.push(2);

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    while(!s.empty()) {
        cout << s.top() <<" empty" << endl;
    }

    cout << "empty" << endl;
    return 0;
}