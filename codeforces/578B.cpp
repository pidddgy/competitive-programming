// https://codeforces.com/contest/578/problem/B

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

int a[maxn], pref[maxn], suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, x;
    cin >> n >> k >> x;
    int mult =1 ;
    for(int i = 1; i <= k; i++) mult *= x;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] | a[i];
    }

    for(int i = n; i >= 1; i--) {
        suf[i] = suf[i+1] | a[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, pref[i-1] | a[i]*mult | suf[i+1]);
    }

    cout << ans << endl;
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
