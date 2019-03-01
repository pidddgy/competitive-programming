// https://dmoj.ca/problem/vmss7wc16c5p4

#include <bits/stdc++.h>
using namespace std;

int dp[100006][3];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    int a[3];
    for(int i = 0; i < 3; i++)
        cin >> a[i];

    for(int i = 0; i <= N; i++)
        for(int j = 0; j < 3; j++)
            if(i-a[j] >= 0)
                if( max(dp[i-a[j]][0], max(dp[i-a[j]][1], dp[i-a[j]][2])) > 0 || i-a[j] == 0)
                    dp[i][j] = max(dp[i-a[j]][0], max(dp[i-a[j]][1], dp[i-a[j]][2])) + 1;

    cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << "\n";
}
