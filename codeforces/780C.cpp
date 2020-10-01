// https://codeforces.com/contest/780/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 200500;

set<int> G[maxn];
set<int> colors[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) ans[i] = -1;

    int n;
    cin >> n;

    int st = 1;
    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v); 
        G[v].emplace(u);

        for(int x: set<int>({u, v})) {
            if(G[x].size() > G[st].size()) {
                st = x;
            }
        }
    } 


    queue<int> Q;
    ans[st] = 1;
    Q.push(st);
    colors[st].emplace(1);

    while(!Q.empty()) {
        int S =  Q.front(); Q.pop();
        watch(S)
        colors[S].emplace(ans[S]);
        int cur = 1;
        for(int adj: G[S]) {
            if(ans[adj] == -1) {
                while(colors[S].count(cur)) {
                    cerr << cur << " is in colors, increasing" << endl;
                    cur++;
                }

                ans[adj] = cur;
                cerr << "setting " << adj << " to " << cur << endl;
                colors[adj].emplace(ans[S]);
                colors[S].emplace(cur);
                Q.push(adj);
            }
        }
    }

    cout << G[st].size()+1 << endl;

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
