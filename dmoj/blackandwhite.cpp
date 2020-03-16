// https://dmoj.ca/problem/dmpg15s5

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 10500;
int N, M;
bool d[maxn][maxn];
signed main() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;

        x++;
        y++;

        d[x][y] = !d[x][y];
        d[x+w][y] = !d[x+w][y];
        d[x][y+h] = !d[x][y+h];
        d[x+w][y+h] = !d[x+w][y+h];
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            d[i][j] = d[i-1][j] ^ d[i][j-1] ^ d[i-1][j-1] ^ d[i][j];

            if(d[i][j] % 2 == 1) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}