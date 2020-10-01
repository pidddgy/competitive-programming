// https://dmoj.ca/problem/coci06c1p5

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define ld long double

ld dp[2048576];
ld prob[25][25];
int N;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> prob[i][j];
        }
    }

    dp[0] = 1;
    for(int i = 0; i < (1<<N); i++) {
        int p = __builtin_popcount(i);

        for(int j = 0; j < N; j++) {
            if(!(i&(1<<j))) {
                dp[i|(1<<j)] = max(dp[i|(1<<j)], (dp[i]*prob[p][j])/100);
            }
        }
    }

    cout << fixed << setprecision(20) << 100.0*dp[(1<<N)-1] << endl;
}