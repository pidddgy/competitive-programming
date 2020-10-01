// https://atcoder.jp/contests/abc169/tasks/abc169_f

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long

const int MOD = 998244353;
ll dp[3005][3005];
int a[3005];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    dp[0][0] = 1;
    int N, S;
    cin >> N >> S;    
    
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for(int i = 0; i <= N-1; i++) {
        for(int j = 0; j <= S; j++) {
            dp[i+1][j] += dp[i][j]*2;
            dp[i+1][j] %= MOD;

            if(j+a[i] <= S) {
                dp[i+1][j+a[i]] += dp[i][j];
                dp[i+1][j+a[i]] %= MOD;                
            }
        }
    }

    cout << dp[N][S] << endl;
}
