// https://codeforces.com/contest/1428/problem/C

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

    int n = sz(s);


    int rem = 0;

    stack<int> a, b;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') a.push(i);
        else b.push(i);

        if(sz(a) and sz(b))
        if(b.top() > a.top()) {
            a.pop();
            b.pop();

            rem += 2;
        }
    }

    rem += sz(b)-(sz(b)&1);

    cout << n-rem << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();    
}

/*

just bomb as many A as possible?

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
