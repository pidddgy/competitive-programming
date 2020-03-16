// http://codeforces.com/contest/236/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    
    int uniq = 0;
    set<char> se;
    for(char x: s) {
        if(se.find(x) == se.end()) {
            uniq++;
            se.emplace(x);
        }
    }

    if(uniq % 2 != 0) {
        cout << "IGNORE HIM!" << endl;
    } else {
        cout << "CHAT WITH HER!" << endl;
    }
}
