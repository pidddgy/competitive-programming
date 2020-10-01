// https://codeforces.com/contest/372/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 50;
int n, m, q;

int a[maxn][maxn], psa[maxn][maxn];

int dp[maxn][maxn][maxn][maxn];

// i, j = top left, ii, jj = bottom right
int query(int i, int j, int ii, int jj) {
    return psa[ii][jj] - psa[ii][j-1] - psa[i-1][jj] + psa[i-1][j-1];
}

int f(int n) {
    if(n) return -1;
    else return 0;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j-1]-'0';
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + a[i][j];
        }
    }

    for(int i = n; i >= 1; i--) {
        for(int j = m; j >= 1; j--) {
            for(int k = i; k <= n; k++) {
                for(int l = j; l <= m; l++) {
                    if(query(i, j, k, l) == 0) dp[i][j][k][l] = 1;

                    for(int mask = 1; mask < (1<<4); mask++) {
                        int val = dp[i-f(mask&1)][j-f(mask&2)][k+f(mask&4)][l+f(mask&8)];

                        if(__builtin_popcount(mask)&1) {
                            dp[i][j][k][l] += val;
                        } else {
                            dp[i][j][k][l] -= val;
                        }
                    }
                }
            }
        }
    }

    while(q--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        cout << dp[A][B][C][D] << endl;
    }
}
