// https://dmoj.ca/problem/dpc

#include <bits/stdc++.h>
using namespace std;
int n(char a) {
    return a-'a';
}

int main() {
    int N;
    cin >> N;
    int a[N], b[N], c[N];

    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    // Max happiness on a day n = dp[n]
    int dp[N][3];
    dp[0][n('a')] = a[0];
    dp[0][n('b')] = b[0];
    dp[0][n('c')] = c[0];

    for(int i = 1; i < N; i++) {
        dp[i][n('a')] = a[i] + max(dp[i-1][n('b')], dp[i-1][n('c')]);
        dp[i][n('b')] = b[i] + max(dp[i-1][n('a')], dp[i-1][n('c')]);
        dp[i][n('c')] = c[i] + max(dp[i-1][n('a')], dp[i-1][n('b')]);
    }

    cout << max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])) << endl;
}
