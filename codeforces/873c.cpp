// https://codeforces.com/contest/873/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
const int maxn = 105;
int n, m, k;
int a[maxn][maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    int anscost = 0;
    for(int i = 1; i <= m; i++) {
        cerr << "on col " << i << endl;
        int cost = 0;

        int micost = 0;
        int ma = 0;
        for(int j = 0; j <= n-k; j++) {
            cerr << "on row " << j << endl;

            if(a[j][i] == 1) {
                cerr << "increment cost" << endl;
                cost++;
            }

            int val = 0;
            for(int c = 1; c <= k; c++) {
                val += a[j+c][i];
            }

            watch(val)
            watch(cost)

            if(val > ma) {
                ma = val;
                micost = cost;
            }
        }

        cerr << "best for column " << i << " is " << ma << endl;

        ans += ma;
        anscost += micost;
        cerr << endl;
    }

    cout << ans << " " << anscost << endl;
}