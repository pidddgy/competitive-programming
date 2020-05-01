// https://codeforces.com/contest/429/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define ll long long

const int maxn = 1005;

ll a[maxn][maxn];
ll dptl[maxn][maxn], dptr[maxn][maxn], dpbl[maxn][maxn], dpbr[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dptl[i][j] = max(dptl[i-1][j], dptl[i][j-1])+a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            dptr[i][j] = max(dptr[i-1][j], dptr[i][j+1]) + a[i][j];
        }
    }

    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= m; j++) {
            dpbl[i][j] = max(dpbl[i+1][j], dpbl[i][j-1]) + a[i][j];
        }
    }

    for(int i = n; i >= 1; i--) {
        for(int j = m; j >= 1; j--) {
            dpbr[i][j] = max(dpbr[i+1][j], dpbr[i][j+1]) + a[i][j];
        }
    }    

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= m; j++) {
    //         cerr << dptl[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    ll ans = 0;
    for(int i = 2; i <= n-1; i++) {
        for(int j = 2; j <= m-1; j++) {
            // cerr << " on " << i << " " << j << endl;
            // watch(dptl[i-1][j])
            // watch(dpbr[i+1][j])
            // watch(dpbl[i][j-1])
            // watch(dptr[i][j+1])
            // watch(dptl[i-1][j]+dpbr[i+1][j] + dpbl[i][j-1]+dptr[i][j+1])
            // watch(dptl[i][j-1]+dpbr[i][j+1] + dpbl[i+1][j]+dptr[i-1][j])
            // cerr << max({dptl[i-1][j]+dpbr[i+1][j] + dpbl[i][j-1]+dptr[i][j+1],
                        // dptl[i][j-1]+dpbr[i][j+1] + dpbl[i+1][j]+dptr[i][i-1]}) << endl;

            ans = max({ans, 
                        dptl[i-1][j]+dpbr[i+1][j] + dpbl[i][j-1]+dptr[i][j+1],
                        dptl[i][j-1]+dpbr[i][j+1] + dpbl[i+1][j]+dptr[i-1][j]
            });
        }
    }

    cout << ans << endl;





}