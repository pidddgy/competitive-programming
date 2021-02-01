// https://codeforces.com/contest/148/problem/D

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

const int maxn = 1005;

ld dp[2][maxn][maxn];

ld f(int turn, int w, int b) {
    if(dp[turn][w][b] != -1) {
        return dp[turn][w][b];
    }

    if(w == 0) {
        if(turn == 0) {
            dp[turn][w][b] = 0;
        } else {
            dp[turn][w][b] = 1;
        }

        return dp[turn][w][b];
    }

    ld cum = 0;
    int cases = 0;

    ld tot = w+b;

    ld res = 0;
    // take black
    if(b > 0) {
        pii s = pii(w, b);
        s.se--;

        // dragon
        if(turn == 1) {
            if(s.fi) {
                // probability of this occuring
                ld prob = ((ld)b/tot) * (ld)(s.fi/((ld)s.fi+(ld)s.se));
                ld to = (1-f(turn^1, s.fi-1, s.se));

                res += prob*to;
            }

            if(s.se) {
                ld prob = ((ld)b/tot) * ((ld)s.se/((ld)s.fi+(ld)s.se));
                ld to = (1-f(turn^1, s.fi, s.se-1));

                res += prob*to;
            }
        } else {
            ld prob = b/(ld)tot;
            ld to = (1.0-f(turn^1, s.fi, s.se));

            res += prob*to;
        }
    }
    res += w/tot;

    dp[turn][w][b] = res;
    return res;
}

signed main() {

    cerr << fixed << setprecision(10);      
    cout << fixed << setprecision(10);      
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < maxn; j++) {
            for(int k = 0; k < maxn; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    // 0 = princess
    // 1 = dragon
    dp[0][0][0] = 0;
    dp[1][0][0] = 1;

    int w,b;
    cin >> w >> b;

    f(0, w, b);

    cout << dp[0][w][b] << endl;
}

/*

dp[i][j][k] = chance of winning [turn][white][black]

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?