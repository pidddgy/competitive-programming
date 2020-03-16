// https://codeforces.com/contest/445/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define int long long
    int n, m;
    cin >> n >> m;

    vector<int> G[n+1];
    bool vis[n+1];

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }

    int ans = 1;

    for(int i = 1; i <= n; i++) {
        vis[i] = false;
    }

    int po = n;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) po--;

        queue<int> Q;
        Q.push(i);
        vis[i] = true;

        while(!Q.empty()) {
            int S = Q.front(); Q.pop();

            for(int x: G[S]) {
                if(!vis[x]) {
                    Q.push(x);
                    vis[x] = true;
                }
            }

        }
    }

    cout << fixed << setprecision(0) << pow(2, po) << endl;

}