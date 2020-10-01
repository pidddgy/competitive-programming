// https://codeforces.com/contest/269/problem/B

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pldi pair<ld, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 5500;

int type[maxn], dp[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        ld x;
        cin >> type[i] >> x;
    }

    for(int i = 1; i <= n; i++) {
        int x = type[i];
        for(int j = x; j >= 1; j--) {
            dp[x] = max(dp[x], dp[j]+1);
        }
    }

    int ma = 0;
    for(int i = 1; i <= m; i++) {
        ma = max(ma, dp[i]);
    }

    cout << n-ma << endl;
}

/*
coordinate compress
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
