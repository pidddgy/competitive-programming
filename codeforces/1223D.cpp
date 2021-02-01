// https://codeforces.com/problemset/problem/1223/D

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

const int maxn = 300500;

// int a[maxn];

void solve() {
    int n;
    cin >> n;

    vector<int> first(n+1, 1e10), last(n+1, -1);

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        first[a] = min(first[a], i);
        last[a] = max(last[a], i);
    }
    
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        if(last[i] != -1) v.emplace_back(i);
    }

    int ma = 1;
    int cur = 1;

    for(int i = 0; i < sz(v)-1; i++) {
        if(last[v[i]] < first[v[i+1]]) {
            // cerr << v[i] << " good with " << v[i+1] << endl;
            cur++;
        } else {
            cur = 1;
        }

        ma = max(ma, cur);
    }

    cout << sz(v)-ma << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while(q--) solve();    
}

/*

only consider the numbers we don't move
sets a. b, c

b must be in increasing order

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
