// https://codeforces.com/contest/131/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 3500;
const int INF = INT_MAX-100;

int dis[maxn];
bool vis[maxn];
set<int> G[maxn];


void clearvis() {
    for(int i = 0; i < maxn; i++) {
        vis[i] = false;
    }
}

void dfs(int node, int par) {
    for(int adj: G[node]) {
        if(!vis[adj] and adj != par) {
            vis[adj] = true;
            dfs(adj, node);
        }
    }
}

void dfs2(int node) {
    for(int adj: G[node]) {
        // poss tle
        if(dis[adj] >= dis[node]+1) {
            dis[adj] = dis[node]+1;
            dfs2(adj);
        }
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < maxn; i++) {
        dis[i] = INF;
    }

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }  

    for(int i = 1; i <= n; i++) {
        clearvis();
        dfs(i, -1);
        if(vis[i]) {
            dis[i] = 0;
            dfs2(i);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
}