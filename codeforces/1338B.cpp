// https://codeforces.com/contest/1338/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 


const int maxn = 100500;

int n;
set<int> G[maxn];
int dis[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        dis[i] = INT_MAX-500;
    }

    cin >> n;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    set<int> leaves;
    for(int i = 1; i <= n; i++) {
        if(G[i].size() == 1) {
            leaves.emplace(i);
        }
    }

    queue<int> Q;
    Q.push(1);
    dis[1] = 0;
    
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int adj: G[S]) {
            if(dis[adj] > dis[S]+1) {
                Q.push(adj);
                dis[adj] = dis[S]+1;
            }
        }
    }

    set<int> parities;

    for(int l: leaves) {
        parities.emplace(dis[l]%2);
    }

    if(parities.size() == 1) {
        cout << 1 << " ";
    } else {
        cout << 3 << " ";
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        bool ok = false;
        if(G[i].size() > 1) {
            for(int adj: G[i]) {
                if(leaves.count(adj)) ok = true;
            }
        }

        cnt += ok;
    }
    
    cout << n-1-leaves.size()+cnt << endl;
}