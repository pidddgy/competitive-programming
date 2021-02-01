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

const int maxn = 2005000;

int n;
int p[maxn];
int a[maxn];
int seg[4*maxn];
int lazy[4*maxn];

void push(int v) {
    // cerr << "pushing " << v << endl;

    seg[v*2] += lazy[v];
    seg[v*2+1] += lazy[v];
    lazy[v*2] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void upd(int l, int r, int add, int tl, int tr, int ind) {
    if(l > r) return;

    if(l == tl and r == tr) {
        seg[ind] += add;
        lazy[ind] += add;
    } else {
        push(ind);
        int tm = (tl+tr)/2;

        upd(l, min(tm, r), add, tl, tm, 2*ind);
        upd(max(l, tm+1), r, add, tm+1, tr, 2*ind+1);

        seg[ind] = min(seg[2*ind], seg[2*ind+1]);
    }
}

int query(int l, int r, int tl, int tr, int ind) {
    if(l > r) return 1e18;

    if(l <= tl and tr <= r) return seg[ind];

    push(ind);

    int tm = (tl+tr)/2;

    return min(query(l, min(tm, r), tl, tm, 2*ind), query(max(tm+1, r), r, tm+1, tr, 2*ind+1));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    int tot = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    // push all to seg
    for(int i = 1; i <= n; i++) {
        // if we choose an x >= p[i] incur cost because we have to move it
        upd(p[i], n, a[i], 1, n, 1);
    }

    int ans = a[1];
    for(int i = 1; i <= n-1; i++) {
        // since p[i] is now on the left side, if !(x >= p[i]) we incur cost a[i]
        upd(1, p[i]-1, a[i], 1, n, 1);

        // if we choose x >= p[i] its free
        upd(p[i], n, -a[i], 1, n, 1);

        ans = min(ans, query(1, n, 1, n, 1));
    }

    cout << ans << endl;
}

/*

start at index i

max(1) < min(2)
on the left side, add a[i] of all indexes with element > i
on the right side, add a[i] of all indexes with element <= i



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
