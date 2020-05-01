// https://codeforces.com/contest/1337/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int x, n, m;
        cin >> x >> n >> m;

        for(int i = 1; i <= n; i++) {
            if(((x/2)+10) < x) {
                x /= 2;
                x += 10;
            }
        }

        for(int i = 1; i <= m; i++) {
            x -= 10;
        }

        if(x <= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
/*
    queue<int> Q;
    Q.push(1);
    amt[1] = 0;
    vis[1] = true;
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int adj: G[S]) {
            if(!vis[adj]) {
                Q.push(adj);
                vis[adj] = true;
                amt[adj] = amt[S]+1;
            }
        }
    }
    */