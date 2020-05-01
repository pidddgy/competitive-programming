// https://codeforces.com/contest/1341/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

vector<string> seq = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

const int maxn = 2420;

string a[maxn];
bool dp[maxn][maxn];
int cost[maxn][20];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            int c = 0;
            for(int k = 0; k < a[i].size(); k++) {
                if(a[i][k] == '1' and seq[j][k] == '0') {
                    c = INT_MAX;
                    break;
                }
                if(a[i][k] != seq[j][k]) {
                    c++;
                }
            }

            cost[i][j] = c;
            // cerr << i << "," << j << " - " << c << endl;
        }
    }

    dp[N+1][0] = true;
    for(int i = N; i >= 1; i--) {
        for(int j = 0; j <= K; j++) {
            if(!dp[i+1][j]) continue;
            for(int k = 0; k <= 9; k++) {
                if(j+cost[i][k] > K) {
                    continue;
                }

                dp[i][j+cost[i][k]] = true;
            }
        }
    }

    if(!dp[1][K]) {
        cout << -1 << endl;
        return 0;
    }

    int rem = K;
    for(int i = 1; i <= N; i++) {
        for(int j = 9; j >= 0; j--) {
            if(rem-cost[i][j] < 0) continue;
            if(dp[i+1][rem-cost[i][j]]) {
                cout << j;
                rem -= cost[i][j];
                break;
            }
        }
    }
    cout << endl;
}