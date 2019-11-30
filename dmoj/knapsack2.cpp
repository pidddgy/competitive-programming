// https://dmoj.ca/problem/dpe

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1000005];
int main() {
    ll N, W;
    cin >> N >> W;
    fill(dp, dp+1000005, 100000000005);
    dp[0] = 0;
    for(int i = 1; i <= N; i++) {
        ll wi, vi; 
        cin >> wi >> vi;
        for(int j = 1000004; j >= vi; j--) {
            dp[j] = min(dp[j], dp[j-vi] + wi);
        }
    }

    // for(int j = 0; j <= 20; j++) {
    //     cout << dp[j] << " ";
    // }


  //  cout << endl;
    for(ll j = 1000003; j >= 1; j--) {
        if(dp[j] <= W) {
            cout << j << endl;
            return 0;
        }
    }
}
