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

int a[3000][3000];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        int x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;

        // if(x > x2) swap(x, x2);
        // if(y > y2) swap(y, y2);

        x2--;
        y2--;

        a[x][y]++;
        a[x][y2+1]--;
        a[x2+1][y]--;
        a[x2+1][y2+1]++;
    }

    int ans = 0;
    int ma = 1000;
    for(int i = 0; i <= ma; i++) {
        for(int j = 0; j <= ma; j++) {
            if(i > 0) a[i][j] += a[i-1][j];
            if(j > 0) a[i][j] += a[i][j-1];
            if(i > 0 and j > 0) a[i][j] -= a[i-1][j-1];

            cerr << a[i][j];
            if(a[i][j] == k) {
                ans++;
            }
        }
        cerr << endl;
    }

    cout << ans << endl;
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
