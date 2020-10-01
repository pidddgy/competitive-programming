// https://atcoder.jp/contests/abc167/tasks/abc167_c

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define cerr cout
#define int long long
#define all(x) (x).begin(), (x).end()

const int maxn = 20;

int C[maxn], U[maxn];
int A[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    for(int i = 0; i < N; i++) {
        cin >> C[i];
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int ans = INT_MAX;
    for(int mask = 0; mask <= (1<<12)-1; mask++) {
        for(int i = 0; i < maxn; i++) U[i] = 0;

        int cost = 0;
        for(int i = 0; i < N; i++) {
            if(mask & (1<<i)) {
                cost += C[i];
                for(int j = 0; j < M; j++) {
                    U[j] += A[i][j];
                }
            }
        }

        
        // bitset<12> x(mask);
        // cout << x << endl;
        // watch(cost)
        // cerr << endl;

        bool ok = true;
        for(int i = 0; i < M; i++) {
            if(U[i] < X) {
                ok = false;
            }
        }

        if(ok) {
            ans = min(ans, cost);
        }
    }

    if(ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
