// https://codeforces.com/contest/1408/problem/0

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

const int maxn = 105;

int a[10][maxn];
int ans[maxn];

void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    } 

    ans[1] = a[1][1];
    for(int i = 2; i <= n-1; i++) {
        for(int j = 1; j <= 3; j++) {
            if(a[j][i] != ans[i-1]) {
                ans[i] = a[j][i];
                break;
            }
        }
    }

    // for(int i = 1; i <= 3; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int j = 1; j <= 3; j++) {
        if((a[j][n] != ans[n-1]) and (a[j][n] != ans[1])) {
            ans[n] = a[j][n];
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*


just pick whatever because there is guaranteed to be at least one good element no matter what
only consider i+1 if we are at n

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
