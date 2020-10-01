// https://codeforces.com/contest/500/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
const int maxn = 350;

int p[maxn];
set<int> G[maxn];
bool vis[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        s = "."+s;

        for(int j = 1; j < s.size(); j++) {
            if(s[j] == '1') {
                G[i].emplace(j);
                G[j].emplace(i);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            watch(i)
            queue<int> Q;
            vis[i] = true;
            Q.push(i);

            vector<int> inds;
            while(!Q.empty()) {
                int S = Q.front(); Q.pop();
                inds.emplace_back(S);

                for(int adj: G[S]) {
                    if(!vis[adj]) {
                        Q.push(adj);
                        vis[adj] = true;
                    }
                }
            }

            vector<int> vals;
            for(int x: inds) {
                watch(x)
                vals.emplace_back(p[x]);
            }

            sort(inds.begin(), inds.end());
            sort(vals.begin(), vals.end());

            for(int i = 0; i < inds.size(); i++) {
                ans[inds[i]] = vals[i];   
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


}