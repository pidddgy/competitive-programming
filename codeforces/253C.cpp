// https://codeforces.com/contest/253/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 105;
const int maxa = 100500;

int n;
int a[maxn];
int dis[maxn][maxa];

const vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool ok(int x, int y) {
    if(y < 1) return false;
    if(x < 1) return false;
    if(x > n) return false;

    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxa; j++) {
            dis[i][j] = INT_MAX-100;
        }
    }
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i]++;
    }

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    queue<int> rQ;
    queue<int> cQ;

    rQ.push(r1);
    cQ.push(c1);

    dis[r1][c1] = 0;

    while(!rQ.empty()) {
        int r = rQ.front();
        int c = cQ.front();

        watch(r)
        watch(c)
        cerr << endl;
        
        rQ.pop(); cQ.pop();

        for(pii x: dir) {
            cerr << "could go to " << r+x.fi << "," << min(c+x.se, a[r+x.fi]) << endl;
            watch(ok(r+x.fi, min(c+x.se, a[r+x.fi])))
            if(ok(r+x.fi, min(c+x.se, a[r+x.fi]))) {
                if(dis[r+x.fi][min(c+x.se, a[r+x.fi])] > dis[r][c]+1) {
                    dis[r+x.fi][min(c+x.se, a[r+x.fi])] = dis[r][c]+1;
                    cerr << "pushing" << endl;
                    rQ.push(r+x.fi);
                    cQ.push(min(c+x.se, a[r+x.fi]));
                }
            }
        }
    }

    cout << dis[r2][c2] << endl;
}