// https://codeforces.com/contest/731/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 200500;
set<int> G[maxn];
bool vis[maxn];
int c[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for(int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;

        G[l].emplace(r);
        G[r].emplace(l);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            int sz = 0;
            map<int, int> cnt;

            queue<int> Q;
            Q.push(i);
            vis[i] = true;
            while(!Q.empty()) {
                int S = Q.front(); Q.pop();

                cnt[c[S]]++;
                sz++;
                for(int adj: G[S]) {
                    if(!vis[adj]) {
                        Q.push(adj);
                        vis[adj]= true;
                    }
                }
            }

            int ma = 0;
            for(pii x: cnt) {
                ma = max(ma, x.se);
            }

            ans += sz-ma;
        }
    }

    cout << ans << endl;
}