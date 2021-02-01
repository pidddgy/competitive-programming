// https://codeforces.com/contest/1436/problem/B

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

const int maxn = 105;

int ans[maxn][maxn];
int r[maxn], c[maxn];

void cl() {
    for(int i = 0; i < maxn; i++) {
        r[i] = 0;
        c[i] = 0;
        for(int j = 0; j < maxn; j++) {
            ans[i][j] = 0;
        }
    }
}
void solve() {
    int n;
    cin >> n;

    cl();

    for(int i = 1; i <= n; i++) {
        ans[i][i] = 1;    
    }

    int j = 1;
    for(int i = n; i >= 1; i--) {
        ans[i][j] = 1;
        j++;
    }

    if(n%2 == 1) {
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int c = n/2+1;
                ans[c+i][c+j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            sum += ans[i][j];
        }

        cerr << "failed on " << n << endl;
        assert(sum == 2 or sum == 3);
    }

    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            sum += ans[j][i];
        }

        assert(sum == 2 or sum == 3);
    }


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

even cases: diagonal
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
