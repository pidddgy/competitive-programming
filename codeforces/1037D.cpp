// https://codeforces.com/contest/1037/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 200500;

int n;
int a[maxn];
int ind[maxn];
bool vis[maxn];

struct Compare {
    bool operator()(int l, int r) {
        return ind[l] < ind[r];
    }
};

set<int, Compare> G[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<pii> edges;
    for(int i = 1; i <= n-1; i++) {
        int x, y;
        cin >> x >> y;

        edges.emplace_back(x, y);
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }

    for(pii x: edges) {
        G[x.fi].emplace(x.se);
        G[x.se].emplace(x.fi);
    }

    queue<int> Q;
    Q.push(1);
    vis[1] = true;

    int cur = 1;
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        if(a[cur] != S) {
            cout << "No" << endl;
            return 0;
        }
        cur++;
        for(int adj: G[S]) {
            if(!vis[adj]) {
                Q.push(adj);
                vis[adj] = true;
            }
        }
    }

    cout << "Yes" << endl;
}