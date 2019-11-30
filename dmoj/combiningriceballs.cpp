// https://dmoj.ca/problem/ccc16s4

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int dp[405][405];
int main() {
    int N;
    cin >> N;

    int a[N+1];
    for(int i = 1; i <= N; i++) cin >> a[i];

    int ans = 0;
    for(int i = N; i >= 1; i--) {
        for(int j = i; j <= N; j++) {
        //    cout << i << " " << j << endl;
            if(i == j) dp[i][j] = a[i];
            else {
                // two points
                int top = i;
                int right = j;

                // [i][top]
                // [right][j]

                while(top < j && right > i) {
                    if(dp[i][top] < dp[right][j]) top++;
                    else if(dp[right][j] < dp[i][top]) right--;
                    else if (dp[right][j] == dp[i][top]) {
                        if(dp[i][top] == 0)  {
                            top++;
                            right--;
                        } else if(top+1 == right) {
                            dp[i][j] = dp[i][top]*2;
                        } else if(dp[top+1][right-1] != 0)  {
                            dp[i][j] = dp[i][top]*2 + dp[top+1][right-1];
                        } else {
                            top++;
                            right--;
                        }
                    } else {
                        top++;
                        right--;
                    }
                    if(dp[i][j] != 0) break;
                }
            }

            ans = max(ans, dp[i][j]);
        } 
    }
    cout << ans << endl;
    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
}
