// check parenthesis matchings
// (((())))  // question is this string is showing balanced parenthesis or not  // true // (( ) false
// in  last our stack should bhi empty means all parenthesis are balanced


#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> symbols={ {'[', -1}, {'(', -2}, {'{', -3}, {']', 1}, {')', 2}, {'}', 3} };

string isBalanced(string s){
    stack <char> st;
    for(char bracket : s) {
        if(symbols[bracket] < 0){
            st.push(bracket);
        } 
        else {
            if(st.empty()) {
                return "N0";
            }
            char top = st.top();
            st.pop();
            if(symbols[top] + symbols[bracket] != 0) {
                return "NO";
            }
        }
    }
    if(st.empty()) {
        return "YES";
    } 
    else {
        return "NO";
    }
}

int main() {

    int t; 
    cout << " enter t :";
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }

    return 0;
}