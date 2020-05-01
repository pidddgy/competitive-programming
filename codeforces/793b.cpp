// https://codeforces.com/contest/793/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1005;

vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
char g[maxn][maxn];
int dis[maxn][maxn];

bool valid(int x, int y) {
    return ((1 <= x) and (x <= n) and (1 <= y) and (y <= m));
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int sx, sy;
    int ex, ey;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dis[i][j] = INT_MAX;
            cin >> g[i][j];

            if(g[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if(g[i][j] == 'T') {
                ex = i;
                ey = j;
            }
        }
    }

    queue<int> rQ({sx});
    queue<int> cQ({sy});
    dis[sx][sy] = 0;

    while(!rQ.empty()) {
        int r = rQ.front(); rQ.pop();
        int c = cQ.front(); cQ.pop();

        watch(r)
        watch(c)

        for(pii d: dir) {
            int rcpy = r;
            int ccpy = c;

            while(g[rcpy+d.fi][ccpy+d.se] != '*' and valid(rcpy+d.fi, ccpy+d.se)) {
                rcpy += d.fi;
                ccpy += d.se;

                if(dis[rcpy][ccpy] >= dis[r][c]+1 and dis[r][c] <= 2) {
                    dis[rcpy][ccpy] = dis[r][c]+1;
                    rQ.push(rcpy);
                    cQ.push(ccpy);
                } else break;
                
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cerr << dis[i][j] << " ";
        }
        cerr << endl;
    }
    if(dis[ex][ey] <= 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

// 0,1 1,0 -1,0