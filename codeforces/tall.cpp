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

const int maxn = 2500;
    int n;

int ans = 1e18;
int a[maxn];
int b[maxn];

int go(int x) {
    for(int i = 1; i <= n; i++) {
        b[i] = a[i]^x;
    }

    sort(b+1, b+n+1);

    int mex = 0;
    for(int i = 1; i <= n; i++) {
        if(b[i] == mex) mex++;
    }
    return mex;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    pii shit = {0, 0};
    for(int i = 1; i <= n; i++) {
        // ans = min(ans, go(a[i]));
        shit = max(shit, {go(a[i]), -a[i]});
    }

    // cout << ans << endl;
    cout << shit.fi << " " << -shit.se << endl;
}

/*

bound: answer must be <= 2001

[i][j] = can i use i to make j


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
