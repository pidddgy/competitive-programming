// https://dmoj.ca/problem/wac5p5

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

vector<vector<int>> vectors;

int N, E, K;


const int maxn = 100;
const int MOD = 998244353;

int a[maxn+10][maxn+10];
int dp[maxn+10][maxn+10][2][2][10];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E >> K;

    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= N; j++) {
            if(s[j-1] == '1') a[i][j] = true;
        }
    }

    dp[1][1][0][0][0] = 1;

    for(int i = 1; i <= E-1; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                for(int l = 0; l <= 1; l++) {
                    for(int m = 0; m <= 1; m++) {
                        for(int n = 0; n <= 6; n++) {
                            if(a[j][k]) {
                                bool ree = (k == 2);
                                bool reee = (k == 3);
                                bool reeee = (k == 4);

                                dp[i+1][k][l|ree][m|reee][n+reeee] += dp[i][j][l][m][n];
                                dp[i+1][k][l|ree][m|reee][n+reeee] %= MOD;
                            }
                        }
                    }
                }
                
            }
        }
    }

    cout << dp[E][N][1][1][K] << endl;
}

/*

dp[event number][current event type][found shelter][found partner <3][number of acorns]

01100
00110
01011
00001
00000

1 2
1 3

2 3
2 4

3 2
3 4
3 5

4 5
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
