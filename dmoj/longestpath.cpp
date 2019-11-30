// https://dmoj.ca/problem/dpg

#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
vector<int> adj[MAXN];
int longest[MAXN];
bool vis[MAXN];

int dfs(int cur) {
    vis[cur] = true;
    int ret = 0;
    for(int to: adj[cur]) {
        if(vis[to])
            ret = max(ret, 1+longest[to]);
        else
            ret = max(ret, 1+dfs(to));
    }

    longest[cur] = ret;
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].emplace_back(y);
    }

    for(int i = 1; i <= N; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    int ans = longest[1];
    for(int i = 1; i <= N; i++) {
        ans = max(ans, longest[i]);
    }

    cout << ans << endl;
}