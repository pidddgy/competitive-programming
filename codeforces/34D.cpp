// https://codeforces.com/contest/34/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

const int maxn = 50500;

set<int> G[maxn];
bool vis[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, r1, r2;
    cin >> n >> r1 >> r2;

    for(int i = 1; i <= n; i++) {
        if(i == r1) continue;

        int p;
        cin >> p;

        G[i].emplace(p);
        G[p].emplace(i);
    }

    queue<int> Q;
    Q.push(r2);

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        for(int adj: G[S]) {
            if(!vis[adj]) {
                vis[adj] = true;
                Q.push(adj);
                ans[adj] = S;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(i == r2) continue;

        cout << ans[i] << " ";
    }
    cout << endl;


}