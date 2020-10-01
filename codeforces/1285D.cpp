// https://codeforces.com/contest/1285/problem/D

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

int solve(vector<int> v, int bit) {
    if(bit < 0) return 0;

    vector<int> a, b;
    for(int x: v) {
        if(x & (1LL << bit)) {
            a.emplace_back(x);
        } else {
            b.emplace_back(x);
        }
    }

    if(a.empty()) return solve(b, bit-1);
    else if(b.empty()) return solve(a, bit-1);
    else {
        return min(solve(a, bit-1), solve(b, bit-1)) + (1LL << bit);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;


    vector<int> a;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        a.emplace_back(x);
    }

    cout << solve(a, 32LL) << endl;
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
