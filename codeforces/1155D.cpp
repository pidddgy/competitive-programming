// https://codeforces.com/contest/1155/problem/D

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

const int maxn = 300500;
int n, x;

int a[maxn];

int pre[maxn], mul[maxn], suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    // maximum sum subarray ending at i
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        cur += a[i];
        cur = max(0LL, cur);

        pre[i] = cur;
        ans = max(ans, pre[i]);
    }

    for(int i = 1; i <= n; i++) {
        mul[i] = max({mul[i-1], pre[i-1], 0LL}) + a[i]*x;
        ans = max(ans, mul[i]);
    }

    cur = 0;
    for(int i = n; i >= 1; i--) {
        cur += a[i];
        cur = max(0LL, cur);

        ans = max({ans, cur, cur+mul[i-1]});
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
