// https://codeforces.com/contest/360/problem/B

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

const int maxn = 2005;
int N, K;

int a[maxn];
pii dp[maxn][maxn][2];

bool f(int l, int r, int x, int t) {
    if(abs(l-x) <= t) return true;
    if(abs(r-x) <= t) return true;
    if(l <= x and x <= r) return true;

    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    if(N == 1) {
        cout << 0 << endl;
        exit(0);
    }

    int l = 0;
    // int r = (int)2e9+5;
    int r = 0;
    int ans = LLONG_MAX;

    while(l <= r) {
        for(int i = 0; i < maxn; i++) {
            for(int j = 0; j < maxn; j++) {
                for(int k = 0; k <= 1; k++)
                    dp[i][j][k] = pii(1e10, -1e10);
            }
        }

        int md = (l+r)/2;

        cerr << "trying " << md << endl;

        dp[0][0][0] = pii(-1e10, 1e10);
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= K; j++) {
                // transition from dp[i-1][j]
                for(int k = 0; k <= 1; k++) {
                    if(f(dp[i-1][j][k].fi, dp[i-1][j][k].se, a[i], md)) {
                        dp[i][j][0] = pii(a[i], a[i]);
                    }   
                }

                // transition from dp[i-1][j-1] if j >= 1
                if(j >= 1) {
                    for(int k = 0; k <= 1; k++) {
                        if(dp[i-1][j-1][k] != pii(1e10, -1e10))  {
                            dp[i][j][1].fi = dp[i-1][j-1][k].fi-md;
                            dp[i][j][1].se = dp[i-1][j-1][k].se+md;
                        }
                    }
                }
            }
        }
        cerr << dp[1][1][1].fi << " " << dp[1][1][1].se << endl;
        cerr << dp[2][2][1].fi << " " << dp[2][2][1].se << endl;
        cerr << dp[3][3][1].fi << " " << dp[3][3][1].se << endl;
        cerr << dp[4][4][1].fi << " " << dp[4][4][1].se << endl;
        cerr << dp[5][5][1].fi << " " << dp[5][5][1].se << endl;
        cerr << dp[6][6][1].fi << " " << dp[6][6][1].se << endl;
        cerr << dp[7][6][0].fi << " " << dp[7][6][0].se << endl;
        cerr << dp[8][7][1].fi << " " << dp[8][7][1].se << endl;

        
        


        bool ok = false;
        for(int i = 0; i <= K; i++) {
            if(dp[N][i][0] != pii(1e10, -1e10)) ok = true;
            if(dp[N][i][1] != pii(1e10, -1e10)) ok = true;
        }

        if(ok) {
            ans = md;
            r = md-1;
        } else {
            l = md+1;
        }   
    }

    cout << ans << endl;
}

/*

make max min possible

pii dp[i][j] = on index i, used j changes, l and r possible

binary search on ans



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
