// https://codeforces.com/contest/1307/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 200500;
int n, m, k;
vector<int> G[maxn];

int dis1[maxn], disn[maxn], s[maxn];

struct Compare {
    bool operator()(int l, int r) {
        return (dis1[l]-disn[l]) < (dis1[r]-disn[r]);
    }
};

void bfs(int arr[], int st) {
    for(int i = 1; i <= n; i++) {
        arr[i] = INT_MAX-200;
    }

    queue<int> Q;
    Q.push(st);
    arr[st] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
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

    cin >> n >> m >> k;

    for(int i = 1; i <= k; i++) {
        cin >> s[i];
    }

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    bfs(dis1, 1);

    // for(int i = 1; i <= n; i++) {
    //     cerr << dis1[i] << " ";
    // }
    // cerr << endl;

    bfs(disn, n);

    sort(s+1, s+k+1, Compare());

    int best = 0;
    int maxa = INT_MIN;

    // a = any previous node
    // b = i (current node considering)
    for(int i = 1; i <= k; i++) {
        best = max(best, maxa+disn[s[i]]+1);
        maxa = max(maxa, dis1[s[i]]);
    }

    cout << min(dis1[n], best) << endl;
}
