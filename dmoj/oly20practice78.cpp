// https://dmoj.ca/problem/oly20practice78

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxm = 5e4;
int N, M;
int dp[maxm+400];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= maxm; i++) {
        dp[i] = INT_MAX;
    }

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        int v, w;
        cin >> v >> w;

        for(int i = 0; i <= M; i++) {
            dp[min(i+v, M)] = min(dp[min(i+v, M)], dp[i]+w);
        }
    }

    cout << dp[M] << endl;
}
