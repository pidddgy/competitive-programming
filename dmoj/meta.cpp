// https://dmoj.ca/problem/meta

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr

const int maxn = 100500;

int N;
set<int> G[maxn];

int dis[maxn], par[maxn];
bool vis[maxn];
int depth[maxn];

void clear() {
    for(int i = 0; i < maxn; i++) {
        dis[i] = INT_MAX-300;
        par[i] = -1;
        vis[i] = false;
    }
}

void dfs(int n) {
    for(int adj: G[n]) {
        if(dis[n]+1 < dis[adj]) {
            dis[adj] = dis[n]+1;
            par[adj] = n;
            dfs(adj);
        }
    }
}

void dfs2(int n) {
    bool leaf = true;
    for(int adj: G[n]) {
        if(!vis[adj]) {
            leaf = false;
            vis[adj] = true;

            dfs2(adj);
            depth[n] = max(depth[n], depth[adj]+1);
        }
    }

    if(leaf) {
        depth[n] = 1;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    clear();
    dis[1] = 0;
    dfs(1);

    for(int i = 1; i <= N; i++) {
        cerr << dis[i] << " ";
    }
    cerr << endl;

    int ma = dis[1], maind = 1;
    for(int i = 2; i <= N; i++) {
        if(dis[i] > ma) {
            ma = dis[i];
            maind = i;
        } 
    }
    int st = maind;

    cerr << "dfsing from " << maind << endl;
    clear();
    dis[maind] = 0;
    dfs(maind);

    for(int i = 1; i <= N; i++) {
        cerr << par[i] << " ";
    }
    cerr << endl;
    
    int cur = 1;
    ma = dis[1];
    for(int i = 2; i <= N; i++) {
        if(dis[i] > ma) {
            ma = dis[i];
            cur = i;
        } 
    }


    
    vector<int> path;
    watch(cur)
    watch(par[cur])
    watch(st)
    while(cur != st) {
        path.push_back(cur);
        cur = par[cur];
        watch(cur)
    }
    path.push_back(cur);

    for(int x: path) {
        cerr << x << " ";
    }
    cerr << endl;
    
    set<int> S;
    if(path.size() == 1) {
        S.emplace(path[0]);
    } else {
        S.emplace(path[path.size()/2]);
        if(path.size()%2==0) {
            S.emplace(path[path.size()/2-1]);
        }
    }

    cerr << "center(s) are: " << endl;
    for(int x: S) {
        cerr << x << " ";
    }
    cerr << endl;


    clear();
    for(int x: S) {
        vis[x] = true;
    }

    for(int x: S) {
        dfs2(x);
    }

    clear();
    queue<int> Q;
    for(int x: S) {
        vis[x] = true;
        Q.push(x);
    }

    while(!Q.empty()) {
        int n = Q.front(); Q.pop();
        cerr << "currently on " << n << endl;

        int ma = 0;
        int macnt = 0;
        for(int adj: G[n]) {
            if(!vis[adj]) {
                cerr << adj << " has depth " << depth[adj] << endl;
                if(depth[adj] > ma) {
                    ma = depth[adj];
                    macnt = 1;
                } else if(depth[adj] == ma) {
                    macnt++;
                }
            }
        }

        watch(ma)
        watch(macnt)
        if(macnt == 1 or (macnt == 2 and S.size() == 1)) {
            for(int adj: G[n]) {
                if(!vis[adj] and depth[adj] == ma) {
                    vis[adj] = true;
                    Q.push(adj);
                    S.emplace(adj);
                }
            }
        }
        cerr << endl;
    }

    cout << S.size() << endl;
}