// https://dmoj.ca/problem/valday15p2

#include <bits/stdc++.h>
#define pb push_back
#define endl '\n'

using namespace std;
int C, M;
vector<int> w;
vector<int> cnt;

int dp[1001][1001];

int KS(int C, int n) {
    if(dp[C][n] != -1)
        return dp[C][n];
    if(n == -1 || C == 0)
        return 0;
    else if(w[n] > C)
        return KS(C, n-1);
    else {
        int wo = KS(C, n-1);
        int with = cnt[n] + KS(C-w[n], n-1);
        
        dp[C][n] = max(wo, with);
        return max(wo, with);
    }
}

int main() {
    for(int i = 0; i < 1001; i++)
        for(int j = 0; j < 1001; j++)
            dp[i][j] = -1;

    cin.sync_with_stdio(0);
    cin.tie(0);

    int C, M;
    cin >> C >> M;

    for(int i = 0; i < C; i++) {
        int N, K;
        cin >> N >> K;
        cnt.pb(N);
        w.pb(K);
    }
    
    cout << KS(M, C-1) << endl;
}
