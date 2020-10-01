// https://codeforces.com/contest/1176/problem/E

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
const int maxn = 200500;
const int INF = INT_MAX-100;

int n, m;
set<int> G[maxn];
int dis[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < maxn; i++) {
        dis[i] = INF;
    }
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        int maind = 1;
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;

            G[u].emplace(v);
            G[v].emplace(u);

            for(int x: set<int>({u, v})) {
                if(G[x].size() > G[maind].size()) {
                    maind = x;
                }
            }
        }

        queue<int> Q;
        Q.push(maind);
        dis[maind] = 0;

        while(!Q.empty()) {
            int S = Q.front(); Q.pop();

            for(int adj: G[S]) {
                if(dis[adj] > dis[S]+1) {
                    Q.push(adj);
                    dis[adj] = dis[S]+1;
                }
            }
        }

        int even = 0;
        for(int i = 1; i <= n; i++) {
            if(dis[i]%2==0) {
                even++;
            }
        }
        

        set<int> ans;
        for(int i = 1; i <= n; i++) {
            if(even <= n/2) {
                if(dis[i] % 2 == 0) {
                    ans.emplace(i);
                } 
            } else {
                if(dis[i]%2==1) {
                    ans.emplace(i);
                }
            }
        }

        cout << ans.size() << endl;
        for(int x: ans) cout << x << " ";
        cout << endl;

        for(int i = 1; i <= n; i++) {
            dis[i] = INF;
            G[i].clear();
        }
    }
}