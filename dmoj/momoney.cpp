#include <bits/stdc++.h>

#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    
    int a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];    

    int dp[n+1][t+1];
    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < t+1; j++)
            dp[i][j] = 0;

    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < t+1; j++) {
            dp[i][j] += dp[i-1][j];
            if(j - a[i] >= 0) {
                dp[i][j] += dp[i-1][j-a[i]];
            }
        }
    }
    cout << dp[n][t] << endl;
}
