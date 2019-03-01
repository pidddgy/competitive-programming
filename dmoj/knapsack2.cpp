// https://dmoj.ca/problem/dpe

#include <bits/stdc++.h>
#define ll long long

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    ll W;
    cin >> N >> W;

    ll w[N+1];
    int v[N+1];
    ll maxV = 0;

    for(ll i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
        maxV += v[i];
    }

    ll dp[N+5][maxV+5];
    for(ll i = 0; i < N+5; i++)
        for(ll j = 0; j < maxV+5; j++)
            dp[i][j] = 0;
    
    for(int i = 1; i < N+1; i++)
        for(int j = i; j < N+1; j++)
            if(dp[j][v[i]] != 0)
                dp[j][v[i]] = min(w[i], dp[j][v[i]]);
            else
                dp[j][v[i]] = w[i];
    
    ll maxPossible = 0;

    for(ll i = 1; i <= N; i++) {
        for(ll j = 1; j <= maxV; j++) {
            
            ll prev = dp[i-1][j-v[i]];
            if (i-1 >= 0 && j-v[i] >= 0 && prev + w[i] <= W && prev != 0) {
                if(dp[i][j] == 0)
                    dp[i][j] = prev + w[i];
                else
                    dp[i][j] = min(dp[i][j], prev + w[i]);
            } else {
                if(dp[i][j] == 0)
                    dp[i][j] = dp[i-1][j];
                else if(dp[i-1][j] != 0)
                    dp[i][j] = min( dp[i-1][j], dp[i][j] );
            }

            if(dp[i][j] != 0 && j > maxPossible) maxPossible = j;
        }
    }

    cout << maxPossible << endl;
}
