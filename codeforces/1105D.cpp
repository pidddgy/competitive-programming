#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 1005;
const int maxp = 12;

int n, m, p;
int dis[maxp][maxn][maxn];
bool vis[maxn][maxn];
queue<int> rQ[maxp];
bool vis2[maxp][maxn][maxn];
queue<int> cQ[maxp];
int ans[maxp];
int s[maxp];
int take = 0;

vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool ok(int r, int c) {
    if(1 <= r and r <= n) {
        if(1 <= c and c <= m) {
            return true;
        }
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;

    for(int i = 1; i <= p; i++) {
        cin >> s[i];
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                dis[i][j][k] = INT_MAX-300;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            if(s[j-1] != '.') {
                if(s[j-1] != '#') {
                    rQ[s[j-1]-'0'].push(i);
                    cQ[s[j-1]-'0'].push(j);
                    dis[s[j-1]-'0'][i][j] = 0;
                } else {
                    vis[i][j] = true;
                    take++;
                }
            }
        }
    }    

    int cur = 1;
    int co = 0;
    int ree =0;
    int ops = 0;
    while(true) {
        int upto = co*s[cur];
        cerr << "on " << cur << endl;
        watch(upto)
        while(!rQ[cur].empty()) {
            int r = rQ[cur].front();
            int c = cQ[cur].front();

            cerr << r << " " << c << endl;

            if(dis[cur][r][c] > upto) {
                cerr << "break1" << endl;
                break;
            }

            ops++;

            assert(ops <= 2e8);

            rQ[cur].pop();
            cQ[cur].pop();

            if(vis2[cur][r][c]) {
                continue;
            }
            vis2[cur][r][c] = true;
            if(!vis[r][c]) {
                vis[r][c] = true;
            } else {
                cerr << "break" << endl;
                continue;
            }


            ans[cur]++;
            cerr << cur << " takes " << r << " " << c << endl;
            take++;

            if(take == n*m) break;

            for(pii d: dir) {
                // cerr << "considering " << r+d.fi << "," << c+d.se << endl;
                if(ok(r+d.fi, c+d.se) and !vis[r+d.fi][c+d.se] and dis[cur][r+d.fi][c+d.se] > dis[cur][r][c]+1) {
                    // cerr << "pushing " << endl;
                    cerr << "pushing " << r+d.fi << "," << c+d.se << endl;
                    rQ[cur].push(r+d.fi);
                    cQ[cur].push(c+d.se);
                    dis[cur][r+d.fi][c+d.se] = dis[cur][r][c]+1;
                }
            }
        }

        ree++;

        if(ree == p*n*m+60) break;
        cerr << endl;
        cur++;
        if(cur == p+1) {
            cur = 1;
            co++;
        }
        
    }


    for(int i = 1; i <= p; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

multisource bfs

keep track of distance, visited, 

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
