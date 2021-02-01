// https://dmoj.ca/problem/oly19practice57

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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

int a[maxn];

int b[maxn];
int m[maxn];

int seg[4*maxn];

int n, q;

void upd(int pos, int val) {
    pos += n;
    seg[pos] = val;

    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = max(seg[i*2], seg[i*2+1]);
    }
}

int query(int l, int r) {
    l += n;
    r += n;

    int res = 0;

    while(l <= r) {
        if(l%2 == 1) res = max(res, seg[l++]);
        if(r%2 == 0) res = max(res, seg[r--]);

        l /= 2;
        r /= 2;
    }

    return res;
}

vector<pii> queries[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;

        queries[r].emplace_back(l, i);
    }

    set<int> S;
    int l = 1;
    for(int r = 1; r <= n; r++) {
        while(S.count(a[r])) {
            S.erase(a[l]);
            upd(l, r-l);
            l++;
        }

        S.emplace(a[r]);
        upd(l, r-l+1);

        for(pii q: queries[r]) {
            ans[q.se] = max(query(q.fi, r), r-max(l, q.fi)+1);
        }
    }

    for(int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }
}

/*
6 400 000 000

use two pointer + segtree to kepe track of everything that is outside of two points
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
