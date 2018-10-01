#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool isAnagram = true;
    string upperCaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string A;
    string B;

    getline(cin, A);
    getline(cin, B);
    
    for(char& letter: upperCaseLetters)
    {
        if(count(A.begin(), A.end(), letter) != count(B.begin(), B.end(), letter))
        {
            isAnagram = false;
            break;
        }
    }

    if(isAnagram)
    {
        cout << "Is an anagram." << "\n";
    } else {
        cout << "Is not an anagram." << "\n";
    }
    return 0;
}
