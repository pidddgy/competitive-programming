// https://codeforces.com/contest/1241/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q;
    cin >> Q;

    while(Q--) {
        string s, t;
        cin >> s >> t;

        bool found = false;
        for(int i = 0; i < s.size(); i++) {
            for(int j = 0; j < t.size(); j++) {
                if(s[i] == t[j]) {
                    found = true;
                }
            }
        }

        if(found) { 
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}