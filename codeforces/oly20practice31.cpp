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

const int maxn = 2e6+500;

// .fi = s, .se = v
vector<pii> shit[maxn];
int seg[3*maxn];

// answer for prefix
int dp[maxn];

// iterative segtree implementation

void upd(int pos, int val) {
    pos += 2e6+1;
    seg[pos] = val;

    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = max(seg[i*2], seg[i*2+1]);
    }
}

int query(int l, int r) {
    l += 2e6+1, r += 2e6+1;
    int res = 0;

    while(l <= r) {
        if (l%2 == 1) res = max(res, seg[l++]);
        if (r%2 == 0) res = max(res, seg[r--]);
        l /= 2; r /= 2;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    for(int i = 1; i <= m; i++) {
        int s, e, v;
        cin >> s >> e >> v;

        s++;
        e++;

        e += r;

        shit[e].emplace_back(s, v);
    }

    for(int i = 1; i <= 2e6+1; i++) {
        dp[i] = max(dp[i], dp[i-1]);

        for(pii p: shit[i]) {
            dp[i] = max(dp[i], p.se+query(1, p.fi));
        }

        upd(i, dp[i]);
    }

    cout << dp[(int)2e6+1] << endl;
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
