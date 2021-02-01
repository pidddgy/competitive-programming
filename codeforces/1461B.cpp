// https://codeforces.com/contest/1461/problem/B

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

const int maxn = 550;

// * = 1
int a[maxn][maxn];
int psa[maxn][maxn];

int query(int i, int l, int r) {
    return psa[i][r] - psa[i][l-1];
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            if(s[j-1] == '*') a[i][j] = 1;

            cerr << a[i][j] << " ";
        }
        cerr << endl;
    }    

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            psa[i][j] = psa[i][j-1] + a[i][j];
            cerr << psa[i][j] << " ";
        }
        cerr << endl;
    }

    watch(query(2, 1, 3))

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cerr << "on " << i << " " << j << endl;
            for(int k = 1; k <= n-i+1; k++) {
                int l = j-k+1, r = j+k-1;

                cerr << "querying " << i+k-1 << " " << l << " " << r << endl;
                if(l < 1 or r > m) break;

                watch(query(i+k-1, l, r))
                if(query(i+k-1, l, r) != r-l+1) break;

                ans++;
            }
            cerr << endl;

        }
    }

    cout << ans << endl;

    // clear everything
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            a[i][j] = psa[i][j] = 0;
        }
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
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
