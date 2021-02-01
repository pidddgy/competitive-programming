// https://dmoj.ca/problem/oly20practice118

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

const int maxn = 1000500;

int n;
int a[maxn];
int pre[maxn], suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1]+a[i];
    }

    for(int i = n; i >= 1; i--) {
        suf[i] = suf[i+1]+a[i];
    }

    int ans = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, abs(pre[i] - suf[i+1]));
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
