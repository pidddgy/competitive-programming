// https://codeforces.com/contest/1179/problem/B

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
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n/2; i++) {
        for(int j = 1; j <= m; j++) {
            cout << i << " " << j << endl;
            cout << n-i+1 << " " << m-j+1 << endl;
        }
    }

    if(n&1) {
        for(int j = 1; j <= m/2; j++) {
            cout << n/2+1 << " " << j << endl;
            cout << n/2+1 << " " << m-j+1 << endl;
        }

        if(m&1) {
            cout << n/2+1 << " " << m/2+1 << endl;
        }
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
