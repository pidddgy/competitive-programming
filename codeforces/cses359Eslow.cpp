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
#define sz(a) (int)(a).size()
#define y1 lsdjkfhshfdsighoihweogihewoghi
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 2005;

int n, k;
vector<int> a;
bool used[maxn];
int dp[maxn][maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        cnt[x]++;
    }

    a.emplace_back(0);

    int add = 0;
    for(pii x: cnt) {
        add += x.se/2;

        if(x.se%2) {
            a.emplace_back(x.fi);
        }
    }

    n = n-2*add;
    k -= add;

    if(k <= 0) {
        cout << 0 << endl;
        return 0;
    }


    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            dp[i][j] = 1e18;
        }
    }
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i >= 2) {
                cerr << i << " " << j << endl;
                dp[i][j] = min(dp[i][j], dp[i-2][j-1]+(a[i]-a[i-1]));
            }

            dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
    }

    cout << dp[n][k] << endl;
}

/*

dp[i][j] = first i, j pairs, min cost

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
