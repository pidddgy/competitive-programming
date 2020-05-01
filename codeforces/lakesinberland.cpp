// https://codeforces.com/contest/723/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define maxn 60
#define pii pair<int, int>
#define fi first
#define se second
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
pii par[60][60];
bool vis[60][60];
int dis[60][60];
char a[60][60];

map<pii, vector<pair<int, pii>>> G;

vector<pii> dirs = {pii(-1, 0), pii(1, 0), pii(0, 1), pii(0, -1)};
int n, m, k;


pii pre[60][60];

void clearVis() {
    for(int i = 0; i < 60; i++) {
        for(int j = 0; j < 60; j++) {
            vis[i][j] = false;
        }
    }
}
bool vpos(int x, int y) {
    if(1 <= x and x <= n) {
        if(1 <= y and y <= m) {
            return true;
        }
    }

    return false;
}

bool onBorder(int x, int y) {
    return(x == 1 or x == n or y == 1 or y == m);
}

bool comp(set<pii> l, set<pii> r) {
    return l.size() < r.size();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    int numWater = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '.') numWater++;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(onBorder(i, j) and a[i][j] == '.') {
                cerr << "pushing " << i << "," << j << endl;
                queue<int> rQ;
                queue<int> cQ;

                rQ.push(i);
                cQ.push(j);

                while(!rQ.empty()) {
                    int r = rQ.front(); rQ.pop();
                    int c = cQ.front(); cQ.pop();
                    cerr << "on " << r << "," << c << endl;
                    for(pii d: dirs) {
                        if(vpos(r+d.fi, c+d.se) and !vis[i][j] and a[r+d.fi][c+d.se] == '.') {
                            
                            rQ.push(r+d.fi);
                            cQ.push(c+d.se);
                            cerr << "pushign " << r+d.fi << "," << c+d.se << endl;
                            vis[i][j] = true;
                        }
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == '*')
                vis[i][j] = true;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cerr << a[i][j];
        }
        cerr << endl;
    }

     for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cerr << vis[i][j];
        }
        cerr << endl;
    }

    watch(vis[5][1])
    
    vector<set<pii>> comps;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if((!vis[i][j]) and (a[i][j] == '.')) {
                cerr << "starting from " << i << "," << j << endl;
                watch(vis[i][j])
                watch(a[i][j])
                queue<int> rQ;
                queue<int> cQ;


                rQ.push(i);
                cQ.push(j);
                vis[i][j] = true;

                set<pii> S;
                S.emplace(pii(i, j));
                while(!rQ.empty()) {
                    int r = rQ.front(); rQ.pop();
                    int c = cQ.front(); cQ.pop();

                    for(pii d: dirs) {
                        pii to = pii(r+d.fi, c+d.se);
                        if(!vis[to.fi][to.se] and vpos(to.fi, to.se) and a[to.fi][to.se] == '.') {
                            rQ.push(to.fi);
                            cQ.push(to.se);
                            S.emplace(pii(to.fi, to.se));
                            vis[to.fi][to.se] = true;
                        }
                    }
                }

                comps.emplace_back(S);
            }
        }
        cerr << endl;
    }
    int have = 0;
    int lakes = comps.size();
    
    sort(comps.begin(), comps.end(), comp);
    for(set<pii> x: comps) {
        for(pii y: x) {
            cout << y.fi << "," << y.se << endl;
        }
        cout << endl;
        if(lakes > k) {
            for(pii y: x) {
                cerr << y.fi << " " << y.se << endl;
            }
            cerr << endl;
            have += x.size();
            for(pii y: x) {
                a[y.fi][y.se] = '*';
            }
            lakes--;
        }    
        cerr << endl;
    }

    cout << have << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }




}