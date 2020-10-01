// https://codeforces.com/problemset/problem/1133/E

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

const int maxn = 5050;
int a[maxn];
int dp[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // for(int i = 0; i < maxn; i++) {
    //     for(int j = 0; j < maxn; j++) {
    //         dp[i][j] = INT_MIN;
    //     }
    // }

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    } 
    sort(a+1, a+n+1);

    dp[0][0] = 0;
    int ans = 0;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            int l = 1, r = j;
            int lgood = -1;

            while(l <= r) {
                int m = (l+r)/2;

                if(a[j] - a[m] <= 5) {
                    r = m-1;
                    lgood = m;
                } else {
                    l = m+1;
                }
            }

            dp[i][j] = max({dp[i][j], dp[i][j-1], dp[i-1][lgood-1] + (j-lgood+1)});
            ans = max(ans, dp[i][j]);

            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    cout << ans << endl;
}

/*
sort all skill levels

observation: skill levels of teams can be in increasing order and it won't matter
observation 2: if we can take a student in a team that already exists there's no reason not to

dp[i][j] = how many students we can get using i teams and first j students

binary search for max students we can take
    -> optimization: if n^2 log n tles we can use o(n) preprocess

61 438 561


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
