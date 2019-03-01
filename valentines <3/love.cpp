// https://dmoj.ca/problem/valentines19j3

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string m;
    getline(cin, m);

    string n = "love";

    long long dp[m.size()+1][n.size()+1];
    
    for(int i = 0; i < m.size()+1; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i < n.size()+1; i++) {
        dp[0][i] = 0;
    }



    for(int i = 1; i < m.size()+1; i++) {
        for(int j = 1; j < n.size()+1; j++) {
            dp[i][j] = 0;
            if(m[i-1] == n[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else
                dp[i][j] = dp[i-1][j];
        }
    }

    // for(int i = 0; i <= m.size(); i++) {
    //     for(int j = 0; j <= n.size(); j++) {
    //         cout << dp[i][j];
    //     }
    //     cout << endl;
    // }
    cout << dp[m.size()][n.size()] << endl;;


}
