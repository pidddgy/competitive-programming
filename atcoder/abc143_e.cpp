// https://atcoder.jp/contests/abc143/tasks/abc143_e

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxn = 305;
const int INF = LLONG_MAX/2-100;

int N, M, L, Q;
int cost[maxn][maxn], cost2[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> L;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cost[i][j] = INF;
            if(i == j) cost[i][j] = 0;
        }
    }
    for(int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        cost[a][b] = cost[b][a] = c;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(cost[i][j] <= L) {
                cost2[i][j] = 1;
            } else if(i == j) {
                cost2[i][j] = 0;
            } else {
                cost2[i][j] = INF;
            }
        }
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                cost2[i][j] = min(cost2[i][j], cost2[i][k] + cost2[k][j]);
            }
        }
    }
    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= N; j++) {
    //         cerr << cost[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= N; j++) {
    //         cerr << cost2[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    cin >> Q;

    while(Q--) {
        int s, t;
        cin >> s >> t;

        if(cost2[s][t] == INF) {
            cout << -1 << endl;
        } else {
            cout << cost2[s][t]-1 << endl;
        }
    }
}
