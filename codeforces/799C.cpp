// https://codeforces.com/contest/799/problem/C

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

const int maxn = 100500;
int n, c, d;

int b[maxn], p[maxn];
char type[maxn];

int mac[maxn], mad[maxn];

int seg[3*maxn];

void upd(int pos, int val) {
    pos += 1e5;
    seg[pos] = val;

    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = max(seg[i*2], seg[i*2+1]);
    }
}

int query(int l, int r) {
    l += 1e5;
    r += 1e5;

    int res = 0;

    while(l <= r) {
        if(l%2 == 1) res = max(res, seg[l++]);
        if(r%2 == 0) res = max(res, seg[r--]);

        l /= 2;
        r /= 2;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c >> d;

    for(int i = 1; i <= n; i++) {
        cin >> b[i] >> p[i];
        cin >> type[i];

        if(type[i] == 'C') {
            mac[p[i]] = max(mac[p[i]], b[i]);
        } else {
            mad[p[i]] = max(mad[p[i]], b[i]);
        }
    }

    for(int i = 1; i <= 1e5; i++) {
        mac[i] = max(mac[i], mac[i-1]);
        mad[i] = max(mad[i], mad[i-1]);
    }

    int ans = 0;

    if(mac[c] != 0 and mad[d] != 0)
        ans = mac[c] + mad[d];

    cerr << "c" << endl;
    for(int i = 1; i <= n; i++) {
        watch(i)
        if(type[i] == 'C') {
            if(c-p[i] >= 1 and query(1, c-p[i]) != 0) {
                watch( b[i]+query(1, c-p[i]))
                ans = max(ans, b[i]+query(1, c-p[i]));
            }

            if(b[i] > query(p[i], p[i])) {
                cerr << "update " << p[i] << " with " << b[i] << endl;
                upd(p[i], b[i]);
            }
        }
    }

    for(int i = 1; i <= 1e5; i++) {
        upd(i, 0);
    }

    for(int i = 1; i <= n; i++) {
        watch(i)
        if(type[i] == 'D') {
            cerr << "query from 1 to " << d-p[i] << endl;
            watch(query(1, d-p[i]))
            if(d-p[i] >= 1 and query(1, d-p[i]) != 0) {
                watch(b[i]+query(1, d-p[i]))
                watch(d-p[i])
                ans = max(ans, b[i]+query(1, d-p[i]));
            }
            if(b[i] > query(p[i], p[i])) {
                cerr << "updating " << p[i] << " with " << b[i] << endl;
                upd(p[i], b[i]);
            }
        }
        cerr << endl;
    }

    cout << ans << endl;
}

/*

either 2 C, 2 D, or one of each

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
