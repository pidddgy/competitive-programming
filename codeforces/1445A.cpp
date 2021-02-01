// https://codeforces.com/contest/1445/problem/0

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


const int maxn = 55;

int n, x;
int a[maxn], b[maxn];
bool used[maxn];

void solve() {
    cin >> n >> x;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        used[i] = false;
    }

    // each a[i] takes the biggest b possible
    for(int i = 1; i <= n; i++) {
        for(int j = n; j >= 1; j--) {
            if(!used[j] and a[i]+b[j] <= x) {
                used[j] = true;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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