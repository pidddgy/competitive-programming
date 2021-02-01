#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
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

const int maxn = 300;
const vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n;

bool ok(int r, int c) {
    if(1 <= r and r <= n) {
        if(1 <= c and c <= n) {
            return true;
        }
    }

    return false;
}

int disj[2*maxn*maxn];
int car[2*maxn*maxn];

int findp(int v) {
    if(disj[v] == v) return v;
    else return disj[v] = findp(disj[v]);
}

void merge(int a, int b) {
    int c = findp(a);
    int d = findp(b);

    if(c == d) return;

    disj[c] = d;
    car[d] += car[c];
}

int a[maxn][maxn];

map< pii, map<int, vector<int>> > G;
int vis[maxn][maxn];
int id[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("multimoo.in", "r", stdin); 
    freopen("multimoo.out", "w", stdout);

    cin >> n;

    set<int> S;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            id[i][j] = (i-1)*n+j;
            cin >> a[i][j];
            disj[id[i][j]] = id[i][j];
            car[id[i][j]] = 1;
        }
    }


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(pii d: dir) {
                if(!ok(i+d.fi, j+d.se)) continue;
                if(a[i][j] == a[i+d.fi][j+d.se]) {
                    merge(id[i][j], id[i+d.fi][j+d.se]);
                }
            }
        }
    }

    int ans1 =0;
    for(int i = 0; i < 2*maxn*maxn; i++) ans1 = max(ans1, car[i]);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(pii d: dir) {
                if(!ok(i+d.fi, j+d.se)) continue;
                if(a[i][j] != a[i+d.fi][j+d.se]) {
                    G[pii(min(a[i][j], a[i+d.fi][j+d.se]), max(a[i][j], a[i+d.fi][j+d.se]))][findp(id[i][j])].emplace_back(findp(id[i+d.fi][j+d.se]));
                    G[pii(min(a[i][j], a[i+d.fi][j+d.se]), max(a[i][j], a[i+d.fi][j+d.se]))][findp(id[i+d.fi][j+d.se])].emplace_back(findp(id[i][j]));
                }
            }
        }
    }

    int ans2 = 0;
    for(auto g: G) {
        map<int, int> vis;

        for(auto e: g.se) {
            if(!vis[e.fi]) {
                int loc = 0;
                queue<int> Q;
                Q.push(e.fi);
                vis[e.fi] = true;

                while(!Q.empty()) {
                    int S = Q.front(); Q.pop();
                    loc += car[S];
                    for(int to: g.se[S]) {
                        if(!vis[to]) {
                            vis[to] = true;
                            Q.push(to);
                        }
                    }
                }

                ans2 = max(ans2, loc);
            }
        }
    }

    cout << ans1 << endl;
    cout << ans2 << endl;
}

/*
3 906 250 000

imagine graph
there are at most 6e4 nodes each with their own colour

bfs with only 2 ids allowed






*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
