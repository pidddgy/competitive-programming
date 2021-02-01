// https://cses.fi/problemset/task/1090

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

    int n, x;
    cin >> n >> x;
    multiset<int> S;

    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p;

        S.emplace(p);
    }

    int ans = 0;
    while(sz(S)) {
        ans++;
        int take = *S.begin();
        S.erase(S.begin());
        int rem = x-take;

        if(S.empty()) {
            break;
        }

        auto other = S.upper_bound(rem);
        if(other != S.begin()) {
            other--;
            S.erase(other);
        }
    }

    cout << ans << endl;
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
