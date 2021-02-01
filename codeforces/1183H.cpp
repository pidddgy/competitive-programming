// https://codeforces.com/contest/1183/problem/H

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

int dp[maxn][maxn];

// rightmost index with letter i, index <= j
int ind[26][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    s = "."+s;

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < maxn; j++) {
            ind[i][j] = -1;
        }
    }


    for(int i = n; i >= 1; i--) {
        ind[s[i]-'a'][i] = i;
    }


    for(int i = 0; i < 26; i++) {
        for(int j = 1; j <= n; j++) {
            ind[i][j] = max(ind[i][j], ind[i][j-1]);
        }
    }

    int sum = 0;    
    
    for(int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < 26; k++) {
                if(ind[k][j-1] != -1) {
                    char tmp = k+'a';
                    cerr << "for " << i << " " << j << " " << tmp << " transition from " << i-1 << " " << ind[k][j-1] << endl;
                    dp[i][j] += dp[i-1][ind[k][j-1]];
                    dp[i][j] = min(dp[i][j], (int)1e12);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            cerr << dp[i][j] << " ";
            sum += dp[i][j];
        }
        cerr << " -> " << sum << endl;
    }

    // for(int i = 1; i <= n; i++) {
        // for(int j = 0; )
    // }

    // exhaust length n..1 in that order
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        int sum = 0;
        for(int j = 0; j < 26; j++) {
            if(ind[j][n] != -1) {
                assert(ind[j][n] < maxn);
                sum += dp[i][ind[j][n]];
            }
        }

        int take = min(sum, k);

        ans += take*(n-i);
        k -= take;
    }

    if(k == 1) {
        k--;
        ans += n;
    }

    if(k) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

/*

count unique subsequence of length i

dp[i][j] = length i, used index j
for any index transition from rightmost index with that letter (precompute)

for i in 1...n
    for j in 1..n
        for k in a..z
            dp[i][j] += dp[i-1][ind(k, j)]

guess: if the max sum is >= k then we can always form 
we can start with max and remove 1, then 2.. so on

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
