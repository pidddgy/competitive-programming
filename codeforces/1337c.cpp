// https://codeforces.com/contest/1337/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
// #define cerr if(false) cerr
const int maxn = 200500;

int n, k;
vector<int> G[maxn];
bool vis[maxn];
// num in subtree
int amt[maxn];
int dis[maxn];
bool industry[maxn];
bool leaf[maxn];
int dfs(int cur) {
    int sum = 1;
    for(int adj: G[cur]) {
        if(!vis[adj]) {
            vis[adj] = true;
            dfs(adj);
        }

        sum += amt[adj];
    }

    if(sum == 1) leaf[cur] = true;
    amt[cur] = sum;
    return amt[cur];
}

int ans = 0;
void dfs2(int cur, int h) {
    if(!industry[cur]) h++;
    else {
        ans += h;
    }

    for(int adj: G[cur]) {
        if(!vis[adj]) {
            vis[adj] = true;
            dfs2(adj, h);
        }
    }
}

bool comp(int l, int r) {
    int lval = (dis[l])-(amt[l]-1);
    int rval = (dis[r])-(amt[r]-1);

    return lval > rval;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vis[1] = true;
    dfs(1);

    for(int i = 1; i <= n; i++) vis[i] = false;

    queue<int> Q;
    Q.push(1);
    dis[1] = 0;
    vis[1] = true;
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int adj: G[S]) {
            if(!vis[adj]) {
                Q.push(adj);
                vis[adj] = true;
                dis[adj] = dis[S]+1;
            }
        }
    }

    vector<int> amts;
    for(int i = 1; i <= n; i++) {
        amts.emplace_back(i);
    }

    sort(amts.begin(), amts.end(), comp);

    for(int i = 0; i < k; i++) {
        industry[amts[i]] = true;
    }


    for(int i = 1; i <= n; i++) vis[i] = false;
    vis[1] = true;
    dfs2(1, 0);

    cout << ans << endl;
}