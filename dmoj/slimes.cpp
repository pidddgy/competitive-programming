// https://dmoj.ca/problem/dpn

#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

ll dp[405][405];
ll a[405];
ll psa[405];

ll sum(ll l, ll r) {
    return psa[r] - psa[l-1];
}

ll f(ll l, ll r) {
    if(dp[l][r] != -1) return dp[l][r];

    if(l == r) {
        dp[l][r] = 0;
        return dp[l][r];
    }
    if(l+1 == r) {
        dp[l][r] = a[l] + a[r];
        return a[l] + a[r];
    }

    dp[l][r] = ULLONG_MAX;

    for(int i = l; i <= r; i++) {
        dp[l][r] = min(dp[l][r], sum(l, i) + sum(i+1, r) + f(l, i) + f(i+1, r));
    }

    return dp[l][r];
}

int main() {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        psa[i] = a[i] + psa[i-1];
    }

    for(int i = 1; i <= N; i++) 
        for(int j = 1; j <= N; j++)
            dp[i][j] = -1;
    
    cout << f(1, N) << endl;

    // for(int i = 1; i <= N; i++)  {
    //     for(int j = 1; j <= N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
}
