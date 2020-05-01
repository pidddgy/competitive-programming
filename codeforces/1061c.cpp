// https://codeforces.com/contest/1061/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 100500;
const int MOD = 1000000007;

int dp[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        vector<int> upd;
        for(int j = 1; j*j <= a[i]; j++) {
            if(a[i]%j==0) {
                cerr << "pushing " << j << endl;
                upd.push_back(j);
                if(j*j != a[i]) {
                    cerr << "pushing " << a[i]/j << endl;
                    upd.push_back(a[i]/j);
                }
            }
        }

        sort(upd.begin(), upd.end(), greater<int>());

        for(int x: upd) {
            if(x > n) continue;
            watch(x)
            dp[x] += dp[x-1];
            dp[x] %= MOD;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << endl;
}