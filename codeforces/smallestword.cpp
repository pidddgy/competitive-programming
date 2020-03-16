// https://codeforces.com/contest/1043/problem/C

#include <bits/stdc++.h>
using namespace std;

bool flip[5000];
int main() {
    string s;
    cin >> s;

    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 'a') {
            flip[i-1] = !flip[i-1];
            flip[i] = true;
        }
    }

    for(int i = 0; i < s.size(); i++) {
        cout << flip[i] << " ";
    }
    cout << endl;

}