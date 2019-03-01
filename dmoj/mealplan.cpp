#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, B, L, D;
    cin >> N >> B >> L >> D;

    int bf[B]; // Breakfast
    int lc[L]; // Lunch
    int dn[D]; // Dinner

    for(int i = 0; i < B; i++) cin >> bf[i];
    for(int i = 0; i < L; i++) cin >> lc[i];
    for(int i = 0; i < D; i++) cin >> dn[i];

    ll dp[N+1][3];
    for(int i = 0; i < N+1; i++) 
        for(int j = 0; j < 3; j++) {
            dp[i][j] = 0;
        }


    for(int i = 0; i < B; i++) {
        if(bf[i] < N+1)
            dp[bf[i]][0]++;
    }

    ll maxH = 0;
    ll ways = 0;

    for(int i = 1; i < N+1; i++) {
        for(auto l_i: lc) {
            if(i+l_i < N+1)
                dp[i+l_i][1] += dp[i][0] % 1000000007;
        }

        for(auto d_i: dn) {
            if(i+d_i < N+1)
                dp[i+d_i][2] += dp[i][1] % 1000000007;
        }

        for(auto b_i: bf) {
            if(i+b_i < N+1)
                dp[i+b_i][0] += dp[i][2] % 1000000007;
        }

        if(dp[i][0] + dp[i][1] + dp[i][2] > 0 && i > maxH) {
            maxH = i;
            ways = dp[i][0] + dp[i][1] + dp[i][2] % 1000000007;
        }
    }


    cout << ways % 1000000007 << " " << N - maxH << endl;

}
