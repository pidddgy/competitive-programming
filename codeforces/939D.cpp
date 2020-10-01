// https://codeforces.com/contest/939/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pchr pair<char, char>
#define fi first
#define se second

map<char, set<char>> G;
map<char, bool> vis;
map<char, bool> vis2;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    s = "."+s;
    t = "."+t;

    for(int i = 1; i <= n; i++) {
        if(s[i] != t[i]) {
            G[s[i]].emplace(t[i]);
            G[t[i]].emplace(s[i]);
        }
    }

    vector<pchr> ans;
    for(char x: string("abcdefghijklmnopqrstuvwxyz")) {
        if(!vis[x]) {
            char machr = '?';

            queue<int> Q;
            Q.push(x);
            vis[x] = true;

            while(!Q.empty()) {
                char S = Q.front(); Q.pop();

                if(G[S].size() > G[machr].size()) {
                    machr = S;
                }
                for(char adj: G[S]) {
                    if(!vis[adj]) {
                        vis[adj] = true;
                        Q.push(adj);
                        ans.emplace_back(S, adj);
                    }
                }
            }
        }
    }

    cout << ans.size() << endl;
    for(auto x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}
