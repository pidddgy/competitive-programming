// https://dmoj.ca/problem/dpl

#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N;
ll a[3005];
ll dp[3005][3005];

ll f(ll l, ll r) {
    if(r+1 == l) {
        return 0;
    }

    if(dp[l][r] != -1) return dp[l][r];
    dp[l][r] = max(a[l] - f(l+1, r), a[r] - f(l, r-1));

    return dp[l][r];
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < 3005; i++) {
        for(int j = 0; j < 3005; j++)
            dp[i][j] = -1;
    }

    f(1, N);
    cout << dp[1][N] << endl;
}
