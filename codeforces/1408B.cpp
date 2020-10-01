// https://codeforces.com/contest/1408/problem/B

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
    int n, k;
    cin >> n >> k;

    set<int> S;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        S.emplace(x);
    }

    if(k == 1) {
        if(sz(S) == 1) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }

        return;
    }

    int ans = 1;
    while(sz(S) > k) {
        int rem = k;
        if(S.count(0)) rem--; // we need to use one element to keep the 0s

        for(int i = 1; i <= rem; i++) {
            S.erase(S.upper_bound(0));
        }

        if(!S.count(0)) {
            S.emplace(0);
        }
        ans++;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();    
}

/*

the fact that it is non decreasing probably matters a lot

at each step take the minimum element 

for every array we can remove k from distinct values
add one distinct value if there wasn't a 0

edge case: if k = 1 and there's more than one distinct value

if k is greater than 1 we can always do it given enough arrays because we can use 0s
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
