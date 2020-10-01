// https://codeforces.com/contest/460/problem/C

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
int n, m, w;
int a[maxn];
int cpy[maxn], d[maxn];

void reset() {
    for(int i = 0; i < maxn; i++) {
        cpy[i] = a[i];
        d[i] = 0;
    }
}

bool f(int x) {
    reset();

    cerr << "checking " << x << endl;

    int used = 0;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        cur += cpy[i];
        cur += d[i];

        if(cur < x) {
            int water = x-cur;
            used += water;

            cerr << "using " << water << " on " << i << endl;
            watch(cur)

            cur += water;
            d[i+w] -= water;
        }
        cur -= cpy[i];
    }

    return (used <= m);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> w;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 2e9;
    int lgood = -1;

    while(l <= r) {
        int mid = (l+r)/2;

        if(f(mid)) {
            lgood = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << lgood << endl;
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
