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

const int maxn = 300;

int n, b;
int a[maxn], s[maxn], d[maxn];

bool dp[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("snowboots.in", "r", stdin); 
    freopen("snowboots.out", "w", stdout);

    cin >> n >> b;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= b; i++) {
        cin >> s[i] >> d[i];
    }

    for(int i = 1; i <= b; i++) {
        dp[1][i] = true;
    }

    for(int i = 1; i <= n-1; i++) {
        for(int j = 1; j <= b; j++) {
            if(!dp[i][j]) continue;

            // take a step
            for(int k = 1; k <= d[j]; k++) {
                if(i+k > n) continue;

                if(s[j] >= a[i+k]) dp[i+k][j] = true;
            }

            // go forward
            for(int k = j+1; k <= b; k++) {
                if(s[k] >= a[i]) dp[i][k] = true;
            }
        }
    }

    for(int i = 1; i <= b; i++) {
        if(dp[n][i]) {
            cout << i-1 << endl;
            break;
        }
    }
}

/*

dp[i][j] = on ith index, jth boot

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
