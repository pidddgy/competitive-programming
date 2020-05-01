// https://codeforces.com/contest/979/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

const int maxn = 300050;

int n, x, y;
vector<int> G[maxn];

// distance from roots
int rootf[maxn];
int rootb[maxn];
bool vis[maxn];

int dfs(int* arr, int n) {
    int sum = 1;
    for(int adj: G[n]) {
        if(!vis[adj]) {
            vis[adj] = true;
            dfs(arr, adj);
        }
        sum += arr[adj];
    }

    arr[n] = sum;
    return arr[n];
}

void clearVis() {
    for(int i = 0; i < maxn; i++) vis[i] = false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y;
    for(int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;

        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    clearVis();
    vis[x] = true;
    dfs(rootf, x);

    clearVis();
    vis[y] = true;
    dfs(rootb, y);

    int all = n*(n-1);
    int invalid = (rootb[x] * rootf[y]);

    cout << all-invalid << endl;
}