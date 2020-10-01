// https://codeforces.com/contest/1417/problem/C

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

const int maxn = 300500;

vector<int> a[maxn];

// take suffix minimum
int ans[maxn];
int n;

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        a[i].emplace_back(0);
        ans[i] = INT_MAX;
    }
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        a[x].emplace_back(i);
    }
    for(int i = 1; i <= n; i++) {
        a[i].emplace_back(n+1);
    }

    for(int i = 1; i <= n; i++) {
        // i supports up to ma length
        int ma = INT_MIN;
        for(int j = 0; j < sz(a[i])-1; j++) {
            ma = max(ma, a[i][j+1]-a[i][j]-1);
        }

        ans[ma+1] = min(ans[ma+1], i);
    }

    ans[0] = INT_MAX;
    for(int i = 1; i <= n; i++) {
        ans[i] = min(ans[i], ans[i-1]);
    }

    for(int i = 1; i <= n; i++) {
        if(ans[i] == INT_MAX) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << endl;

    // clear everything    
    for(int i = 1; i <= n; i++) {
        a[i].clear();
        ans[i] = INT_MAX;
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

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
