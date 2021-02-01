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

const int maxn = 2300;
const vector<pii> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int n, m, r, c, x, y;
char a[maxn][maxn];
int dis[maxn][maxn];
bool vis[maxn][maxn];
bool ok(int row, int col) {
    if(1 <= row and row <= n) {
        if(1 <= col and col <= m) {
            if(a[row][col] != '*')
            return true;
        }
    }

    return false;
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            dis[i][j] = 1e18;

    cin >> n >> m;
    cin >> r >> c;
    cin >> x >> y;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j-1];
        }
    }

    deque<int> rdq, cdq;
    rdq.push_back(r);
    cdq.push_back(c);
    dis[r][c] = 0;

    while(!rdq.empty()) {
        int cr = rdq.front(), cc = cdq.front();
        rdq.pop_front();
        cdq.pop_front();

        cerr << "On " << cr << " " << cc << endl;
        watch(dis[cr][cc])

        int rm = cc-(c-dis[cr][cc]);
        watch(rm)
        if(dis[cr][cc] <= x and rm <= y)
            vis[cr][cc] = true;
        else continue;

        for(pii d: dir) {
            if(ok(cr+d.fi, cc+d.se)) {
                if(dis[cr+d.fi][cc+d.se] > dis[cr][cc]+(d==pii(0, -1))) {
                    dis[cr+d.fi][cc+d.se] = dis[cr][cc]+(d==pii(0, -1));
                    if(d == pii(0, -1)) {
                        rdq.push_back(cr+d.fi);
                        cdq.push_back(cc+d.se);
                    } else {
                        rdq.push_front(cr+d.fi);
                        cdq.push_front(cc+d.se);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ans += vis[i][j];
        }
    }

    cout << ans << endl;
}

/*
0-1 bfs with deque
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
