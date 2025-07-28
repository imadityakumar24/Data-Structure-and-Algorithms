#include <bits/stdc++.h>
using namespace std;
   /*
bool pallidrome(string s)
{
    string character;
    int i = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        int asciivalue = static_cast<int>(s[i]);
        if (asciivalue >= 97 || asciivalue <= 122 || asciivalue >= 65 || asciivalue <= 90)
        {
            if (asciivalue >= 97 || asciivalue <= 122)
            {
                character = s[i];
            }
            else
            {
                asciivalue + 32;
                char ch = static_cast<char>(asciivalue);
                character = ch;
            }
        }
    }

    for (i = 0; i < character.size() - 1; i++)
    {
        cout << character[i];
    }
}

*/

/*

int main()
{

    string s;
    cout << "Enter string : ";
    getline(cin, s);

    int count = 0;
    for (int i = 0; i < s.size()-1; i++) {
       // cout << s[i];
        count++;
    }
    cout << "count = " << count << endl;
    cout << "s size = " << s.size() << endl;

    cout << endl;

    string character[count];
    // cout << sizeof(string) << endl;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int asciivalue = static_cast<int>(s[i]);
        if ( asciivalue >= 97 && asciivalue <= 122 || asciivalue >= 65 && asciivalue <= 90)
        {
            if (asciivalue >= 97 && asciivalue <= 122)
            {
                character[i] = s[i];
               // cout << character[i];
            }
            else
            {
                asciivalue = asciivalue + 32;
                char ch = static_cast<char>(asciivalue);
                character[i] = ch;
              //  character[i];
            }
        }
    }


    for (int i = 0; character[i] != '\0'; i++) {
        cout << character[i];
    }


    
    return 0;
}

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        // cout << s[i];
        count++;
    }
    cout << "count = " << count << endl;
    cout << "s size = " << s.size() << endl;

    cout << endl;

    string copy = s;

    vector<char> character;  // Use a vector to store characters dynamically

    for (int i = 0; s[i] != '\0'; i++)
    {
        int asciivalue = static_cast<int>(s[i]);
        if ( (asciivalue >= 97 && asciivalue <= 122) || (asciivalue >= 65 && asciivalue <= 90) )
        {
            if (asciivalue >= 97 && asciivalue <= 122)
            {
                character.push_back(s[i]);
            }
            else
            {
                asciivalue = asciivalue + 32;
                char ch = static_cast<char>(asciivalue);
                character.push_back(ch);
            }
        }
    }

    string copy_values(character.begin(), character.end()); // new vector is copying the character 1 data
    
    if(copy == copy_values) 
        return 1;
    else
        return 0;    

    

    return 0;
}
