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

const int maxn = 300500;
const int MOD = 998244353;

int mod(int num) {
    return (num+MOD)%MOD;
}

bool cmp(const pii &l, const pii &r) {
    return l.se < r.se;
}

pii a[maxn];
int fac[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fac[1] = 1;
    for(int i = 2; i <= 3e5; i++) {
        fac[i] = mod(fac[i-1]*i);
    }

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a+1, a+n+1);
    int cur = 1;
    int x = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i].fi != a[i-1].fi) {
            x *= fac[cur];
            x = mod(x);
            cerr << "group size " << cur << endl;
            cur = 1;
        } else {
            cur++;
        }
    }
            cerr << "group size " << cur << endl;

    x *= fac[cur];
    x = mod(x);
    watch(x)

    int y = 1;
    sort(a+1, a+n+1, cmp);
    cur = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i].se != a[i-1].se) {
            cerr << "group size " << cur << endl;
            y *= fac[cur];
            y = mod(y);
            watch(y)
            cur = 1;
        } else {
            cur++;
        }
    }
            cerr << "group size " << cur << endl;

    y *= fac[cur];
    y = mod(y);
    watch(y)

    int z = 0;
    sort(a+1, a+n+1);
    stable_sort(a+1, a+n+1, cmp);

    bool sorted = true;
    for(int i = 1; i < n; i++) {
        if(!(a[i].fi <= a[i+1].fi and a[i].se <= a[i+1].se)) sorted = false;
    }

    if(sorted) {
        cur = 1;
        z = 1;
        for(int i = 2; i <= n; i++) {
            if(a[i] != a[i-1]) {
                z *= fac[cur];
                z = mod(z);
                cur = 1;
            } else {
                cur++;
            }
        }

        z *= fac[cur];
        z = mod(z);
    }

    int bad = mod(x+y-z);

    cout << mod(fac[n]-bad) << endl;
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
