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

const int maxn = 100500;
const int maxv = 205;
const int MOD = 998244353;

int mod(int num) {
    return (num+MOD)%MOD;
}
int n;

// 0 = unsatisfied
int dp[2][maxv][2];
int psa[2][maxv][2];

int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        int cur = i%2;
        int pre = cur^1;

        for(int j = 0; j < maxv; j++) {
            for(int k = 0; k < 2; k++) {
                dp[cur][j][k] = 0;
                psa[cur][j][k] = 0;
            }
        }

        cerr << "on" << i << endl;
        for(int j = 1; j <= 200; j++) {
            if(a[i] == -1 or a[i] == j) {
                // satisfied
                if(i != 1) {
                    dp[cur][j][1] += dp[pre][j][0];
                    dp[cur][j][1] += psa[pre][200][1] - psa[pre][j-1][1];
                }

                // not satisfied
                if(i == 1) dp[cur][j][0] = 1;
                else dp[cur][j][0] += psa[pre][j-1][0] + psa[pre][j-1][1];

                dp[cur][j][0] = mod(dp[cur][j][0]);
                dp[cur][j][1] = mod(dp[cur][j][1]);
            }

            psa[cur][j][1] = mod(psa[cur][j-1][1] + dp[cur][j][1]);
            psa[cur][j][0] = mod(psa[cur][j-1][0] + dp[cur][j][0]);
        }
        watch(dp[cur][1][0]) 
        watch(psa[cur][150][1])
        watch(dp[cur][2][0])
        watch(dp[cur][2][1])
    }

    // mod
    int ans = 0;
    watch(dp[n%2][2][0])
    watch(dp[n%2][2][1])
    for(int j = 1; j <= 200; j++) {
        ans += mod(dp[n%2][j][1]);
        ans = mod(ans);
    }
    cout << ans << endl;
}

/*

dp[index][element][already satisfied], number of ways

if current has to be satisfied there is a range:
    transition from whatever satisfied element >= current
    transition from any unsatisfied element == current

if current will be unsatisfied
    transition from any satisfied element < current
    we can use it to satisfy a previously unsatisfied element < current

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
