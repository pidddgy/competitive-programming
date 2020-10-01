// https://atcoder.jp/contests/abc142/tasks/abc142_f

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1500;
vector<int> path;
vector<pii> edges;
vector<vector<int>> cycles;
set<int> G[maxn];
int vis[maxn];
int N, M;

void dfs(int v) {
    // cerr << "currently on " << v << endl;
    vis[v] = 1;
    path.push_back(v);

    for(int to: G[v]) {
        if(vis[to] != 2) {
            if(vis[to] == 1) {
                // cerr << "hit cycle, back edge going to " << to << endl;
                cycles.emplace_back(vector<int>());
                int i = path.size()-1;
    
                while(path[i] != to) {
                    cycles.back().emplace_back(path[i]);
                    i--;
                }
                cycles.back().emplace_back(to);
            } else {
                dfs(to);
            }
        }
    }

    path.pop_back();
    vis[v] = 2;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        G[a].emplace(b);
        edges.emplace_back(a, b);
    }

    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    // for(auto c: cycles) {
    //     for(int x: c) {
    //         cerr << x << " ";
    //     }
    //     cerr << endl;
    // }
    
    for(vector<int> c: cycles) {
        set<int> S;
        map<int, int> indeg, outdeg;

        for(int x: c) {
            S.emplace(x);
        }

        for(pii e: edges) {
            if(S.count(e.fi) and S.count(e.se)) {
                outdeg[e.fi]++;
                indeg[e.se]++;
            }
        }

        bool ok = true;
        for(int x: c) {
            if(!(outdeg[x] == 1 and indeg[x] == 1)) {
                ok = false;
            }
        }

        if(ok) {
            cout << c.size() << endl;
            for(int x: c) {
                cout << x << endl;
            }
            exit(0);
        }
    }

    cout << -1 << endl;
}
