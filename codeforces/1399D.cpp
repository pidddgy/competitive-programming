// https://codeforces.com/contest/1399/problem/D

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
    int n;
    cin >> n;

    // int a[n+1], ans[n+1];
    vector<int> a(n+1);
    vector<int> ans(n+1);
    // for(int)

    string s;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        // cin >> a[i];
        a[i] = s[i-1]-'0';
    }

    set<int> S[2];
    int cur = 0;

    for(int i = 1; i <= n; i++) {
        if(S[a[i]^1].empty()) {
            cur++;
            S[a[i]^1].emplace(cur);
        }

        int hugs = *S[a[i]^1].begin();
        ans[i] = hugs;

        S[a[i]^1].erase(hugs);
        S[a[i]].emplace(hugs);
    }

    cout << cur << endl;
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
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
