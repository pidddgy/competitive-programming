// https://codeforces.com/contest/717/problem/D

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

ld dp[130][35];
bool vis[35];

ld p[500];
// chance of getting k on n piles, d = times divided by 2
ld f(int n, int k, int d) {
    if(vis[d]) return dp[k][d];
    if(n == 1) return p[k];

    for(int i = 0; i <= 127; i++) {
        dp[i][d+1] = f(n/2, i, d+1);
    }

    if(n%2 == 0) {
        for(int i = 0; i <= 127; i++) {
            for(int j = 0; j <= 127; j++) {
                dp[i^j][d] += dp[i][d+1] * dp[j][d+1];
            }
        }
    } else {
        for(int i = 0; i <= 127; i++) {
            for(int j = 0; j <= 127; j++) {
                for(int l = 0; l <= 100; l++) {
                    dp[i^j^l][d] += dp[i][d+1] * dp[j][d+1] * p[l];
                }
            }
        }
    }

    vis[d] = true;
    return dp[k][d];
}

int n, x;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    cin >> n >> x;
    for(int i = 0; i <= x; i++) {
        cin >> p[i];
    }

    cout << 1-f(n, 0, 0) << endl;
}

/*

xor must be non zero bc uh sprague grundy theorem idk

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
