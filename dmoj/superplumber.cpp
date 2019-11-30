// https://dmoj.ca/problem/ccc04s5

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
#define maxNM 105

int a[maxNM][maxNM];
int dp[maxNM][maxNM];
int main() {
    for(;;) {
        int M, N;
        cin >> M >> N;
        if(M == 0 && N == 0) return 0;
        
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                char b;
                cin >> b;

                if(b == '*') a[i][j] = -10;
                else if(b == '.') a[i][j] = 0;
                else a[i][j] = b-'0';

                dp[i][j] = -1;
            }
        }

        // left row, bottom up
        dp[M][1] = a[M][1];
        for(int i = M-1; i >= 1; i--) {
            if(a[i][1] == -10){
                break;
            }
            else {
                if(a[i][1] != 20)
                    dp[i][1] = a[i][1] + dp[i+1][1];
                else 
                    dp[i][1] = dp[i+1][1];
            }
        }
        
        for(int i = 2; i <= N; i++) {
            //cout << "on col " << i << endl;
            // go up down
            for(int j = 1; j <= M; j++) {
                if(dp[j][i-1] != -1) {
                //  cout << "editing " << i  << " " << j << endl;
                    int temp = dp[j][i-1];
                    for(int k = j; k <= M; k++) {
                        if(a[k][i] == -10) break;
                        
                        temp += a[k][i];
                        dp[k][i] = max(dp[k][i], temp);
                //        cout << "currently on " << i << " " << k << endl;
                    }
                }
            //  cout << endl;
            }
        
            // down up
            for(int j = M; j >= 1; j--) {
                if(dp[j][i-1] != -1) {
                    int temp = dp[j][i-1];
                    for(int k = j; k >= 1; k--) {
                        if(a[k][i] == -10) break;

                        temp += a[k][i];
                        dp[k][i] = max(dp[k][i], temp);
                    }
                }
            }
        }

        cout << dp[M][N] << endl;
    }
}
