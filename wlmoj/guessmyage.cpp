// https://mcpt.ca/problem/jdcc16c1p4

#include <bits/stdc++.h>
using namespace std;
int dp[50005];
int main() {
    int N, K;
    cin >> N >> K;

    dp[1] = 0;
    for(int i = 2; i <= N; i++) {
        int mi = 2147483647;
        // ask if age is greater than j
        for(int j = 1; j < i; j++) {
            int worst = max(dp[j]+100, dp[i-j]+100+K);
            mi = min(mi, worst);
        }
        dp[i] = mi;
    }

    cout << dp[N] << endl;
}