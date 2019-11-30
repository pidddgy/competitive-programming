#include <bits/stdc++.h>
#define ld long double
#define MAXN 3003
using namespace std;

ld dp[MAXN][MAXN];
ld a[MAXN];

int main() {
    int N;
    cin >> N;

    
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    dp[0][0] = 1;
    for(int i = 1; i <= N; i++) dp[0][i] = (1-a[i]) * dp[0][i-1];
    // chance to get i heads using first j coins
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
        //    if jth coin will be head
            dp[i][j] += dp[i-1][j-1]*a[j];

            // if jth coin will be tail
            dp[i][j] += dp[i][j-1]* (1-a[j]);
        }
    }

    ld ans = 0;
    for(int i = (N/2)+1; i <= N; i++) {
        ans += dp[i][N];
    }

    cout << setprecision(10) << ans << endl;
}
