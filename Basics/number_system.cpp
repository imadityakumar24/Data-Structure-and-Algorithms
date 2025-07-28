// leet code problem 2427 common facoter return sum of how many number divided a and b

#include <bits/stdc++.h>
using namespace std;


int commonFactor(int a, int b) {
    int count = 0;
    int limit  = (a < b)? a: b;
    for(int i = 1; i <= limit; i++) {
        if(a % i == 0 && b % i == 0){
            count = count + 1;
        }
    }
    return count;
}

int main() {

    int a;
    cout << "Enter a : ";
    cin >> a;
    int b;
    cout << "Enter b : ";
    cin >> b;

    int result = commonFactor(a, b);
    cout << result;


    return 0;
}



/* // rseturn single dogit

int addDigits(int n) {
    if(n <= 9) {
        return n;
    }
    int temp = n;
    int sum = 0;
    while(temp != 0) {
        n = temp;
        n = n % 10;
        sum = sum + n;
        temp = temp / 10;
    }
    n = sum;
    addDigits(n);
}

int main() {

    int n;
    cout << "Enter n : ";
    cin >> n;

    int result = addDigits(n);
    cout << result;


    return 0;
}

*/