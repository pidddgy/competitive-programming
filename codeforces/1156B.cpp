// https://codeforces.com/contest/1156/problem/B

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

bool ok(string s) {
    for(int i = 0; i+1 < s.size(); i++) {
        if(abs(s[i]-s[i+1]) == 1) {
            return false;
        }
    }

    return true;
}

void solve() {
    string s;
    cin >> s;

    string evens, odds;
    for(int i = 0; i < s.size(); i++) {
        if((s[i]-'a') % 2 == 0) {
            evens += s[i];
        } else {
            odds += s[i];
        }
    }

    sort(all(evens));
    sort(all(odds));

    if(ok(evens + odds)) {
        cout << evens+odds << endl;
    } else if(ok(odds + evens)) {
        cout << odds+evens << endl;
    } else {
        cout << "No answer" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?