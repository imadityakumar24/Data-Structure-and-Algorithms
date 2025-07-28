#include<iostream>
#include <cmath>
using namespace std;

// armstrong numbers are 153, 370, 371, 407

string armstrong(int n) {
    int temp = n;
    int count = 0;
    while(n != 0) {
        int lastdigit = n % 10;
        count++;
        n = n / 10;
    }
    
    n = temp;  // Reset n to its original value
    
    int sum = 0;
    while(n != 0) {
        int digit = n % 10;
        sum = sum + pow(digit, count);
        n = n / 10;
    }
    
    if(sum == temp) 
        return "true";
    else 
        return "false";  
}

int main() {

    string result = armstrong(534);
    cout << result << endl;
    
    return 0;
}