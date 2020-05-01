// https://codeforces.com/contest/1098/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define int long long
#define cerr if(false) cerr
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 100500;

int par[maxn];
vector<int> G[maxn];
int s[maxn];
bool vis[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        int _;
        cin >> _;

        G[i].emplace_back(_);
        G[_].emplace_back(i);
    }

    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    par[1] = -1;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        set<int> children;
        set<int> desc;
        for(int adj: G[S]) {            
            if(!vis[adj]) {
                children.emplace(s[adj]);
                desc.emplace(adj);
                Q.push(adj);
                par[adj] = S;
                vis[adj] = true;
            }
        }

        if(S != 1 and s[S] == -1) {
            cerr << "on " << S << endl;
            cerr << "is now " << s[par[S]] << endl;
            s[S] = s[par[S]];
        }

        if(S != 1 and desc.size() >= 2) {
            if(children.lower_bound(0) != children.end())
                s[S] = *children.lower_bound(0);
        }
        // if(children.size() == 0) {
        //     s[S] = s[par[S]];
        //     continue;
        // }

        // if(s[S] == -1) {
        //     if((children.size() >= 2) || 
        //     (children.size() == 1 and *children.begin() == -1) || 
        //     (s[*desc.begin()] - s[par[S]] < 0)) {
        //         cerr << "failed on " << S << endl;
        //         watch((children.size() >= 2))
        //         watch(s[*desc.begin()])
        //         watch(s[par[S]])
        //         watch((s[*desc.begin()] - s[par[S]]) < 0)

        //         cerr << endl;
        //         cout << -1 << endl;
        //         return 0;
        //     }

        //     s[S] = s[*desc.begin()]+1;
        // }
    }

    for(int i = 1; i <= n; i++) {
        cerr << s[i] << " ";
    }
    cerr << endl;

    int ans = s[1];
    for(int i = 2; i <= n; i++) {
        cerr << i << " - " << s[i] << " " << s[par[i]] << endl;
        ans += s[i]-s[par[i]];
        watch(s[i])
        if((s[i] - s[par[i]]) < 0) {
            cerr << "failed on " << i << endl;
            watch(s[i])
            watch(s[par[i]])
            watch(s[i] - s[par[i]])
            cout << -1 << endl;
            return 0;
        }
    }
    cerr << endl;

    cout << ans << endl;

}