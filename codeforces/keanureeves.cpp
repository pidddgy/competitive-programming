// http://codeforces.com/contest/1189/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    int one = 0;
    int zero = 0;

    for(char chr: s) {
        if(chr == '0') zero++;
        else one++;
    }   

    if(one == zero) {
        cout << 2 << endl;
        for(int i = 0; i < s.size()-1; i++) {
            cout << s[i];
        }

        cout << " " << s.back();
    } else {
        cout << 1 << endl;
        for(int i = 0; i < s.size(); i++) {
            cout << s[i];
        }
    }

    cout << endl;
}