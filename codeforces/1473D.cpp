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

const int maxn = 200500;
string s;
int n, m;

int segmi[4*maxn];
int segma[4*maxn];

int psa[maxn];


// iterative segtree implementation
void updma(int pos, int val) {
    pos += n;
    segma[pos] = val;

    for(int i = pos/2; i >= 1; i /= 2) {
        segma[i] = max(segma[i*2], segma[i*2+1]);
    }
}

int queryma(int l, int r) {
    l += n, r += n;
    int res = -(1e18);

    while(l <= r) {
        if (l%2 == 1) res = max(res, segma[l++]);
        if (r%2 == 0) res = max(res, segma[r--]);
        l /= 2; r /= 2;
    }

    return res;
}

void updmi(int pos, int val) {
    pos += n;
    segmi[pos] = val;

    // cerr << "set " << pos << " to " << val << endl;

    for(int i = pos/2; i >= 1; i /= 2) {
        segmi[i] = min(segmi[i*2], segmi[i*2+1]);
    }
}

int querymi(int l, int r) {
    l += n, r += n;
    int res = 1e18;

    while(l <= r) {
        if (l%2 == 1) res = min(res, segmi[l++]);
        if (r%2 == 0) res = min(res, segmi[r--]);
        l /= 2; r /= 2;
    }

    return res;
}

void solve() {
    cin >> n >> m;

    // updmi(4, 1);
    // watch(querymi(4, 4))

    // clear everything
    for(int i = 1; i <= n; i++) {
        updmi(i, 1e18);
        updma(i, 0);
        psa[i] = 0;
    }

    cin >> s;
    s = "."+s;

    int cur = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '+') cur++;
        else cur--;

        updmi(i, cur);
        updma(i, cur);

        psa[i] = cur;
    }

    while(m--) {
        int l, r;
        cin >> l >> r;

        int lo = 0, hi = 0;

        if(l > 1) {
            lo = min(lo, querymi(1, l-1));
            hi = max(hi, queryma(1, l-1));
        }
        // int lo = querymi(1, l-1);
        // int hi = queryma(1, l-1);

        int rng = psa[r]-psa[l-1];
        watch(rng)
        cerr << lo << " " << hi << endl;

        watch(querymi(r+1, n))

        if(r < n) {
            lo = min(lo, querymi(r+1, n)-rng);
            hi = max(hi, queryma(r+1, n)-rng);
        }
        cerr << lo << " " << hi << endl;

        cout << hi-lo+1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

n*log(2e5)
q * log(2e5)

either use before l, r
or after l, r but subtract

1
2
4
4
3
3
4
2
3
2
1
2
2
2

1
2
4
4
3
3
4
2
3
2
1
2
2
2

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
