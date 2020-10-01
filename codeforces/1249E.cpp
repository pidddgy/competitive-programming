// https://codeforces.com/contest/1249/problem/E

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

int a[maxn], b[maxn];

// dp[0] = stairs, dp[1] = elevator
int dp[maxn][2];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    for(int i = 2; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 2; i <= n; i++) {
        cin >> b[i];
    }

    dp[1][1] = INT_MAX;

    for(int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i];
        dp[i][1] = min(dp[i-1][1], dp[i-1][0] + c) + b[i];
    }    

    for(int i = 1; i <= n; i++) {
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
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
