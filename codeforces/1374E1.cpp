// https://codeforces.com/contest/1374/problem/E1

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

const int maxn = 200500;
int ind[5];
int times[5][maxn], psa[5][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        int t, a, b;
        cin >> t >> a >> b;

        int j = a*2 + b;

        times[j][++ind[j]] = t;
        cerr << "putting " << t << " to " << j << " " << ind[j] << endl;
    }

    for(int i = 0; i <= 3; i++) {
        sort(times[i]+1, times[i]+1+ind[i]);

        for(int j = 1; j <= ind[i]; j++) {
            cerr << times[i][j] << " ";
        }
        cerr << endl;
        cerr << "~~~~" << endl;
    }


    for(int i = 0; i <= 3; i++) {
        for(int j = 1; j <= ind[i]; j++) {
            psa[i][j] = psa[i][j-1] + times[i][j];
        }
    }

    watch(psa[0][2])
    
    int ans = LLONG_MAX;
    for(int i = 0; i <= ind[3]; i++) {
        cerr << "trying " << i << endl;
        int need = k-i;

        if(need > ind[1] or need > ind[2]) continue;
        watch(need)
        int loc = psa[3][i] + psa[2][need] + psa[1][need];

        ans = min(ans, loc);
    }
    
    if(ans == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
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
