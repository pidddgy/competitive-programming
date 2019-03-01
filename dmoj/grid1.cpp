#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    char grid[H+1][W+1];
    for(int i = 1; i < H+1; i++)
        for(int j = 1; j < W+1; j++)
            cin >> grid[i][j];

    unsigned long long dp[H+1][W+1];
    for(int i = 0; i < H+1; i++)
        for(int j = 0; j < W+1; j++)
            dp[i][j] = 0;

    dp[1][1] = 1;
    for(int i = 1; i < H+1; i++)
        for(int j = 1; j < W+1; j++) {
            if(grid[i][j] != '#') {
                dp[i][j] += dp[i-1][j] % 1000000007;
                dp[i][j] += dp[i][j-1] % 1000000007;
            }
        }

    cout << dp[H][W] % 1000000007 << endl;
}
