// https://codeforces.com/contest/1056/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;

const int maxn = (1e5)+500;

int have[maxn];
bool vis[maxn];
vector<int> G[maxn];

int dfs(int cur) {
    vis[cur] = true;
    watch(cur)

    int h = 0;
    for(int adj: G[cur]) {
        if(!vis[adj]) {
            h += dfs(adj);
        }
    }

    if(h == 0) h = 1;

    have[cur] = h;
    watch(have[cur])
    return h;
}
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;

        G[i].emplace_back(p);
        G[p].emplace_back(i);
    }

    dfs(1);

    for(int i = 1; i <= n; i++) {
        cerr << have[i] << " ";
    }
    cerr << endl;

    sort(have+1, have+n+1);

    int ma = 0;
    for(int i = 1; i <= n; i++) {
        ma = max(ma, have[i]);

        cout << ma << " ";
    }
    cout << endl;
}