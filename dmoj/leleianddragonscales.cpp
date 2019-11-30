// https://dmoj.ca/problem/dmopc15c1p5

#include <bits/stdc++.h>
#define maxn 300
#define pii pair<int, int>
#define fi first
#define se second
#define endl '\n'
using namespace std;

int a[maxn][maxn];
int psa[maxn][maxn];

int query(int i, int j, int ii, int jj) {
    return psa[ii][jj] - psa[ii][j-1] - psa[i-1][jj] + psa[i-1][j-1];
}
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int W, H, N;
    cin >> H >> W >> N;

    for(int i = 1; i <= W; i++) {
        for(int j = 1; j <= H; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= W; i++) {
        for(int j = 1; j <= H; j++) {
            if(i == 1 and j == 1) {
                psa[i][j] = a[i][j];
            } else if(i == 1) {
                psa[i][j] = a[i][j] + psa[i][j-1];
            } else if(j == 1) {
                psa[i][j] = a[i][j] + psa[i-1][j];
            } else {
                psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + a[i][j];
            }
        }
    }

    vector<pii> dimen;
    for(int i = 1; i <= N; i++) {
        if(dimen.size())
        if(i == dimen.back().fi or N/i == dimen.back().se)
            dimen.pop_back();

        dimen.emplace_back(i, N/i);
    }

    int ans = 0;
    for(int i = 1; i <= W; i++) {
        for(int j = 1; j <= H; j++) {
            for(pii d: dimen) {
                ans = max(ans, query(i, j, min(i+d.fi-1, W), min(j+d.se-1, H)));
            }
        }
    }

    cout << ans << endl;
}