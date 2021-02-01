// https://codeforces.com/contest/1443/problem/f

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

const int maxn = 200500;
const int MOD = 998244353;

int n, m;
int a[maxn], b[maxn];

// if about to come in b
int have[maxn];
int pos[maxn];

void solve() {
    cin >> n >> m;

    for(int i = 1; i <= max(n, m)+50; i++) {
        a[i] = b[i] = have[i] = pos[i] = 0;
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        have[b[i]] = true;
    }

    have[0] = true;
    int ans = 1;
    for(int i = 1; i <= m; i++) {
        int k = 2;
        if(have[a[pos[b[i]]-1]]) k--;
        if(have[a[pos[b[i]]+1]]) k--;

        if(k == 0) {
            cout << 0 << endl;
            return;
        }
        ans *= k;
        ans %= MOD;

        have[b[i]] = false;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();    
}

/*

each element is either used or not used

for x in b
    pick any unused adjacent to x

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
