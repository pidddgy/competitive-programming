// https://codeforces.com/contest/845/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

vector<string> arr;
void f(string s = "") {
    if(s.size() == 6) {
        if((s[0]-'0' + s[1]-'0' + s[2]-'0') == s[3]-'0' + s[4]-'0' + s[5]-'0') {
            arr.emplace_back(s);
        }
        return;
    }

    for(char x: "1234567890") {
        f(s+x);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    f();

    for(string x: arr) {
        // cerr << x << endl;
    }

    string s;
    cin >> s;

    int ans = INT_MAX;
    for(string x: arr) {
        int edit = 0;
        for(int i = 0; i < 6; i++) {
            if(x[i] != s[i]) {
                edit++;
            }
        }
        ans = min(ans, edit);
    }
    cout << ans << endl;
}