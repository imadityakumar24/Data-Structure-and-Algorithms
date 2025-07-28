#include <iostream>
using namespace std;

// backtracking 
// not allow to use --
// print your name n intergers in decreasing order  using recursion
// am stating from 6 but i'm able to print linearly order 
// output    enter n = 6  =  6 5 4 3 2 1
// time complexity = o(n)
// space complecity = o(n)

void ntimes(int i, int n) { // recursion using stack space 
    if(i > n) {
        return ;
    }
    ntimes(i+1, n);   
    cout << i << " "; 
}

int main() {
    int n;
    cout << "enter n = ";
    cin >> n;
    int i = 1;
    ntimes(i, n);

    return 0;
}


/*

#include <iostream>
using namespace std;

// backtracking 
// not allow to use ++
// print your name n intergers in increasing order  using recursion
// am stating from 6 but i'm able to print linearly order 
// output    enter n = 6  =  1 2 3 4 5 6 
// time complexity = o(n)
// space complecity = o(n)

void ntimes(int i, int n) { // recursion using stack space 
    if(i < 1) {
        return ;
    }
    ntimes(i-1, n);   
    cout << i << " "; 
}

int main() {
    int n;
    cout << "enter n = ";
    cin >> n;
    int i = n;
    ntimes(i, n);

    return 0;
}

*/



/*

// print your name n intergers in decreasing order  using recursion
// time complexity = o(n)
// space complecity = o(n)

#include <iostream>
using namespace std;

void ntimes(int i, int n) { // recursion using stack space 
    if(i > 0)
        return ;
    cout << i << " ";
    ntimes(i-1, n);    
}

int main() {
    int n;
    cout << "enter n = ";
    cin >> n;
    int i = n;
    ntimes(i, n);

    return 0;
}

*/



/*

// print your name n intergers in incresing order  using recursion
// time complexity = o(n)
// space complecity = o(n)

// output = enter n = 5
//          1 2 3 4 5

#include <iostream>
using namespace std;

void ntimes(int i, int n) { // recursion using stack space 
    if(i > n)
        return ;
    cout << i << " ";
    ntimes(i+1, n);    
}

int main() {
    int n;
    cout << "enter n = ";
    cin >> n;
    int i = 1;
    ntimes(i, n);

    return 0;
}

*/






/*

// print your name n times using recursion
// time complexity = o(n)
// space complecity = o(n)

// OUPUT 
// 5
// love you
// love you
// love you
// love you
// love you

#include <iostream>
using namespace std;

void name(int i, int n) { // recursion using stack space 
    if(i > n)
        return ;
    cout << "love you" << endl;
    name(i+1, n);    
}

int main() {
    int n;
    cin >> n;
    int i = 1;
    name(i, n);

    return 0;
}

*/

