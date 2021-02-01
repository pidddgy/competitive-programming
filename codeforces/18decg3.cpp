#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = (int)1e4+50;

int seg[4*maxn];

void upd(int pos, int val, int ind, int cl, int cr) {
    if(cl > cr) return;

    if(cl == cr) {
        seg[ind] = val;
    } else {
        int cm = (cl+cr)/2;

        if(pos <= cm) {
            upd(pos, val, 2*ind, cl, cm);
        } else {
            upd(pos, val, 2*ind+1, cm+1, cr);
        }

        seg[ind] = max(seg[2*ind], seg[2*ind+1]);
    }
}

// max query
int query(int l, int r, int ind, int cl, int cr) {
    if(l > r) return -1e18;
    if(cl > cr) return -1e18;

    if(l == cl and r == cr) {
        return seg[ind];
    } else {
        int cm = (cl+cr)/2;

        return max(query(l, min(r, cm), 2*ind, cl, cm),
                    query(max(cm+1, l), r, 2*ind+1, cm+1, cr));
    }
}

int n, k;
int a[maxn];
int dp[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // upd(1, 2, 1, 1, 5);
    // upd(2, 3, 1, 1, 5);
    // upd(3, 4, 1, 1, 5);

    // watch(query(1, 2, 1, 1, 5))
    // watch(query(1, 1, 1, 1, 5))
    // watch(query(1,3, 1, 1, 5))

    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        // upd(i, a[i], 1, 1, n);
    }

    for(int i = 1; i <= n; i++) {
        int ma = 0;
        for(int j = i; j >= 1 and i-j+1 <= k; j--) {
            ma = max(ma, a[j]);
            dp[i] = max(dp[i], dp[j-1]+ma*(i-j+1));
        }
    }

    cout << dp[n] << endl;
}

/*

132 877 123

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
