// https://codeforces.com/contest/690/problem/C2

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
const int maxn = 100500;

int n, m;
vector<int> G[maxn];
int dis[maxn];
int dis2[maxn];

void bfs(int *arr, int st) {
    queue<int> Q;

    Q.push(st);
    arr[st] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        cerr << "on " << S << endl;
        for(int adj: G[S]) {
            if(arr[adj] > arr[S]+1) {
                arr[adj] = arr[S]+1;
                Q.push(adj);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        dis[i] = INT_MAX;
        dis2[i] = INT_MAX;
    }

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    bfs(dis, 1);

    int ma = 0;
    int maiind = -1;
    for(int i = 1; i <= n; i++) {
        if(dis[i] > ma) {
            ma = dis[i];
            maiind = i;
        }
    }

    for(int i = 1; i <= n; i++) {
        cerr << dis[i] << " ";
    }
    cerr << endl;


    bfs(dis2, maiind);

    for(int i = 1; i <= n; i++) {
        cerr << dis2[i] << " ";
    }
    cerr << endl;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dis2[i]);
    }
    
    cout << ans << endl;
}
