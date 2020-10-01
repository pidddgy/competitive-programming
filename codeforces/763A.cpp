// https://codeforces.com/contest/763/problem/A

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100500;

set<int> G[maxn];
vector<pii> edges;
int color[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        edges.emplace_back(u, v);
    }

    set<int> u;
    for(int i = 1; i <= n; i++) {
        cin >> color[i];
        u.emplace(color[i]);
    }
    if(u.size()==1) {
        cout << "YES" << endl << 1 << endl;
        return 0;
    }

    bool first = true;
    set<int> S;
    for(pii e: edges) {
        if(color[e.fi] != color[e.se]) {
            cerr << "considering " << e.fi << "," << e.se << endl;
            if(first) {
                S.emplace(e.fi);
                S.emplace(e.se);
                first = false;
            } else {
                set<int> T = {e.fi, e.se};
                set<int> s = S;
                set<int> inter;
                set_intersection(T.begin(), T.end(),
                s.begin(), s.end(), inserter(inter, inter.begin()));

                S.clear();
                for(int x: inter) {
                    S.emplace(x);
                }
            }
        }

        cerr << "S is " << endl;
        for(int x: S) {
            cerr << x << " ";
        }
        cerr << endl;
    }
    
    if(S.size()) {
        cout << "YES" << endl;
        cout << *S.begin() << endl;
    } else {
        cout << "NO" << endl;
    }
}
