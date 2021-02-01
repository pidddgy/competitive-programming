// https://cses.fi/problemset/task/1091

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
    multiset<int> S;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        S.emplace(x);
    }

    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        auto ptr = S.upper_bound(x);

        if(ptr != S.begin()) {
            ptr--;
            cout << *ptr << endl;
            S.erase(ptr);
        } else {
            cout << -1 << endl;
        }
    }
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
