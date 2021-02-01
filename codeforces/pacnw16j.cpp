// https://dmoj.ca/problem/pacnw16j

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

int n, q;
int a[maxn];
int seg[maxn*3];

void upd(int pos, int val) {
    pos += n;

    seg[pos] = val;
    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = min(seg[2*i], seg[2*i+1]);
    }
}

int query(int l, int r) {
    int ans = LLONG_MAX;
    l += n;
    r += n;
    while(l <= r) {
        if(l%2 == 1) ans = min(ans, seg[l++]);
        if(r%2 == 0) ans = min(ans, seg[r--]);

        l /= 2;
        r /= 2;
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(i, a[i]);
    }

    while(q--) {
        int v, ql, qr;
        cin >> v >> ql >> qr;

        int cur = ql;
        int d = v%(a[ql]);

        while(cur < qr and d) {
            int l = cur+1;
            int r = qr;
            int lgood = -1;
            while(l <= r) {
                int mid = (l+r)/2;

                if(query(cur+1, mid) <= d) {
                    lgood = mid;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }

            if(lgood == -1) break;
            cur = lgood;
            d %= a[lgood];
        }

        cout << d << endl;
    }


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
