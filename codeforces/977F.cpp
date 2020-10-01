// https://codeforces.com/problemset/problem/977/F

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

const int maxn = 200500;
int n;

// mi[i] = min tail element for sequence i long
int mi[maxn];
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) mi[i] = INT_MAX;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }    

    map<int, int> dp;
    int lst = 0;
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        dp[a[i]] = max(dp[a[i]], dp[a[i]-1]+1);
        if(dp[a[i]] > ans) {
            ans = dp[a[i]];
            lst = a[i];
        }
    }

    cout << ans << endl;
    vector<int> v;
    for(int i = n; i >= 1; i--) {
        if(a[i] == lst) {
            // cout << i << " ";
            v.emplace_back(i);
            lst = a[i]-1;
        }
    }

    reverse(v.begin(), v.end());

    for(int x: v) cout << x << " ";
    cout << endl;
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
