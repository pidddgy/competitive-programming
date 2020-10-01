// https://codeforces.com/contest/1209/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define pipii pair<int, pii>

const int maxn = 100500;

bool used[maxn];
bool vis[maxn];

map<int, queue<pipii>> G;
vector<pipii> guests;

queue<pipii> Q;
int sad = 0;

void dfs(pipii S) {
    if(used[S.se.fi] and used[S.se.se]) {
        sad++;
    }

    used[S.se.fi] = true;
    used[S.se.se] = true;

    while(G[S.se.fi].size()) {
        pipii adj = G[S.se.fi].front(); G[S.se.fi].pop();
        if(!vis[adj.fi]) {
            vis[adj.fi] = true;
            dfs(adj);
        }
    }

    while(G[S.se.se].size()) {
        pipii adj = G[S.se.se].front(); G[S.se.se].pop();
        if(!vis[adj.fi]) {
            vis[adj.fi] = true;
            dfs(adj);
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;

        if(x > y) swap(x, y);

        pipii g = pipii(i, pii(x, y));
        guests.emplace_back(g);
        G[x].emplace(g);
        G[y].emplace(g);
    }

    for(pipii st: guests) {
        if(!vis[st.fi]) {
            vis[st.fi] = true;
            dfs(st);

        }
    }

    cout << sad << endl;
}