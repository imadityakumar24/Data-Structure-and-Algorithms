
/*
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cout << "enter the string : ";
    getline(cin, s);

    // precalculations // suppose  all charcters are in lower letter
    int hash[26] = {0};
    for(int i = 0; i < s.size(); i++) {
        hash[s[i] -= 'a']++; // indexing
    }

    
    int q;
    cout << "enter q : ";
    cin >> q;
    while(q--) {
        char c;
        cout << "how many time character  is appear in string : ";
        cin >> c;
        cout << hash[c -'a'] << " times in the string" << endl;
    }

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cout << "enter the string : ";
    getline(cin, s);

    // precalculations // suppose  all charcters are in lower letter
    int hash[256] = {0};
    for(int i = 0; i < s.size(); i++) {
        hash[s[i]]++; // indexing
    }

    
    int q;
    cout << "enter q : ";
    cin >> q;
    while(q--) {
        char c;
        cout << "how many time character  is appear in string : ";
        cin >> c;
        cout << hash[c] << " times in the string" << endl;
    }

    return 0;
}

*/



/*
 // integers hasing 

// number hasing 
// inside main the max size of int array is 10topower6 or 1e6
// outside main globaly the max size of int array is 10topower7 or 1e7

#include <bits/stdc++.h>
using namespace std;

int main() {

    int size;
    cout << "enter the size of array : ";
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // precalculations 
    int hashArray[size] = {0};
    for(int i = 0; i < size; i++) {
        hashArray[arr[i]] += 1;
    }

    int q; // this is for how many times you want to check number is appera
    cout << "enter q : ";
    cin >> q;
    while(q--) {
        int number;
        cout << "how many time number is appear in array : ";
        cin >> number;
        // fetching of number in hash array
        cout << hashArray[number] << " times this number is appear in array "<< endl;
    }

    return 0;
}

*/


#include <bits/stdc++.h>
using namespace std;

int main() {

    int size;
    cout << "enter the size of array : ";
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // precalculations 
    int hashArray[size] = {0};
    for(int i = 0; i < size; i++) {
        hashArray[arr[i]] += 1;
    }

// prointing the frequency of all numbers
    cout << endl;
    for(int i = 0; i < size; i++) {
       // cout << hashArray[i] << " ";
        cout << i << " is apearing " << hashArray[i] << " times " << endl;
    }

    return 0;
}



