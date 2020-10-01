// https://codeforces.com/contest/343/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<char> a;
    for(int i = 0; i < s.size(); i++) {
        if(a.size()) {
            if(a.back() == s[i]) {
                a.pop_back();
                continue;
            }
        }

        a.push_back(s[i]);
    }

    if(a.size()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}