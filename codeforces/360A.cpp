// https://codeforces.com/contest/360/problem/A

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

const int maxn = 5005;
int n, m;
int a[maxn], b[maxn], t[maxn], l[maxn], r[maxn], x[maxn];

const int INF = (int)1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        b[i] = INF;
    }

    for(int i = 1; i <= m; i++) {
        cin >> t[i] >> l[i] >> r[i] >> x[i];
    }

    for(int i = 1; i <= m; i++) {
        if(t[i] == 1) {
            for(int j = l[i]; j <= r[i]; j++) {
                a[j] += x[i];
            }
        } else if(t[i] == 2) {
            for(int j = l[i]; j <= r[i]; j++) {
                b[j] = min(b[j], x[i]-a[j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) a[i] = 0;

    for(int i = 1; i <= m; i++) {
        if(t[i] == 1) {
            for(int j = l[i]; j <= r[i]; j++) {
                a[j] += x[i];
            }
        } else if(t[i] == 2) {
            int ma = -INF;
            for(int j = l[i]; j <= r[i]; j++) {
                ma = max(ma, a[j]+b[j]);
            }

            if(ma != x[i]) {
                cout << "NO" << endl;
                exit(0);
            }
        }
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

/*

force each element to be <= a[i]

for each query of type 2 check if max is == a[i]

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
