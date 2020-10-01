// https://codeforces.com/contest/1364/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr

const int maxn = 100500;
int n, m, k;

bool vis[maxn];
set<int> G[maxn];
int par[maxn];
int dvis[maxn];

void reset() {
    for(int i = 0; i < maxn; i++) {
        vis[i] = false;
        par[i] = -1;
        dvis[i] = 0;
    }
}

vector<int> path;

struct Compare {
     bool operator()(vector<int> l, vector<int> r) {
        return l.size()<r.size(); 
    }
};

set<vector<int>, Compare> cycles;
 
void dfs(int v, int par) {
    if(cycles.size() and (*cycles.begin()).size() <= k) return;

    dvis[v] = 1;
    path.push_back(v);

 
    for(int to: G[v]) {
        if(to == par) continue;

        // cerr << "considering " << to << endl;

        if(dvis[to] != 2) {
            if(dvis[to] == 1) {
                vector<int> emp;

                int i = path.size()-1;
    
                while(path[i] != to) {
                    emp.emplace_back(path[i]);
                    i--;
                }
                emp.emplace_back(to);
                cycles.emplace(emp);
            } else {
                dfs(to, v);
            }
        }
    }
    path.pop_back();
    dvis[v] = 2;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt(seed);

    cin >> n >> m >> k;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    for(int r = 1; r <= 10; r++) {
        reset();

        int st = (mt()%n)+1;
        set<int> ans;
        
        queue<int> Q;
        Q.push(st);
        vis[st] = true;
        ans.emplace(st);
    
        while(!Q.empty()) {
            int S = Q.front(); Q.pop();
            bool ok = true;
            for(int x: ans) {
                if(G[S].count(x)) {
                    ok = false;
                }
            }

            if(ok) ans.emplace(S);

            for(int adj: G[S]) {
                if(!vis[adj]) {
                    Q.push(adj);
                    vis[adj] = true;
                }
            }
        }

        if(ans.size() >= (k+1)/2) {
            cout << 1 << endl;
            for(int i = 1; i <= (k+1)/2; i++) {
                cout << *ans.begin() << " ";
                ans.erase(*ans.begin());
            }
            cout << endl;

            exit(0);
        }
    }

    reset();
    
    dfs(1, -1);

    if(cycles.size() and (*cycles.begin()).size() <= k) {
        cout << 2 << endl;
        
        vector<int> ans = *cycles.begin();

        cout << ans.size() << endl;


        for(int x: ans) {
            cout << x << " ";
        }
        cout << endl;
        exit(0);
    }


    assert(false);
}
