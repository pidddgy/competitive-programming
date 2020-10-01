// https://codeforces.com/contest/370/problem/C

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

int a[5500];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a+n);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != a[(i+n/2)%n]) {
            ans++;
        }
    }

    cout << ans << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " " << a[(i+n/2)%n] << endl;
    }
}

/*

ideas: bipartite (put into pairs), look at case with a "dominant" colour

sort objects and shift everything to optimize unique pairs

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
