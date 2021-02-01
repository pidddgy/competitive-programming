// https://codeforces.com/contest/1461/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

const int maxn = 100500;
const int maxv = (int)1e6+500;

int n, q, s;
int a[maxn];
int psa[maxn];

int query(int l, int r) {
    return psa[r]-psa[l-1];
}

set<int> S;
void f(int x, int y) {
    if(x > y) return;
    S.emplace(query(x, y));

    cerr << "on " << x << " " << y << endl;
    if(x == y) {
        return;
    }

    int mi = a[x];
    int ma = a[y];

    int mid = (mi+ma)/2;

    int l = x, r = y;
    int lgood = -1;

    while(l <= r) {
        int md = (l+r)/2;

        if(a[md] <= mid) {
            lgood = md;
            l = md+1;
        } else {
            r = md-1;
        }
    }

    watch(lgood)

    // cerr << mi << " " << mid << " " << ma << endl;

    if(lgood != y)
    f(x, lgood);

    if(lgood+1 != x)
    f(lgood+1, y);
}


void solve() {
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++) {
        cerr << a[i] << " ";
        psa[i] += psa[i-1]+a[i];
    }
    cerr << endl;


    S.clear();

    f(1, n);
    for(int i = 1; i <= q; i++) {
        cin >> s;
        if(S.count(s)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    for(int i = 1; i <= n; i++) {
        a[i] = 0;
        psa[i] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
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