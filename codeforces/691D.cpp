// https://codeforces.com/contest/691/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 1000500;
int n, m;

int a[maxn], ans[maxn];
set<int> G[maxn];
bool vis[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            vector<int> inds;
            vector<int> elems;
            queue<int> Q;
            Q.push(i);
            vis[i] = true;

            while(!Q.empty()) {
                int S = Q.front(); Q.pop();

                inds.emplace_back(S);
                elems.emplace_back(a[S]);
                
                for(int adj: G[S]) {
                    if(!vis[adj]) {
                        vis[adj] = true;
                        Q.push(adj);
                    }
                }
            }

            sort(inds.begin(), inds.end());
            sort(elems.begin(), elems.end(), greater<int>());

            for(int i = 0; i < inds.size(); i++) {
                ans[inds[i]] = elems[i];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
