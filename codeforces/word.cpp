// http://codeforces.com/contest/59/problem/A

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    string s;
    cin >> s;

    int u = 0;
    int l = 0;

    for(char x: s) {
        if(isupper(x)) u++;
        else l++;
    }

    if(u > l) {
        for(char x: s) {
            cout << (char)toupper(x);
        }
    } else {
        for(char x: s) {
            cout << (char)tolower(x);
        }
    }
    
    cout << "\n";
}
