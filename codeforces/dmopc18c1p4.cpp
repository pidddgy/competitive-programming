// https://dmoj.ca/problem/dmopc18c1p4

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

pii f[maxn];
int psa[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    for(int i = 1; i <= n; i++) {
        cin >> f[i].fi;
        f[i].se = i;
    }

    sort(f+1, f+n+1);

    for(int i = 1; i <= n; i++) {
        psa[i] = psa[i-1] + f[i].fi;
    }

    bool found = false;
    for(int i = x; i <= n; i++) {
        int l = psa[i-1]-psa[i-x]+1;
        int r = psa[i]-psa[i-x];

        if(l <= k and k <= r) {
            found = true;
            int ree = 1;
            for(int j = i-x+1; j <= i; j++) {
                ans[f[j].se] = ree++;
            }

            for(int j = 1; j <= n; j++) {
                if(ans[j] == 0) ans[j] = ree++;
            }

            assert(ree == n+1);
            break;
        }
    }

    if(!found) {
        cout << -1 << endl;
    } else {
        for(int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

/*

sliding window, ranges always overlap because mathTM

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
