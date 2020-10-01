// https://codeforces.com/contest/510/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 105;
map<char, set<char>> G;
map<char, bool> vis;
map<char, bool> traversing;
string a[maxn];
string ans;

void dfs(char n, char parent) {
    vis[n] = true;
    traversing[n] = true; 
    for(char adj: G[n]) {
        if((adj != parent and vis[adj] and traversing[adj]) or 
        (G[adj].count(n) and G[n].count(adj))) {
            cout << "Impossible" << endl;
            exit(0);
        }
        if(!vis[adj]) {
            vis[adj] = true;
            dfs(adj, n);
        }
    }

    traversing[n] = false;
    ans += n;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            bool found = false;
            for(int k = 0; k < min(a[i].size(), a[j].size()); k++) {
                if(a[i][k] != a[j][k]) {
                    cerr << "edge from " << a[i][k] << " to " << a[j][k] << endl;
                    found = true;
                    G[a[i][k]].emplace(a[j][k]);
                    break;
                }
            }
            if(!found) {
                if(a[i].size() > a[j].size()) {
                    cout << "Impossible" << endl;
                    exit(0);
                }
            }
        }
    }

    for(char x: string("abcdefghijklmnopqrstuvwxyz")) {
        if(!vis[x]) {
            dfs(x, '?');
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}
