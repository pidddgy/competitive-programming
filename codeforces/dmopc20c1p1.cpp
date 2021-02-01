// https://dmoj.ca/problem/dmopc20c1p1

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    string s;
    cin >> s;

    set<char> S;

    for(char x: s) {
        S.emplace(x);
    }

    if(S.count('M') and S.count('C')) {
        cout << "NEGATIVE MARKS" << endl;
    } else if(S.count('M') or S.count('C')) {
        cout << "FAIL" << endl;
    } else {
        cout << "PASS" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
